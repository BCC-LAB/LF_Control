/*Setting Pixhawk Mode*/
#ifndef MODE_H
#define MODE_H

#include <ros/ros.h>
#include <mavros_msgs/SetMode.h>

class ModeClass {
public:
  ModeClass();
  virtual ~ModeClass();
  int set_Mode(std::string mode);

private:
  // ROS NodeHandle
  ros::NodeHandle node_handle_;

  //SERVICE
  ros::ServiceClient set_mode_client;

};

#endif // MODE_H