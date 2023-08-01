#include "class_model/formation.h"
#include "class_model/convert_degree.h"

FormationClass::FormationClass() : node_handle_(""){
  	
    std::string ros_namespace;
	if (!node_handle_.hasParam("namespace"))
	{
	}else{
		node_handle_.getParam("namespace", ros_namespace);
	}

    next_command=node_handle_.advertise<std_msgs::String>(ros_namespace+"/mavros/next_command",100); 



}

FormationClass::~FormationClass() { ros::shutdown(); }

void FormationClass::leader(){

    int counter=0;
    std::string command = "",pre_command = "";
    
    while(true){
    if(flag==0){
    command_object.set_velocity(0,0,0,0.1,1);
    sleep(5);
    while(counter<=5){
        command_object.set_velocity(-1,1,0,0,1);
        command = receiver_object.check_command();
        
        while(command =="stop" || command == "land"){
            command_object.set_velocity(0,0,0,0,1);
            command = receiver_object.check_command();
            
            if(command == "land"){
                mode_object.set_Mode("LAND");
            }else if(command != "stop"){
                break;
            }
            
        }

    counter++;
    std::cout << command <<std::endl;
    }
    if(counter>=5){
        flag = 1;
    }
    command = receiver_object.check_command();
    }
    if(command == "land"){
        mode_object.set_Mode("LAND");
        ROS_INFO("xxxx");
    }
    
}
}

void FormationClass::leader1(float x,float y){

    std::string command = "",pre_command = "";
    std_msgs::String message;

    leader_location=request_object.get_leader_GPS();
    target_location.lon = leader_location.lon/100 + x;
    target_location.lat = leader_location.lat/100 + y/1.1;
    sleep(3);
    flag = 0;
    heading_status = 0;
    // message.data = "1";
    while(true){
        if(flag==0){
            go2target(x,y);
        }else{
            // next_command.publish(message);
            ROS_INFO("break");
            break;
        }

        command = receiver_object.check_command();
        while(command =="stop" || command == "land"){
            command_object.set_velocity(0,0,0,0,1);
            command = receiver_object.check_command();
            
            if(command == "land"){
                mode_object.set_Mode("LAND");
            }else if(command != "stop"){
                break;
            }
            
        }

        if(command != pre_command){
            // ROS_INFO("change formation");
            break;
        }
        pre_command = command;
    }
}

void FormationClass::follower1(int type){

    std::string command,pre_command = "";
    int message;
    while(true){
        
        if(type == 0){
            calculate_position(4,30);
        }else if(type == 1){
            calculate_position(4,0);
        }else if(type == 2){
            calculate_position(4,90);
        }else if(type == 3){
            calculate_position(4,120);
        }else if(type == 4){
            calculate_position(2.5,120);
        }else if(type == 5){
            calculate_position(4,60);
        }

        command = receiver_object.check_command();
        // message = request_object.get_formation_message();
        // ROS_INFO("%d",message);

        if(command != pre_command ){
            // ROS_INFO("change formation");
            break;
        }
        pre_command = command;
        

    }

    // sleep(2);

    // mode_object.set_Mode("LAND");

}

void FormationClass::follower2(int type){

    std::string message,command,pre_command = "";
    while(true){
        
        if(type == 0){
            calculate_position(4,-30);
        }else if(type == 1){
            calculate_position(8,0);
        }else if(type == 2){
            calculate_position(4,-90);
        }else if(type == 3){
            calculate_position(4,-120);
        }else if(type == 4){
            calculate_position(2.5,-120);
        }else if(type == 5){
            calculate_position(4,-60);
        }

        command = receiver_object.check_command();
        //message = request_object.get_formation_message();

        if(command != pre_command ){
            // ROS_INFO("change formation");
            break;
        }
        pre_command = command;
        

    }

}

void FormationClass::follower3(int type){

    std::string message,command,pre_command = "";
    while(true){
        
        if(type == 0){
            calculate_position(8,30);
        }else if(type == 1){
            calculate_position(12,0);
        }else if(type == 2){
            calculate_position(8,90);
        }else if(type == 3){
            calculate_position(6,160);
        }else if(type == 4){
            calculate_position(2.5,60);
        }else if(type == 5){
            calculate_position(6.93,30);
        }
        

        command = receiver_object.check_command();
        //message = request_object.get_formation_message();

        if(command != pre_command ){
            // ROS_INFO("change formation");
            break;
        }
        pre_command = command;
        

    }

}

