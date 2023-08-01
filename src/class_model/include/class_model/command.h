/*Drone Control Command*/
#ifndef COMMAND_H
#define COMMAND_H

#include <ros/ros.h>
#include <geometry_msgs/TwistStamped.h>
#include <mavros_msgs/GlobalPositionTarget.h>
#include <class_model/sensor.h>


class CommandClass {
public:
    CommandClass();
    virtual ~CommandClass();
    void set_global_position(double lon,double lat,float alt,float yaw);
    void set_velocity(float x,float y,float alt,float yaw,float second);
    void fix_velocity(float x,float y,float alt,float yaw,float second);
    void velocity_init();
    void set_target_position(float x,float y);
    ThreadGPSClass gps_object;


private:
    // ROS NodeHandle
    ros::NodeHandle node_handle_;

    geometry_msgs::TwistStamped msg;
    // mavros_msgs::GlobalPositionTarget goal_position;
    global_location current_location;
    global_location target_location;
    global_location origin_location;
    global_location pre_location;
    float errorX,errorY,lon_speed,lat_speed;

    int fix_position(global_location pre_location,float x,float y,float s);
    float clip(float speed,float max_speed,float min_speed);
    //SERVICE

    //SUBSCRIBE

    //PUBLISHER
    ros::Publisher velocity_command;
    ros::Publisher gps_command; 

};

#endif // COMMAND_H
