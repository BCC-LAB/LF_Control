#include "class_model/command.h"

CommandClass::CommandClass() : node_handle_("~"){

	std::string ros_namespace;
	if (!node_handle_.hasParam("namespace"))
	{
	}else{
		node_handle_.getParam("namespace", ros_namespace);
	}

    velocity_command=node_handle_.advertise<geometry_msgs::TwistStamped>(ros_namespace+"/mavros/setpoint_velocity/cmd_vel",10);
    // gps_command=node_handle_.advertise<geographic_msgs::GeoPoseStamped>(ros_namespace+"/mavros/setpoint_position/global",10);
    gps_command=node_handle_.advertise<mavros_msgs::GlobalPositionTarget>(ros_namespace+"/mavros/setpoint_raw/global",10);

}

CommandClass::~CommandClass() { ros::shutdown(); }

void CommandClass::velocity_init(){

    msg.twist.linear.x = 0;
	msg.twist.angular.x = 0;
	msg.twist.linear.y = 0;
	msg.twist.angular.y = 0;
	msg.twist.linear.z = 0;
	msg.twist.angular.z = 0;

    velocity_command.publish(msg);

	double begin = ros::Time::now().toSec();
	while(true){
		velocity_command.publish(msg);
		double now = ros::Time::now().toSec();
		if((now-begin)>0.01){
			break;
	}

    // uint64_t last_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	// while(true){
	// 	velocity_command.publish(msg);
	// 	uint64_t now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	// 	if((now_ms-last_ms)>10){
	// 		break;
	// }
	}

}

void CommandClass::fix_velocity(float x,float y,float alt,float yaw,float second){

    msg.twist.linear.x = x;
    msg.twist.angular.x = x;
    msg.twist.linear.y = y;
    msg.twist.angular.y = y;
    msg.twist.linear.z = alt;
    msg.twist.angular.z = yaw;
    // ROS_INFO("set_velocity: x:%f, y:%f, alt:%f, yaw:%f",x,y,alt,yaw);
	pre_location=gps_object.gps_position();
	ROS_INFO("%f,%f",pre_location.lat,pre_location.lon);

    //uint64_t last_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	int flag = 0;
	
	double begin = ros::Time::now().toSec();
	while(true){
		velocity_command.publish(msg);
		double now = ros::Time::now().toSec();
		if((now-begin)>second){
			//ROS_INFO("%ld",now-begin);
			velocity_init();
			flag=1;
			ROS_INFO("fin");
			break;
	}
	
	// while(true){
	// velocity_command.publish(msg);

	// uint64_t now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	// if((now_ms-last_ms)>second*1000){
	// 	// ROS_INFO("%ld",now_ms-last_ms);
	// 	velocity_init();
	// 	flag=1;
	// 	ROS_INFO("fin");
	// 	break;
	// }
	}

	while(flag==1){
		sleep(1);
		if(fix_position(pre_location,x,y,second)!=0){
			ROS_INFO("position_fixed");
			break;
		}

	}

}

void CommandClass::set_global_position(double lon,double lat,float alt,float yaw){
    
    mavros_msgs::GlobalPositionTarget goal_position;
	goal_position.coordinate_frame = mavros_msgs::GlobalPositionTarget::FRAME_GLOBAL_REL_ALT;
	goal_position.type_mask =  mavros_msgs::GlobalPositionTarget::IGNORE_VX |
                              mavros_msgs::GlobalPositionTarget::IGNORE_VY |
                              mavros_msgs::GlobalPositionTarget::IGNORE_VZ |
                              mavros_msgs::GlobalPositionTarget::IGNORE_AFX |
                              mavros_msgs::GlobalPositionTarget::IGNORE_AFY |
                              mavros_msgs::GlobalPositionTarget::IGNORE_AFZ |
                              mavros_msgs::GlobalPositionTarget::FORCE |
                              mavros_msgs::GlobalPositionTarget::IGNORE_YAW_RATE;
    goal_position.latitude = lat;
    goal_position.longitude = lon;
    goal_position.altitude = alt;
	goal_position.yaw = yaw;
	// goal_position.header.frame_id = "map";
	// goal_position.type_mask = 65535;


	// geographic_msgs::GeoPoseStamped goal_position;
    // goal_position.header.frame_id = "map";
    // goal_position.pose.position.latitude = lat;
    // goal_position.pose.position.longitude = lon;
    // goal_position.pose.position.altitude = 67;

	ROS_INFO("%f,%f",lat,lon);
	double begin = ros::Time::now().toSec();
	while(true){
		gps_command.publish(goal_position);
		double now = ros::Time::now().toSec();
		if((now-begin)>0.5){
			break;
	}
	}

}

