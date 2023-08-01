; Auto-generated. Do not edit!


(cl:in-package class_model-msg)


;//! \htmlinclude receiverCMD.msg.html

(cl:defclass <receiverCMD> (roslisp-msg-protocol:ros-message)
  ((cmd
    :reader cmd
    :initarg :cmd
    :type cl:string
    :initform ""))
)

(cl:defclass receiverCMD (<receiverCMD>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <receiverCMD>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'receiverCMD)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name class_model-msg:<receiverCMD> is deprecated: use class_model-msg:receiverCMD instead.")))

(cl:ensure-generic-function 'cmd-val :lambda-list '(m))
(cl:defmethod cmd-val ((m <receiverCMD>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader class_model-msg:cmd-val is deprecated.  Use class_model-msg:cmd instead.")
  (cmd m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <receiverCMD>) ostream)
  "Serializes a message object of type '<receiverCMD>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'cmd))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'cmd))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <receiverCMD>) istream)
  "Deserializes a message object of type '<receiverCMD>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'cmd) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'cmd) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<receiverCMD>)))
  "Returns string type for a message object of type '<receiverCMD>"
  "class_model/receiverCMD")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'receiverCMD)))
  "Returns string type for a message object of type 'receiverCMD"
  "class_model/receiverCMD")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<receiverCMD>)))
  "Returns md5sum for a message object of type '<receiverCMD>"
  "43a54fa49066cddcf148717d9d4a6353")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'receiverCMD)))
  "Returns md5sum for a message object of type 'receiverCMD"
  "43a54fa49066cddcf148717d9d4a6353")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<receiverCMD>)))
  "Returns full string definition for message of type '<receiverCMD>"
  (cl:format cl:nil "# receiverCMD.msg~%~%# Command message~%string cmd~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'receiverCMD)))
  "Returns full string definition for message of type 'receiverCMD"
  (cl:format cl:nil "# receiverCMD.msg~%~%# Command message~%string cmd~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <receiverCMD>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'cmd))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <receiverCMD>))
  "Converts a ROS message object to a list"
  (cl:list 'receiverCMD
    (cl:cons ':cmd (cmd msg))
))
