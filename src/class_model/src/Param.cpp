#include"class_model/Param.h"

ParamClass::ParamClass() : node_handle_("~"){


}

ParamClass::~ParamClass() { ros::shutdown(); }

int ParamClass::getID() {
	
    int ParamData;
	if (!node_handle_.hasParam("droneID"))
	{
		ROS_INFO("No Param Named droneID");
        return 0;
	}else{
		node_handle_.getParam("droneID", ParamData);
		// ROS_INFO("Drone ID %d", ParamData);
        return ParamData;
	}

}

int ParamClass::getParam(std::string ParamName) {
	
    int ParamData;
	if (!node_handle_.hasParam(ParamName))
	{
		ROS_INFO("No Param Named %s" , ParamName);
        return 0;
	}else{
		node_handle_.getParam(ParamName, ParamData);
		// ROS_INFO("Drone ID %d", ParamData);
        return ParamData;
	}

}

int ParamClass::setParam(std::string ParamName , int value){
		
	if (!node_handle_.hasParam(ParamName))
	{
		ROS_INFO("No Param Named %s" , ParamName);
        
	}else{
		node_handle_.setParam(ParamName,value);
		
        return 0;
	}
}