/*Subscribe Data Which MQTT Pubilsh */
#ifndef REQUESTDATA_H
#define REQUESTDATA_H
#define MQTT

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>
#include <class_model/gps_location.h>
#include "class_model/FlightInformation.h"



class RequestClass {
public:
    RequestClass();
    virtual ~RequestClass();
    global_location get_leader_GPS();
    global_location get_leader_data();
    float get_leader_heading();
    int get_formation_message();
    
private:
  // ROS NodeHandle
    ros::NodeHandle node_handle_;

    void Data_callback(const class_model::FlightInformation::ConstPtr &gps);
    void Message_callback(const std_msgs::String::ConstPtr &message);
    void LeaderData_callback(const class_model::FlightInformation::ConstPtr &data);
    void jsonToInt(std::string data);
    void jsonToString(std::string data);
    void StringToJson(std::string data);
    float heading;
    global_location leader_data;
  // SUBSCRIBE
    ros::Subscriber mqtt_data; 
    ros::Subscriber formation_data;
    ros::Subscriber Leader_data;

};

#endif // REQUESTDATA_H

