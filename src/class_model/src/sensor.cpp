#include <class_model/sensor.h>

global_location position; 
float heading;


ThreadGPSClass::ThreadGPSClass() : node_handle_("~"){

    std::string ros_namespace;
    if (!node_handle_.hasParam("namespace"))
	{
	}else{
		node_handle_.getParam("namespace", ros_namespace);
	}

    gps_sub = node_handle_.subscribe(ros_namespace+"/mavros/global_position/global", 10,
                                   &ThreadGPSClass::GPS_callback, this);
    compass_sub = node_handle_.subscribe(ros_namespace+"/mavros/global_position/compass_hdg", 10,
                                   &ThreadGPSClass::Compass_callback, this);

}

ThreadGPSClass::~ThreadGPSClass() { ros::shutdown(); }

void ThreadGPSClass::GPS_callback(const sensor_msgs::NavSatFix::ConstPtr &gps) {
	
    position.lat=gps->latitude;   
	position.lon=gps->longitude;
    position.alt=gps->altitude;
    // ROS_INFO("GPS [%f,%f]", position.lat, position.lon);
}

void ThreadGPSClass::Compass_callback(const std_msgs::Float64::ConstPtr &degree){
    heading = degree->data;
}

global_location ThreadGPSClass::gps_position(){
    // ROS_INFO("GPS [%f,%f]", position.lat, position.lon);
    return position; 
}

float ThreadGPSClass::get_heading(){

    return heading; 
}