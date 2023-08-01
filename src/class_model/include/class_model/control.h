#ifndef CONTROL_H
#define CONTROL_H

#include <ros/ros.h>
#include <mavros_msgs/CommandTOL.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/State.h>

class ControlClass {
public:
    ControlClass();
    virtual ~ControlClass();
    int arm();
    int takeoff(float takeoff_alt);

private:
    // ROS NodeHandle
    ros::NodeHandle node_handle_;

    mavros_msgs::State current_state_g;

    //SERVICE
    ros::ServiceClient arming_client;
    ros::ServiceClient takeoff_client;

    //SUBSCRIBE
    ros::Subscriber state_sub;

    void state_cb(const mavros_msgs::State::ConstPtr& msg);
    

};

#endif // CONTROL_H