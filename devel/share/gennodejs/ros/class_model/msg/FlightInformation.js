// Auto-generated. Do not edit!

// (in-package class_model.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class FlightInformation {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.LAT = null;
      this.LON = null;
      this.ALT = null;
      this.heading = null;
    }
    else {
      if (initObj.hasOwnProperty('LAT')) {
        this.LAT = initObj.LAT
      }
      else {
        this.LAT = 0;
      }
      if (initObj.hasOwnProperty('LON')) {
        this.LON = initObj.LON
      }
      else {
        this.LON = 0;
      }
      if (initObj.hasOwnProperty('ALT')) {
        this.ALT = initObj.ALT
      }
      else {
        this.ALT = 0;
      }
      if (initObj.hasOwnProperty('heading')) {
        this.heading = initObj.heading
      }
      else {
        this.heading = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type FlightInformation
    // Serialize message field [LAT]
    bufferOffset = _serializer.uint32(obj.LAT, buffer, bufferOffset);
    // Serialize message field [LON]
    bufferOffset = _serializer.uint32(obj.LON, buffer, bufferOffset);
    // Serialize message field [ALT]
    bufferOffset = _serializer.uint32(obj.ALT, buffer, bufferOffset);
    // Serialize message field [heading]
    bufferOffset = _serializer.uint32(obj.heading, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type FlightInformation
    let len;
    let data = new FlightInformation(null);
    // Deserialize message field [LAT]
    data.LAT = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [LON]
    data.LON = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [ALT]
    data.ALT = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [heading]
    data.heading = _deserializer.uint32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'class_model/FlightInformation';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'fc743ed1ccbcb3c34c37472dd8dab444';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # FlightInformation.msg
    
    # Custom GPS message
    uint32 LAT
    uint32 LON
    uint32 ALT
    
    # Flight information message
    uint32 heading
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new FlightInformation(null);
    if (msg.LAT !== undefined) {
      resolved.LAT = msg.LAT;
    }
    else {
      resolved.LAT = 0
    }

    if (msg.LON !== undefined) {
      resolved.LON = msg.LON;
    }
    else {
      resolved.LON = 0
    }

    if (msg.ALT !== undefined) {
      resolved.ALT = msg.ALT;
    }
    else {
      resolved.ALT = 0
    }

    if (msg.heading !== undefined) {
      resolved.heading = msg.heading;
    }
    else {
      resolved.heading = 0
    }

    return resolved;
    }
};

module.exports = FlightInformation;
