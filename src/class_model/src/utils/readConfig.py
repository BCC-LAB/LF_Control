import yaml

class Config:
    def __init__(self, inFileName):
        self.sectionNames = ["MQTT","ROS", "LOG"]
        self.options = {}
        self.inFileName = inFileName

    def setAttribute(self):
        with open(self.inFileName,"r") as f:
            self.ymlcfg=yaml.safe_load(f)
        
        ecfgs = [self.ymlcfg.get(name) for name in self.sectionNames]
        if None in ecfgs:
            nameIndex = ecfgs.index(None)
            raise Exception("Missing {} section in cfg file".format(self.sectionNames[nameIndex]))
        #iterate over options
        for opts, ecfg in zip(self.options, ecfgs):
            for opt in self.options[opts]:
                if opt in ecfg:
                    optval=ecfg[opt]
                    #verify parameter type
                    if type(optval) != self.options[opts][opt][0]:
                        raise Exception("Parameter {} has wrong type".format(opt))
                     
                    #create attributes on the fly
                    setattr(self,opt,optval)
                else:
                    if self.options[opts][opt][1]:
                        raise Exception("Missing mandatory parameter {}".format(opt))
                    else:
                        setattr(self,opt,None)
         
    def __str__(self):
        return str(yaml.dump(self.ymlcfg, default_flow_style=False))


class Read_PUB_Config(Config):
    def setAttribute(self):
        super().setAttribute()

    def __init__(self, inFileName):      
        super().__init__(inFileName)  
        self.options = {
            self.sectionNames[0]:{
                            "msg_format": (str,False),
                            "MQTTClientNamePub": (str,True),
                            "host": (str,True),
                            "port": (int,True),
                            "keepalive": (int,True),
                            "Flight_Information_topicToMqtt": (str,False)},
            self.sectionNames[1]:{
                            "ROSClientNamePub": (str,False),
                            "ROStopicName_Flight_Information": (str,False)},
            self.sectionNames[2]:{
                            "logFileName":(str,False)}}
        self.setAttribute()

    def __str__(self):
        return super().__str__()

class Read_SUB_Config(Config):
    def setAttribute(self):
        super().setAttribute()

    def __init__(self, inFileName):      
        super().__init__(inFileName)  
        self.options = {
            self.sectionNames[0]:{
                            "msg_format": (str,False),
                            "MQTTClientNameSub": (str,True),
                            "host": (str,True),
                            "port": (int,True),
                            "keepalive": (int,True),
                            "Flight_Information_topicToMqtt": (str,False)},
            self.sectionNames[1]:{
                            "ROSClientNameSub": (str,False),
                            "ROStopicName_Flight_Information": (str,False)},
            self.sectionNames[2]:{
                            "logFileName":(str,False)}}
        self.setAttribute()

    def __str__(self):
        return super().__str__()

class Read_CMD_Config(Config):
    def setAttribute(self):
        super().setAttribute()

    def __init__(self, inFileName):      
        super().__init__(inFileName)  
        self.options = {
            self.sectionNames[0]:{
                            "msg_format": (str,False),
                            "MQTTClientNameCmd": (str,True),
                            "host": (str,True),
                            "port": (int,True),
                            "keepalive": (int,True),
                            "Cmd_Broadcast_topicToMqtt": (str,True),
                            "Cmd_Broadcast_topicToMqtt_QOS": (int,True)},
            self.sectionNames[1]:{
                            "ROSClientNameCmd": (str,True),
                            "ROStopicName_Cmd_Broadcast_Receiver": (str,True)},
            self.sectionNames[2]:{
                            "logFileName":(str,False)}}
        self.setAttribute()

    def __str__(self):
        return super().__str__()

if __name__ == "__main__":
    cfg=Read_CMD_Config("mqttConfig_CMD.yml")
    print(cfg)


