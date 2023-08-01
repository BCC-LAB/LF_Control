/*Select Formation*/
#ifndef SELECT_H
#define SELECT_H

#include "class_model/receiver.h"
#include "class_model/formation.h"
#include "class_model/Param.h"

class SelectClass {
public:
    SelectClass();
    virtual ~SelectClass();
        //ClassObject
    ReceiverClass receiver_object;
    FormationClass formation_object;
    ParamClass param_object;

    void init_formation(float x=0,float y=0);
    void line_formation(float x=0,float y=0);
    void row_formation(float x=0,float y=0);
    void circle_formation();
    void goose_formation(float x=0,float y=0);
    void protect_formation(float x=0,float y=0);
    void Hex_formation(float x=0,float y=0);
    void house_formation(float x=0,float y=0);
    void start_formation();
    void stop();
    
private:
    // ROS NodeHandle
    ros::NodeHandle node_handle_;
    int counter;
    int JobNumber;
};

#endif // SELECT_H