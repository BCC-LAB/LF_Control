#include "class_model/select.h"


SelectClass::SelectClass() : node_handle_(""){
    

}

SelectClass::~SelectClass() { ros::shutdown(); }

void SelectClass::init_formation(float x ,float y){

    counter = 0;
    // if(param_object.getID() == 1){
    //     formation_object.leader();
    // }else if(param_object.getID() == 2){
    //     formation_object.follower1(counter);
    // }else if(param_object.getID() == 3){
    //     formation_object.follower2(counter);
    // }else if(param_object.getID() == 4){
    //     formation_object.follower3(counter);
    // }else if(param_object.getID() == 5){
    //     formation_object.follower4(counter);
    // }

    if(param_object.getID() == 1){
        formation_object.leader1(x,y);
    }else if(param_object.getID() == 2){
        formation_object.sph_follower1(counter);
    }else if(param_object.getID() == 3){
        formation_object.sph_follower2(counter);
    }else if(param_object.getID() == 4){
        formation_object.sph_follower3(counter);
    }else if(param_object.getID() == 5){
        formation_object.sph_follower4(counter);
    }


    // sleep(2);

    // mode_object.set_Mode("LAND");

}

void SelectClass::goose_formation(float x ,float y){

    counter = 0;
    if(param_object.getID() == 1){
        formation_object.leader1(x,y);
    }else if(param_object.getID() == 2){
        formation_object.follower1(counter);
    }else if(param_object.getID() == 3){
        formation_object.follower2(counter);
    }else if(param_object.getID() == 4){
        formation_object.follower3(counter);
    }else if(param_object.getID() == 5){
        formation_object.follower4(counter);
    }else if(param_object.getID() == 6){
        formation_object.follower5(counter);
    }else if(param_object.getID() == 7){
        formation_object.follower6(counter);
    }


    // sleep(2);

    // mode_object.set_Mode("LAND");

}

void SelectClass::line_formation(float x ,float y){
    
    counter = 1;
    if(param_object.getID() == 1){
        formation_object.leader1(x,y);
    }else if(param_object.getID() == 2){
        formation_object.follower1(counter);
    }else if(param_object.getID() == 3){
        formation_object.follower2(counter);
    }else if(param_object.getID() == 4){
        formation_object.follower3(counter);
    }else if(param_object.getID() == 5){
        formation_object.follower4(counter);
    }else if(param_object.getID() == 6){
        formation_object.follower5(counter);
    }else if(param_object.getID() == 7){
        formation_object.follower6(counter);
    }
    // sleep(2);

    // mode_object.set_Mode("LAND");

}

void SelectClass::row_formation(float x ,float y){

    counter = 2;
    if(param_object.getID() == 1){
        formation_object.leader1(x,y);
    }else if(param_object.getID() == 2){
        formation_object.follower1(counter);
    }else if(param_object.getID() == 3){
        formation_object.follower2(counter);
    }else if(param_object.getID() == 4){
        formation_object.follower3(counter);
    }else if(param_object.getID() == 5){
        formation_object.follower4(counter);
    }else if(param_object.getID() == 6){
        formation_object.follower5(counter);
    }else if(param_object.getID() == 7){
        formation_object.follower6(counter);
    }
    // sleep(2);

    // mode_object.set_Mode("LAND");

}

void SelectClass::circle_formation(){

    counter = 3;
    if(param_object.getID() == 1){
        formation_object.leader1();
    }else if(param_object.getID() == 2){
        formation_object.follower1(counter);
    }else if(param_object.getID() == 3){
        formation_object.follower2(counter);
    }else if(param_object.getID() == 4){
        formation_object.follower3(counter);
    }else if(param_object.getID() == 5){
        formation_object.follower4(counter);
    }else if(param_object.getID() == 6){
        formation_object.follower5(counter);
    }
    // sleep(2);

    // mode_object.set_Mode("LAND");
}

void SelectClass::protect_formation(float x ,float y){

    counter = 4;
    if(param_object.getID() == 1){
        formation_object.leader1(x,y);
    }else if(param_object.getID() == 2){
        formation_object.follower1(counter);
    }else if(param_object.getID() == 3){
        formation_object.follower2(counter);
    }else if(param_object.getID() == 4){
        formation_object.follower3(counter);
    }else if(param_object.getID() == 5){
        formation_object.follower4(counter);
    }else if(param_object.getID() == 6){
        formation_object.follower5(counter);
    }
    // sleep(2);

    // mode_object.set_Mode("LAND");
}

void SelectClass::Hex_formation(float x ,float y){

    counter = 5;
    if(param_object.getID() == 1){
        formation_object.leader1(x,y);
    }else if(param_object.getID() == 2){
        formation_object.follower1(counter);
    }else if(param_object.getID() == 3){
        formation_object.follower2(counter);
    }else if(param_object.getID() == 4){
        formation_object.follower3(counter);
    }else if(param_object.getID() == 5){
        formation_object.follower4(counter);
    }else if(param_object.getID() == 6){
        formation_object.follower5(counter);
    }
    // sleep(2);

    // mode_object.set_Mode("LAND");
}

void SelectClass::start_formation(){

    JobNumber = param_object.getParam("JobNumber");
    if(JobNumber == 0){
        formation_object.leader1();
    }else if(JobNumber == 1){
        formation_object.follower1(counter);
    }else if(JobNumber == 2){
        formation_object.follower2(counter);
    }else if(JobNumber == 3){
        formation_object.follower3(counter);
    }else if(JobNumber == 4){
        formation_object.follower4(counter);
    }else if(JobNumber == 5){
        formation_object.follower5(counter);
    }
}

void SelectClass::house_formation(float x ,float y){

    counter = 6;
    if(param_object.getID() == 1){
        formation_object.leader1(x,y);
    }else if(param_object.getID() == 2){
        formation_object.follower1(counter);
    }else if(param_object.getID() == 3){
        formation_object.follower2(counter);
    }else if(param_object.getID() == 4){
        formation_object.follower3(counter);
    }else if(param_object.getID() == 5){
        formation_object.follower4(counter);
    }else if(param_object.getID() == 6){
        formation_object.follower5(counter);
    }else if(param_object.getID() == 7){
        formation_object.follower6(counter);
    }


    // sleep(2);

    // mode_object.set_Mode("LAND");

}

void SelectClass::stop(){

}