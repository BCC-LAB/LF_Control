import json
import time

class Json_msg_from_ros:
    GPS_Data = {}
    client = None
    #Mqtt
    Flight_Information_topicToMqtt = None

    @classmethod 
    def callBack_gps(cls, GPS):
        lat=int(GPS.latitude*1e7)   #change the scale to centimeters
        lon=int(GPS.longitude*1e7)
        alt=int(GPS.altitude*1e2)
        dataGpsUpdate = {"lat": lat, "lon": lon, "alt": alt}
        cls.GPS_Data.update(dataGpsUpdate)
        dataJsonFormate = json.dumps(cls.GPS_Data)
        cls.mqtt_Pub(message=dataJsonFormate, topics=cls.Flight_Information_topicToMqtt)

    @classmethod 
    def callBack_compass_hdg(cls, Compass):
        heading = int(Compass.data*1e2)
        dataGpsUpdate = {"heading": heading}
        cls.GPS_Data.update(dataGpsUpdate)
        dataJsonFormate = json.dumps(cls.GPS_Data)
        cls.mqtt_Pub(message=dataJsonFormate, topics=cls.Flight_Information_topicToMqtt)

    @classmethod
    def mqtt_Pub(cls, message:str, topics:str, waitForAck:bool=False, qos:int=0):
        cls.client.publish(topics, message, qos)
