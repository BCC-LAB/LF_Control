#!/usr/bin/env python3
#coding:utf-8
import paho.mqtt.client as mqtt
import os
import sys
import time
from utils.readConfig import Read_CMD_Config
from utils.basicMqtt import MQTTClient
from utils.Json_mqtt_cmd_data_to_ros import Json_msg_to_ros
import logging
from std_msgs.msg import String
import rospy

def init_dataFormat(cfg:Read_CMD_Config):
    # ROS
    Json_msg_to_ros.rate = rospy.Rate(10)
    Json_msg_to_ros.publisher_Cmd_Broadcast = rospy.Publisher(cfg.ROStopicName_Cmd_Broadcast_Receiver,String,queue_size=10)
    # MQTT
    client.on_message = Json_msg_to_ros.on_message
    Json_msg_to_ros.Cmd_Broadcast_topicToMqtt = cfg.Cmd_Broadcast_topicToMqtt

def on_connect(self, userdata, flags, rc):
    logger.info("Connected with result code " + str(rc))
    client.subscribe(topic=cfg.Cmd_Broadcast_topicToMqtt, qos=cfg.Cmd_Broadcast_topicToMqtt_QOS)

def on_disconnect(client, userdata, rc):
    logger.info(f"disconnecting reason  (rc)")
    client.connected_flag=False
    client.disconnect_flag=True

if __name__ == '__main__':
    # Read Config
    FilePath = os.path.join(os.path.dirname(__file__),"utils","mqttConfig_CMD.yml")
    cfg = Read_CMD_Config(FilePath)
    client = MQTTClient(cfg.MQTTClientNameCmd)

    # set log
    log_format = "%(asctime)s - %(levelname)s - %(message)s"
    formatter = logging.Formatter(log_format)

    stream_handler = logging.StreamHandler()
    stream_handler.setFormatter(formatter)
    stream_handler.setLevel(logging.DEBUG)

    file_handler = logging.FileHandler(cfg.logFileName)
    file_handler.setFormatter(formatter)
    file_handler.setLevel(logging.INFO)

    logger = logging.getLogger("__CMD__")
    logger.setLevel(logging.DEBUG)
    logger.addHandler(file_handler)
    logger.addHandler(stream_handler)
    logger.info(cfg)

    # Mqtt
    client.on_connect = on_connect
    client.on_disconnect = on_disconnect
    client.connect(host=cfg.host, port=cfg.port, keepalive=cfg.keepalive)
    client.loop_start()

    # Ros
    rospy.init_node(cfg.ROSClientNameCmd)
    # init data format
    init_dataFormat(cfg)
    try:
        rospy.spin()
    except BaseException as error:
        client.disconnect()
        logger.info("End of program")
        sys.exit()