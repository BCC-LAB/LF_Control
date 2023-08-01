import orjson
import logging

logger = logging.getLogger("__CMD__")

class Json_msg_to_ros:
    rate = None
    # Ros publisher
    publisher_Cmd_Broadcast = None

    @classmethod
    def ros_pub(cls, dataJson):
        logger.debug(dataJson.payload.decode("UTF-8"))
        cls.publisher_Cmd_Broadcast.publish(dataJson.payload.decode("UTF-8"))
        cls.rate.sleep()


    @staticmethod
    def on_message(client, userdata, msg):
        Json_msg_to_ros.ros_pub(msg)