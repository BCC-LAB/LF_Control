/*Follow the leader in a fixed formation */
#ifndef FORMATION_H
#define FORMATION_H

#include <ros/ros.h>
#include "class_model/sensor.h"
#include "class_model/mode.h"
#include "class_model/receiver.h"
#include "class_model/control.h"
#include "class_model/command.h"
#include "class_model/requestData.h"
#include "class_model/PID.h"
#include <std_msgs/String.h>



class FormationClass {
public:
    FormationClass();
    virtual ~FormationClass();
        //ClassObject
    ThreadGPSClass GPS_object;
    ModeClass mode_object;
    ReceiverClass receiver_object;
    ControlClass control_object;
    CommandClass command_object;
    RequestClass request_object;
    PIDClass PID_x;
    PIDClass PID_y;
    
    void leader();
    void leader1(float x=0.0,float y=0.0);
    void follower1(int type);
    void follower2(int type);
    void follower3(int type);
    void follower4(int type);
    void follower5(int type);
    void follower6(int type);
    void sph_follower1(int type);
    void sph_follower2(int type);
    void sph_follower3(int type);
    void sph_follower4(int type);
    void face2target(float target_heading);
private:
    // ROS NodeHandle
    ros::NodeHandle node_handle_;

    global_location target_location;
    global_location follower_location;
    global_location leader_location;
    global_location current_location;
    int flag = 0,heading_status = 0,buf = 0;
    float pre_alt,cur_alt;
    float error_lon,error_lat;
    float leader_pid[3] = {0.5 , 0.000001 ,0.001};
    float follower_pid[3] = {0.5 , 0.000001 ,0.001};
    float ignore_small = 0.50;

    void calculate_position(float k,float theta);
    void spherical_coordinate(float k,float theta,float psi);
    void go2target(float x,float y);

    //PUBLISHER
    ros::Publisher next_command;

      // SUBSCRIBE
    ros::Subscriber command_break;

};

#endif // FORMATION_H