void FormationClass::follower4(int type){

    std::string message,command,pre_command = "";
    while(true){
        
        if(type == 0){
            calculate_position(8,-30);
        }else if(type == 1){
            calculate_position(16,0);
        }else if(type == 2){
            calculate_position(8,-90);
        }else if(type == 3){
            calculate_position(6,-160);
        }else if(type == 4){
            calculate_position(2.5,-60);
        }else if(type == 5){
            calculate_position(6.93,-30);
        }

        command = receiver_object.check_command();
        //message = request_object.get_formation_message();

        if(command != pre_command ){
            // ROS_INFO("change formation");
            break;
        }
        pre_command = command;

    }

}

void FormationClass::follower5(int type){

    std::string message,command,pre_command = "";
    while(true){
        
        if(type == 0){
            calculate_position(12,-30);
        }else if(type == 1){
            calculate_position(20,0);
        }else if(type == 2){
            calculate_position(6,-90);
        }else if(type == 3){
            calculate_position(6,180);
        }else if(type == 4){
            calculate_position(3,0);
        }else if(type == 5){
            calculate_position(8,0);
        }

        command = receiver_object.check_command();
        //message = request_object.get_formation_message();

        if(command != pre_command ){
            // ROS_INFO("change formation");
            break;
        }
        pre_command = command;
        

    }

}

void FormationClass::follower6(int type){

    std::string message,command,pre_command = "";
    while(true){
        
        if(type == 0){
            calculate_position(12,-30);
        }else if(type == 1){
            calculate_position(20,0);
        }else if(type == 2){
            calculate_position(6,-90);
        }else if(type == 3){
            calculate_position(6,180);
        }else if(type == 4){
            calculate_position(3,0);
        }else if(type == 5){
            calculate_position(8,0);
        }

        command = receiver_object.check_command();
        //message = request_object.get_formation_message();

        if(command != pre_command ){
            // ROS_INFO("change formation");
            break;
        }
        pre_command = command;
        

    }

}

void FormationClass::sph_follower1(int type){

    std::string message,command,pre_command = "";
    while(true){
        
        if(type == 0){
            spherical_coordinate(4,30,30);
        // }else if(type == 1){
        //     calculate_position(12,0,1);
        // }else if(type == 2){
        //     calculate_position(8,90,1);
        // }else if(type == 3){
        //     calculate_position(6,160,1);
        // }else if(type == 4){
        //     calculate_position(2.5,60,1);
        }
        

        command = receiver_object.check_command();
        message = request_object.get_formation_message();

        if(command != pre_command || message == "1"){
            // ROS_INFO("change formation");
            break;
        }
        pre_command = command;
        

    }

}

void FormationClass::sph_follower2(int type){

    std::string message,command,pre_command = "";
    while(true){
        
        if(type == 0){
            spherical_coordinate(4,-30,30);
        // }else if(type == 1){
        //     calculate_position(12,0,1);
        // }else if(type == 2){
        //     calculate_position(8,90,1);
        // }else if(type == 3){
        //     calculate_position(6,160,1);
        // }else if(type == 4){
        //     calculate_position(2.5,60,1);
        }
        

        command = receiver_object.check_command();
        message = request_object.get_formation_message();

        if(command != pre_command || message == "1"){
            // ROS_INFO("change formation");
            break;
        }
        pre_command = command;

    }

}

void FormationClass::sph_follower3(int type){

    std::string message,command,pre_command = "";
    while(true){
        
        if(type == 0){
            spherical_coordinate(4,30,-30);
        // }else if(type == 1){
        //     calculate_position(12,0,1);
        // }else if(type == 2){
        //     calculate_position(8,90,1);
        // }else if(type == 3){
        //     calculate_position(6,160,1);
        // }else if(type == 4){
        //     calculate_position(2.5,60,1);
        }
        

        command = receiver_object.check_command();
        message = request_object.get_formation_message();

        if(command != pre_command || message == "1"){
            // ROS_INFO("change formation");
            break;
        }
        pre_command = command;
        

    }
}

void FormationClass::sph_follower4(int type){

    std::string message,command,pre_command = "";
    while(true){
        
        if(type == 0){
            spherical_coordinate(4,-30,-30);
        // }else if(type == 1){
        //     calculate_position(12,0,1);
        // }else if(type == 2){
        //     calculate_position(8,90,1);
        // }else if(type == 3){
        //     calculate_position(6,160,1);
        // }else if(type == 4){
        //     calculate_position(2.5,60,1);
        }
        

        command = receiver_object.check_command();
        message = request_object.get_formation_message();

        if(command != pre_command || message == "1"){
            // ROS_INFO("change formation");
            break;
        }
        pre_command = command;
        

    }
}





