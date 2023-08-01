import json

class Json_msg_to_ros:
    rate = None
    #Ros publisher
    publisher_Flight_Information = None
    #Ros msg
    FlightInformationRosMsg = None 

    @classmethod
    def on_message_Flight_Information(cls, client, userdata, msg):
        cls.publisher_Flight_Information.publish(cls.convert_proto_to_ros(msg.payload.decode("UTF-8")))
        cls.rate.sleep()

    @classmethod
    def convert_proto_to_ros(cls, json):
        FlightDict = json.loads(json)
        cls.FlightInformationRosMsg.LAT = FlightDict.get("lat")
        cls.FlightInformationRosMsg.LON = FlightDict.get("lon")
        cls.FlightInformationRosMsg.ALT = FlightDict.get("alt")
        cls.FlightInformationRosMsg.heading = FlightDict.get("heading")
        return cls.FlightInformationRosMsg
