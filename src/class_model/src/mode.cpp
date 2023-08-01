#include"class_model/mode.h"

ModeClass::ModeClass() : node_handle_("~"){

	std::string ros_namespace;
	if (!node_handle_.hasParam("namespace"))
	{
		ROS_INFO("using default namespace");
	}else{
		node_handle_.getParam("namespace", ros_namespace);
		ROS_INFO("using namespace %s", ros_namespace.c_str());
	}
  
  set_mode_client=node_handle_.serviceClient<mavros_msgs::SetMode>(ros_namespace+"/mavros/set_mode");

}

ModeClass::~ModeClass() { ros::shutdown(); }

int ModeClass::set_Mode(std::string mode) {
	
	mavros_msgs::SetMode srv_setMode;
  srv_setMode.request.base_mode = 0;
  srv_setMode.request.custom_mode = mode.c_str();
  if(set_mode_client.call(srv_setMode)){
    // ROS_INFO("setmode %s ok",mode.c_str());
    return 0;
    }else{
      ROS_ERROR("Failed SetMode %s,retry...",mode.c_str());
      set_Mode(mode);
      return 0;
    }

}