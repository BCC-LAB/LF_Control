/*Subscribe Pixhawk Sensor Data*/
#ifndef SENSOR_H
#define SENSOR_H

#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <sensor_msgs/NavSatFix.h>
#include <class_model/gps_location.h>

class ThreadGPSClass {
public:
  ThreadGPSClass();
  virtual ~ThreadGPSClass();
  global_location gps_position();
  float get_heading();

private:
  // ROS NodeHandle
  ros::NodeHandle node_handle_;

  // SUBSCRIBE
  ros::Subscriber gps_sub;
  ros::Subscriber compass_sub;

  void GPS_callback(const sensor_msgs::NavSatFix::ConstPtr &gps);
  void Compass_callback(const std_msgs::Float64::ConstPtr &degree);

};

#endif // SENSOR_H