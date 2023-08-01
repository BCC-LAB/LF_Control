;; Auto-generated. Do not edit!


(when (boundp 'class_model::FlightInformation)
  (if (not (find-package "CLASS_MODEL"))
    (make-package "CLASS_MODEL"))
  (shadow 'FlightInformation (find-package "CLASS_MODEL")))
(unless (find-package "CLASS_MODEL::FLIGHTINFORMATION")
  (make-package "CLASS_MODEL::FLIGHTINFORMATION"))

(in-package "ROS")
;;//! \htmlinclude FlightInformation.msg.html


(defclass class_model::FlightInformation
  :super ros::object
  :slots (_LAT _LON _ALT _heading ))

(defmethod class_model::FlightInformation
  (:init
   (&key
    ((:LAT __LAT) 0)
    ((:LON __LON) 0)
    ((:ALT __ALT) 0)
    ((:heading __heading) 0)
    )
   (send-super :init)
   (setq _LAT (round __LAT))
   (setq _LON (round __LON))
   (setq _ALT (round __ALT))
   (setq _heading (round __heading))
   self)
  (:LAT
   (&optional __LAT)
   (if __LAT (setq _LAT __LAT)) _LAT)
  (:LON
   (&optional __LON)
   (if __LON (setq _LON __LON)) _LON)
  (:ALT
   (&optional __ALT)
   (if __ALT (setq _ALT __ALT)) _ALT)
  (:heading
   (&optional __heading)
   (if __heading (setq _heading __heading)) _heading)
  (:serialization-length
   ()
   (+
    ;; uint32 _LAT
    4
    ;; uint32 _LON
    4
    ;; uint32 _ALT
    4
    ;; uint32 _heading
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _LAT
       (write-long _LAT s)
     ;; uint32 _LON
       (write-long _LON s)
     ;; uint32 _ALT
       (write-long _ALT s)
     ;; uint32 _heading
       (write-long _heading s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _LAT
     (setq _LAT (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _LON
     (setq _LON (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _ALT
     (setq _ALT (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _heading
     (setq _heading (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get class_model::FlightInformation :md5sum-) "fc743ed1ccbcb3c34c37472dd8dab444")
(setf (get class_model::FlightInformation :datatype-) "class_model/FlightInformation")
(setf (get class_model::FlightInformation :definition-)
      "# FlightInformation.msg

# Custom GPS message
uint32 LAT
uint32 LON
uint32 ALT

# Flight information message
uint32 heading

")



(provide :class_model/FlightInformation "fc743ed1ccbcb3c34c37472dd8dab444")


