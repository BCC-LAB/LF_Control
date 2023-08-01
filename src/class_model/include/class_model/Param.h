/*Get/SET Drone's Parameter*/
#ifndef PARAM_H
#define PARAM_H

#include <ros/ros.h>

class ParamClass {
public:
    ParamClass();
    virtual ~ParamClass();
    int getID();
    int setParam(std::string ParamName , int value);
    int getParam(std::string ParamName);

private:
    // ROS NodeHandle
    ros::NodeHandle node_handle_;

    //SERVICE


    //SUBSCRIBE



    

};

#endif // PARAM_H