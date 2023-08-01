import paho.mqtt.client as mqtt
import time
class MQTTClient(mqtt.Client):
   
   def __init__(self,cname,**kwargs):
      super().__init__(cname,**kwargs)
      self.last_pub_time=time.time()
      self.topic_ack=[]
      self.run_flag=True
      self.subscribe_flag=False
      self.bad_connection_flag=False
      self.connected_flag=True
      self.disconnect_flag=False
      self.disconnect_time=0.0
      self.pub_msg_count=0
      self.devices=[]

