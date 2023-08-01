#include"class_model/requestData.h"
#include <cstdlib>
#include <iostream>

global_location leader_position;
int command; 

RequestClass::RequestClass() : node_handle_(""){

  mqtt_data = node_handle_.subscribe("/Flight_Information_reciver", 100,
                                   &RequestClass::Data_callback, this);
  formation_data = node_handle_.subscribe("/Fly_Formation_reciver", 10,
                                   &RequestClass::Message_callback, this);

}

RequestClass::~RequestClass() { ros::shutdown(); }

void RequestClass::Data_callback(const class_model::FlightInformation::ConstPtr &sensor) {

  #ifdef MQTT
  leader_data.lon = sensor->LON;
  leader_data.lat = sensor->LAT;
  leader_data.alt = sensor->ALT;
  leader_data.heading = sensor->heading; 
  #endif

}

void RequestClass::Message_callback(const std_msgs::String::ConstPtr &message) {

	std::string data = message->data;

}


global_location RequestClass::get_leader_data(){

  return leader_data; 
}

global_location RequestClass::get_leader_GPS(){

  return leader_position; 
}

float RequestClass::get_leader_heading(){
  
  return heading;
}

int RequestClass::get_formation_message(){

  return command;
}