int CommandClass::fix_position(global_location pre_location,float x,float y,float s){

	current_location=gps_object.gps_position();
	float offset_lon=((pre_location.lon-100)*1e+5)+(x*s)-((current_location.lon-100)*1e+5);
	float offset_lat=(pre_location.lat*1e+5)+(y*s)-(current_location.lat*1e+5);
	// ROS_INFO("pre(%f,%f)",(pre_location.lon-100)*1e+5,(pre_location.lat*1e+5));
	// ROS_INFO("cur(%f,%f)",((current_location.lon-100)*1e+5),(current_location.lat*1e+5));
	ROS_INFO("of_lon:%f,of_lat:%f",offset_lon,offset_lat);
	if(offset_lon>1 || offset_lat>1 || offset_lon<-1 || offset_lat<-1){
		fix_velocity(offset_lon/10,offset_lat/10,0,0,1);
		// sleep(1);
		return 0;
	}
	else{
		return 1;
	}
}
void CommandClass::set_velocity(float x,float y,float alt,float yaw,float second){

    msg.twist.linear.x = x;
    msg.twist.angular.x = x;
    msg.twist.linear.y = y;
    msg.twist.angular.y = y;
    msg.twist.linear.z = alt;
    msg.twist.angular.z = yaw;
    // ROS_INFO("set_velocity: x:%f, y:%f, alt:%f, yaw:%f",x,y,alt,yaw);
	// global_location pre_location=gps_object.gps_position();
	
	double begin = ros::Time::now().toSec();
	while(true){
		velocity_command.publish(msg);
		double now = ros::Time::now().toSec();
		if((now-begin)>second){
			velocity_init();
			break;
	}


    // uint64_t last_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

	// while(true){
	// velocity_command.publish(msg);
	// uint64_t now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	// if((now_ms-last_ms)>second*1000){
	// 	// ROS_INFO("%ld",now_ms-last_ms);
	// 	//velocity_init();
	// 	break;
	// }
	}
}

void CommandClass::set_target_position(float x ,float y ){

	origin_location = gps_object.gps_position();
	target_location.lon = (origin_location.lon*1e+5)+x;
	target_location.lat = (origin_location.lat*1e+5)+y;
	float PID[]={0.25,0.1,0};

	while(true){

		current_location = gps_object.gps_position();
		errorX = (current_location.lon-origin_location.lon)*1e+5;
		errorY = (current_location.lat-origin_location.lat)*1e+5;

		lon_speed = clip(PID[0]*x + PID[1]*(x-errorX),1.5,-1.5);
		lat_speed = clip(PID[0]*y + PID[1]*(y-errorY),1.5,-1.5);
		ROS_INFO("%f,%f",lon_speed,lat_speed);


		if(sqrt(pow(errorX,2)+pow(errorY,2)) < (sqrt(x*x+y*y)-0.5)){
			fix_velocity(lon_speed,lat_speed,0,0,0.2);
		}
		else if(fix_position(origin_location,x,y,1) != 0){
			break;
		}
	}

}

float CommandClass::clip(float speed,float max_speed,float min_speed){

	if (speed > 0){
		if(speed > max_speed){
			speed = max_speed;
		}
		// if(speed < 0.5){
		// 	speed = 0.5;
		// }
		return speed;
	}
	else if(speed < 0){
		if(speed < min_speed){
			speed = min_speed;
		}
		// if(speed > -0.5){
		// 	speed = -0.5;
		// }
		return speed;
	}
	else{
		return speed;
	}

}