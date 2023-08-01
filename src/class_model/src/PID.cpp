#include "class_model/PID.h"

// PIDClass::PIDClass() : node_handle_(""){
    

// }

// PIDClass::~PIDClass() { ros::shutdown(); }

float PIDClass::update(float current ,float target ,float pidvals[3]){

    current_time = std::clock();
    // pTime = current_time -
    double t = (current_time - pTime)/1e6;
    float error = (target - current)/1.1;

    double P,D,result;
    P = pidvals[0] * error;
    I = I + (pidvals[1] * error *t);
    // D = (pidvals[2] * (error - pError))/t;
    D = 0;

    result = P + I + D;

    if (limit !=NULL){
        if (result > limit[0]){
            result = limit[0];
        }
        if (result < limit[1]){
            result = limit[1];
        }
    }

    pError = error;
    pTime = current_time; 

    // ROS_INFO("%f,%f,%f",P,I,D);

    return result;
}

float PIDClass::update1(float current ,float target){

    current_time = std::clock();
    // pTime = current_time -
    double t = (current_time - pTime);
    float error = target - current;

    double P,D,result;
    P = pidval1[0] * error;
    I = I + (pidval1[1] * error *t);
    D = (pidval1[2] * (error - pError))/t;

    result = P + I + D;

    if (limit !=NULL){
        if (result > limit[0]){
            result = limit[0];
        }
        if (result < limit[1]){
            result = limit[1];
        }
    }

    pError = error;
    pTime = current_time; 

    // ROS_INFO("%f,%f,%f",P,I,D);

    return result;
}