void FormationClass::calculate_position(float k,float theta){

    leader_location=request_object.get_leader_data();           //get Leader's data 
    float deg_phi = leader_location.heading/100;
    float heading = GPS_object.get_heading();
    
    float phi = deg_phi*3.14/180;             //degree-->radian
    theta = theta*3.14/180;

                    
    follower_location=GPS_object.gps_position();    //get Follower's GPS


    double Pf[]={},Pl[]={leader_location.lon,leader_location.lat};       //transfer maxtrix  
    float transfer[2][2]={
                            cos(phi),-sin(phi),
                            sin(phi),cos(phi)
                        };
    float Q[2]={k*sin(theta),k*cos(theta)};
    float T[2]={1,-1};

    Pf[0]=(transfer[0][0]*Q[0]+transfer[0][1]*Q[1])*T[0]+Pl[0]/100;
    Pf[1]=(transfer[1][0]*Q[0]+transfer[1][1]*Q[1])*T[1]+Pl[1]/100;
    
    
    float error_x = PID_x.update(follower_location.lon*1e5 , Pf[0] ,follower_pid);       //caculate error
    float error_y = PID_y.update(follower_location.lat*1e5 , Pf[1] ,follower_pid);
    
    // float error_x = PID_x.update1(follower_location.lon*1e5 , Pf[0] );       //caculate error
    // float error_y = PID_y.update1(follower_location.lat*1e5 , Pf[1] );

    // float error_x = Pf[0] - (follower_location.lon*1e+5);            //caculate error
    // float error_y = Pf[1] - (follower_location.lat*1e+5);
    
    float error_degree = deg_phi - heading ;
    float error_yaw = 0.2;   //CCW

    if (error_degree >= 360){
        error_degree -= 360;
    }
    if (error_degree <= -360){
        error_degree += 360;
    }

    error_yaw = check_direction(error_degree)*error_yaw;              //check yaw direction

    if (error_x < 0.3 && error_x > -0.3){                     //ignore small errors                  
        error_x = 0;
    }
    if (error_y < 0.3 && error_y > -0.3){
        error_y = 0;
    }
    if (error_degree < 5 && error_degree > -5 ){
        error_yaw = 0;
    }else if(error_degree >355 || error_degree < -355){
        error_yaw = 0;
    }

    // ROS_INFO("%f,%f",leader_location.lon/100 ,leader_location.lat/100);
    // ROS_INFO("%f,%f",follower_location.lon*1e+5 ,follower_location.lat*1e+5);
    // ROS_INFO("%f,%f",Pf[0],Pf[1]);
    // ROS_INFO("%f,%f",error_x,error_y);
    // ROS_INFO("deg:%f",deg_phi);
    // ROS_INFO("heading:%f",heading);
    // ROS_INFO("error_degree:%f",error_degree);
    // ROS_INFO("error_yaw:%f",error_yaw);
    // ROS_INFO("************************************");
    
    // command_object.set_velocity(error_x,error_y,0,error_yaw,0.1);
    command_object.set_global_position(Pf[0]/1e5,Pf[1]/1e5,2,deg_phi);

}

