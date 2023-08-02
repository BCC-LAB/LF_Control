#!/usr/bin/env python3
#coding:utf-8
import os
import sys
import time
import utils
import logging
import rospy
from std_msgs.msg import String
from class_model.msg import FlightInformation

def init_dataFormat(cfg:utils.Read_SUB_Config):
    # ROS
    utils.Json_msg_to_ros.rate = rospy.Rate(10)
    utils.Json_msg_to_ros.publisher_Flight_Information = rospy.Publisher(cfg.ROStopicName_Flight_Information,FlightInformation,queue_size=10)
    utils.Json_msg_to_ros.FlightInformationRosMsg = FlightInformation()
    # MQTT
    client.on_message = utils.Json_msg_to_ros.on_message_Flight_Information
    utils.Json_msg_to_ros.Flight_Information_topicToMqtt = cfg.Flight_Information_topicToMqtt

def on_connect(self, userdata, flags, rc):
    logger.info("Connected with result code " + str(rc))
    client.subscribe(cfg.Flight_Information_topicToMqtt)

def on_disconnect(client, userdata, rc):
    logger.info("disconnecting reason  "  +str(rc))
    client.connected_flag=False
    client.disconnect_flag=True

def on_publish(self, userdata, mid):
    logger.debug(cfg)

if __name__ == '__main__':
    # Read Config
    FilePath = os.path.join(os.path.dirname(__file__),"utils","mqttConfig_SUB.yml")
    cfg = utils.Read_SUB_Config(FilePath)
    client = utils.MQTTClient(cfg.MQTTClientNameSub)
    
    # set log
    log_format = "%(asctime)s - %(levelname)s - %(message)s"
    formatter = logging.Formatter(log_format)

    stream_handler = logging.StreamHandler()
    stream_handler.setFormatter(formatter)
    stream_handler.setLevel(logging.DEBUG)

    file_handler = logging.FileHandler(cfg.logFileName)
    file_handler.setFormatter(formatter)
    file_handler.setLevel(logging.INFO)

    logger = logging.getLogger(__name__)
    logger.setLevel(logging.INFO)
    logger.addHandler(file_handler)
    logger.addHandler(stream_handler)
    logger.info(cfg)
      
    # Mqtt
    client = utils.MQTTClient(cfg.MQTTClientNameSub)
    client.on_connect = on_connect
    client.on_publish = on_publish
    client.on_disconnect = on_disconnect
    client.connect(host=cfg.host, port=cfg.port, keepalive=cfg.keepalive)

    # Ros
    rospy.init_node(cfg.ROSClientNameSub)
    # initialize
    init_dataFormat(cfg)
    try:
        client.loop_start()
        rospy.spin()
    except BaseException as error:
        client.loop_stop()
        client.disconnect()
        logger.info("End of program")
        sys.exit(0)
