/*PID Controlier*/
#ifndef PID_H
#define PID_H

#include <ros/ros.h>
#include "ctime"

class PIDClass {
public:
//   PIDClass();
//   virtual ~PIDClass();
  float update(float current ,float target ,float pidvals[3]);
  float update1(float current ,float target );
private:
  // ROS NodeHandle
  ros::NodeHandle node_handle_;

  float pidval1[3] = {0.5 , 0.000000000001 , 0.5};
  float limit[2] = {1 , -1};
  float targetvals,pError,I;
  clock_t pTime = 0,current_time;



};

#endif // PID_H
