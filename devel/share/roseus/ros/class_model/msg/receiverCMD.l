;; Auto-generated. Do not edit!


(when (boundp 'class_model::receiverCMD)
  (if (not (find-package "CLASS_MODEL"))
    (make-package "CLASS_MODEL"))
  (shadow 'receiverCMD (find-package "CLASS_MODEL")))
(unless (find-package "CLASS_MODEL::RECEIVERCMD")
  (make-package "CLASS_MODEL::RECEIVERCMD"))

(in-package "ROS")
;;//! \htmlinclude receiverCMD.msg.html


(defclass class_model::receiverCMD
  :super ros::object
  :slots (_cmd ))

(defmethod class_model::receiverCMD
  (:init
   (&key
    ((:cmd __cmd) "")
    )
   (send-super :init)
   (setq _cmd (string __cmd))
   self)
  (:cmd
   (&optional __cmd)
   (if __cmd (setq _cmd __cmd)) _cmd)
  (:serialization-length
   ()
   (+
    ;; string _cmd
    4 (length _cmd)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _cmd
       (write-long (length _cmd) s) (princ _cmd s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _cmd
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _cmd (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get class_model::receiverCMD :md5sum-) "43a54fa49066cddcf148717d9d4a6353")
(setf (get class_model::receiverCMD :datatype-) "class_model/receiverCMD")
(setf (get class_model::receiverCMD :definition-)
      "# receiverCMD.msg

# Command message
string cmd

")



(provide :class_model/receiverCMD "43a54fa49066cddcf148717d9d4a6353")


