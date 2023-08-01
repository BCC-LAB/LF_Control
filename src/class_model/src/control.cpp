#include"class_model/control.h"

ControlClass::ControlClass() : node_handle_("~"){
	
	std::string ros_namespace;
	if (!node_handle_.hasParam("namespace"))
	{
	}else{
		node_handle_.getParam("namespace", ros_namespace);
	}
    arming_client=node_handle_.serviceClient<mavros_msgs::CommandBool>(ros_namespace+"/mavros/cmd/arming");
    takeoff_client=node_handle_.serviceClient<mavros_msgs::CommandTOL>(ros_namespace+"/mavros/cmd/takeoff");
    state_sub = node_handle_.subscribe<mavros_msgs::State>(ros_namespace+"/mavros/state", 10, &ControlClass::state_cb,this);
}

ControlClass::~ControlClass() { ros::shutdown(); }


void ControlClass::state_cb(const mavros_msgs::State::ConstPtr& msg){

    current_state_g = *msg;
    
}

int ControlClass::arm() {
	
	ROS_INFO("Arming drone");
	mavros_msgs::CommandBool arm_request;
	arm_request.request.value = true;
	while (!current_state_g.armed && !arm_request.response.success && ros::ok())
	{
		ros::Duration(.1).sleep();
		arming_client.call(arm_request);
	}
	if(arm_request.response.success)
	{
		ROS_INFO("Arming Successful");	
		return 0;
	}else{
		ROS_INFO("Arming failed with %d", arm_request.response.success);
		return -1;	
	}

}

int ControlClass::takeoff(float takeoff_alt) {
	
	mavros_msgs::CommandTOL srv_takeoff;
	srv_takeoff.request.altitude = takeoff_alt;
	if(takeoff_client.call(srv_takeoff)){
		sleep(3);
		ROS_INFO("takeoff sent %d", srv_takeoff.response.success);
	}else{
		ROS_ERROR("Failed Takeoff");
		return -2;
	}
	sleep(2);
	return 0;

}