void FormationClass::spherical_coordinate(float k,float theta,float psi){

    float deg_phi = request_object.get_leader_heading()/100;
    float heading = GPS_object.get_heading();
    
    float phi = deg_phi*3.14/180;             //degree-->radian
    theta = theta*3.14/180;
    psi = psi*3.14/180;

    leader_location=request_object.get_leader_GPS();           //get Leader/Follower 's GPS         
    follower_location=GPS_object.gps_position();  

    cur_alt = leader_location.alt;
    if (cur_alt == NAN || cur_alt == -NAN){
        cur_alt = pre_alt;
    }  

    double Pf[3]={},Pl[]={leader_location.lon,leader_location.lat,cur_alt};       //transfer maxtrix  
    float transfer[3][3]={
                            cos(phi),-sin(phi),0,
                            sin(phi),cos(phi),0,
                                0   ,   0   ,1,
                        };
    float Q[3]={k*cos(psi)*sin(theta),k*cos(psi)*cos(theta),k*sin(psi)};
    float T[3]={1,-1,1};

    Pf[0]=(transfer[0][0]*Q[0] + transfer[0][1]*Q[1] + transfer[0][2]*Q[2])*T[0] + Pl[0]/100;    //calculate follower coordinate
    Pf[1]=(transfer[1][0]*Q[0] + transfer[1][1]*Q[1] + transfer[1][2]*Q[2])*T[1] + Pl[1]/100;    //rigid body ---> world
    Pf[2]=(transfer[2][2]*Q[2])*T[2] + Pl[2]/100;

    if(Pf[2] == NAN || Pf[2] == -NAN){
        Pf[2] = k*sin(psi) + cur_alt/100;
    }
    
    float error_x = PID_x.update(follower_location.lon*1e5 , Pf[0] ,follower_pid);       //caculate error
    float error_y = PID_y.update(follower_location.lat*1e5 , Pf[1] ,follower_pid);       //follower_pid defined in header file
    float error_alt = Pf[2] - follower_location.alt;
    
    // float error_x = PID_x.update1(follower_location.lon*1e5 , Pf[0] );       //caculate error
    // float error_y = PID_y.update1(follower_location.lat*1e5 , Pf[1] );

    // float error_x = Pf[0] - (follower_location.lon*1e+5);            //caculate error
    // float error_y = Pf[1] - (follower_location.lat*1e+5);
    
    float error_degree = deg_phi - heading;
    float error_yaw = 0.2;
    float error_z = (error_alt/std::abs(error_alt))*0.1;

    error_yaw = check_direction(error_degree)*error_yaw;              //check yaw direction

    if (error_x < 0.3 && error_x > -0.3){                     //ignore small errors                  
        error_x = 0;
    }
    if (error_y < 0.3 && error_y > -0.3){
        error_y = 0;
    }
    if (error_degree < 5 && error_degree > -5 ){
        error_yaw = 0;
    }else if(error_degree >355 || error_degree < -355){
        error_yaw = 0;
    }
    if(error_alt < 0.3 && error_alt > -0.3){
        error_z = 0;
    }
    
    pre_alt = leader_location.alt;

    // ROS_INFO("%f,%f",leader_location.lon/100 ,leader_location.lat/100);
    // ROS_INFO("%f,%f",follower_location.lon*1e+5 ,follower_location.lat*1e+5);
    // ROS_INFO("%f,%f",Pf[0],Pf[1]);
    // ROS_INFO("%f,%f",error_x,error_y);
    // ROS_INFO("deg:%f",deg_phi);
    // ROS_INFO("heading:%f",heading);
    // ROS_INFO("error_degree:%f",error_degree);
    // ROS_INFO("error_yaw:%f",error_yaw);
    ROS_INFO("Pl[2]:%f ,error_alt:%f,follower_location.alt:%f",Pl[2],error_alt,follower_location.alt);
    ROS_INFO("Q[2]:%f ,Pf[2]:%f ,error_z:%f",k*sin(psi),Pf[2],error_z);
    // ROS_INFO("************************************");
    
    command_object.set_velocity(error_x ,error_y ,0,0,0.1);
    // command_object.set_global_position(target_location.lon/1e5,target_location.lat/1e5,current_location.alt,heading);


}

void FormationClass::go2target(float x,float y){

    // leader_location=request_object.get_leader_GPS();
    current_location=GPS_object.gps_position(); 

    float target_heading,error_heading;
    float heading = GPS_object.get_heading();
    target_heading = ConvertDeg(x,y);   

    // float error_yaw = 0.2;
    // error_heading =  target_heading - heading;
    // error_yaw = check_direction(error_heading)*error_yaw;              //check yaw direction

    while(heading_status != 1){
        face2target(target_heading);
    }

    float error_x = PID_x.update(current_location.lon*1e5 , target_location.lon ,leader_pid);   //leader_pid defined in header file
    float error_y = PID_y.update(current_location.lat*1e5 , target_location.lat ,leader_pid);

    // float error_x = PID_x.update1(current_location.lon*1e5 , target_location.lon );
    // float error_y = PID_y.update1(current_location.lat*1e5 , target_location.lat );

    if (error_x < 0.3 && error_x > -0.3){                     //ignore small errors                  
        error_x = 0;
    }
    if (error_y < 0.3 && error_y > -0.3){
        error_y = 0;
    }

    if (error_x == 0 && error_y == 0){
        flag = 1;
    }

    command_object.set_velocity(error_x ,error_y ,0,0,0.1);

    // ROS_INFO("slope:%f,%f,%f",slope,x,y);
    // ROS_INFO("%f,%f",error_x,error_y);
    // ROS_INFO("heading:%f,target_heading:%f",heading,target_heading);
    // ROS_INFO("target:%f,%f",target_location.lon ,target_location.lat);
    // ROS_INFO("current:%f,%f",current_location.lon*1e5 ,current_location.lat*1e5);
    ROS_INFO("************************************");
    


}

void FormationClass::face2target(float target_heading){

    float error_heading;
    float heading = GPS_object.get_heading();
    float error_yaw = 0.2;
    error_heading =  target_heading - heading;
    error_yaw = check_direction(error_heading)*error_yaw; 

    if (error_heading < 5 && error_heading > -5 ){
        error_yaw = 0;
        heading_status = 1;
    }
    command_object.set_velocity(0 ,0 ,0,error_yaw,0.1);
}



