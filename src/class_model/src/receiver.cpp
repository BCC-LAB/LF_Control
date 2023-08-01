#include"class_model/receiver.h"

ReceiverClass::ReceiverClass() : node_handle_("~"){
	
    std::string ros_namespace;
	if (!node_handle_.hasParam("namespace"))
	{
	}else{
		node_handle_.getParam("namespace", ros_namespace);
	}
    mqtt_sub = node_handle_.subscribe(ros_namespace+"/cmd_receiver",10,&ReceiverClass::cmd_receiver, this);
}

ReceiverClass::~ReceiverClass() { ros::shutdown(); }

void ReceiverClass::cmd_receiver(const class_model::receiverCMD::ConstPtr &msg){

    mqtt_command="";
    mqtt_command.append(msg->cmd);
    if(msg->cmd == "land"){
        mode_object.set_Mode("LAND");
    }
    // std::cout<< "type:" << msg->data << std::endl;
}

std::string ReceiverClass::check_command(){
    // ROS_INFO("sd:%s",mqtt_command);
    return mqtt_command;
}