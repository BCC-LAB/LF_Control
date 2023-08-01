#include "class_model/select.h"

int main(int argc, char **argv) {

    // Init ROS node
    ros::init(argc, argv, "drone2_node");

    // reate Assync spiner
    ros::AsyncSpinner spinner(0);
	spinner.start();
    // ros::Rate rate(5);   

    ModeClass mode_object;
    ControlClass control_object;
    ReceiverClass receiver_object;
    CommandClass command_object;
    SelectClass select_formation;
    
    std::string type = "",pre_type ="x";
    int flag = 0;

    mode_object.set_Mode("GUIDED");
    while(flag!=1){
        type = receiver_object.check_command();
        if(type == "go"){
            mode_object.set_Mode("GUIDED");
            control_object.arm();
            control_object.takeoff(4);
            sleep(2);
            flag = 1;
            type ="";
        }   
    }
    

    while(ros::ok() && flag == 1){
        type = receiver_object.check_command();
        
    if(pre_type == type){
        type = "alreadly_set";
        // ROS_INFO("set");
    }
    
// TODO: switch case
    if(type == "init"){
        select_formation.goose_formation();
        pre_type ="init";
        ROS_INFO("init formation");
    }else if(type == "line"){
        select_formation.line_formation();
        pre_type ="line";
    }else if(type == "row"){
        select_formation.row_formation();
        pre_type ="row";
    }else if(type == "v1"){                         
        select_formation.goose_formation(0,5);
        pre_type ="v1";
    }else if(type == "v2"){
        select_formation.goose_formation(-5,0);
        pre_type ="v2";
    }else if(type == "v3"){
        select_formation.goose_formation(0,-5);
        pre_type ="v3";
    }else if(type == "v4"){
        select_formation.goose_formation(5,0);
        pre_type ="v4";
    }else if(type == "house"){
        select_formation.house_formation();
        pre_type ="house";
    }else if(type == "stop"){
        select_formation.stop();
    }else if(type == "land"){
        // ROS_INFO("Land");
        mode_object.set_Mode("LAND");
    }

    }

    ros::waitForShutdown();

    return 0;
}
