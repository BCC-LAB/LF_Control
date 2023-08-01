/*Receive Command From MQTT*/
#ifndef RECEIVER_H
#define RECEIVER_H

#include <ros/ros.h>
#include <std_msgs/String.h>
#include "class_model/mode.h"
#include "class_model/receiverCMD.h"
class ReceiverClass {
public:
    ReceiverClass();
    virtual ~ReceiverClass();
    ModeClass mode_object;
    std::string check_command();

private:
    // ROS NodeHandle
    ros::NodeHandle node_handle_;

    std::string mqtt_command;

    //SERVICE
    //SUBSCRIBE
    ros::Subscriber mqtt_sub;

    void cmd_receiver(const class_model::receiverCMD::ConstPtr &msg);

};

#endif // RECEIVER_H
