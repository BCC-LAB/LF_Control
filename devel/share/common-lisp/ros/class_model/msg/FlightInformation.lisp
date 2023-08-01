; Auto-generated. Do not edit!


(cl:in-package class_model-msg)


;//! \htmlinclude FlightInformation.msg.html

(cl:defclass <FlightInformation> (roslisp-msg-protocol:ros-message)
  ((LAT
    :reader LAT
    :initarg :LAT
    :type cl:integer
    :initform 0)
   (LON
    :reader LON
    :initarg :LON
    :type cl:integer
    :initform 0)
   (ALT
    :reader ALT
    :initarg :ALT
    :type cl:integer
    :initform 0)
   (heading
    :reader heading
    :initarg :heading
    :type cl:integer
    :initform 0))
)

(cl:defclass FlightInformation (<FlightInformation>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <FlightInformation>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'FlightInformation)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name class_model-msg:<FlightInformation> is deprecated: use class_model-msg:FlightInformation instead.")))

(cl:ensure-generic-function 'LAT-val :lambda-list '(m))
(cl:defmethod LAT-val ((m <FlightInformation>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader class_model-msg:LAT-val is deprecated.  Use class_model-msg:LAT instead.")
  (LAT m))

(cl:ensure-generic-function 'LON-val :lambda-list '(m))
(cl:defmethod LON-val ((m <FlightInformation>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader class_model-msg:LON-val is deprecated.  Use class_model-msg:LON instead.")
  (LON m))

(cl:ensure-generic-function 'ALT-val :lambda-list '(m))
(cl:defmethod ALT-val ((m <FlightInformation>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader class_model-msg:ALT-val is deprecated.  Use class_model-msg:ALT instead.")
  (ALT m))

(cl:ensure-generic-function 'heading-val :lambda-list '(m))
(cl:defmethod heading-val ((m <FlightInformation>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader class_model-msg:heading-val is deprecated.  Use class_model-msg:heading instead.")
  (heading m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <FlightInformation>) ostream)
  "Serializes a message object of type '<FlightInformation>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'LAT)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'LAT)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'LAT)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'LAT)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'LON)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'LON)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'LON)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'LON)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ALT)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'ALT)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'ALT)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'ALT)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'heading)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'heading)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'heading)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'heading)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <FlightInformation>) istream)
  "Deserializes a message object of type '<FlightInformation>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'LAT)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'LAT)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'LAT)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'LAT)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'LON)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'LON)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'LON)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'LON)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ALT)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'ALT)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'ALT)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'ALT)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'heading)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'heading)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'heading)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'heading)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<FlightInformation>)))
  "Returns string type for a message object of type '<FlightInformation>"
  "class_model/FlightInformation")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FlightInformation)))
  "Returns string type for a message object of type 'FlightInformation"
  "class_model/FlightInformation")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<FlightInformation>)))
  "Returns md5sum for a message object of type '<FlightInformation>"
  "fc743ed1ccbcb3c34c37472dd8dab444")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'FlightInformation)))
  "Returns md5sum for a message object of type 'FlightInformation"
  "fc743ed1ccbcb3c34c37472dd8dab444")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<FlightInformation>)))
  "Returns full string definition for message of type '<FlightInformation>"
  (cl:format cl:nil "# FlightInformation.msg~%~%# Custom GPS message~%uint32 LAT~%uint32 LON~%uint32 ALT~%~%# Flight information message~%uint32 heading~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'FlightInformation)))
  "Returns full string definition for message of type 'FlightInformation"
  (cl:format cl:nil "# FlightInformation.msg~%~%# Custom GPS message~%uint32 LAT~%uint32 LON~%uint32 ALT~%~%# Flight information message~%uint32 heading~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <FlightInformation>))
  (cl:+ 0
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <FlightInformation>))
  "Converts a ROS message object to a list"
  (cl:list 'FlightInformation
    (cl:cons ':LAT (LAT msg))
    (cl:cons ':LON (LON msg))
    (cl:cons ':ALT (ALT msg))
    (cl:cons ':heading (heading msg))
))
