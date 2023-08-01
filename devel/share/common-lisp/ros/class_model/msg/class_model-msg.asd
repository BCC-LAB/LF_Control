
(cl:in-package :asdf)

(defsystem "class_model-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "FlightInformation" :depends-on ("_package_FlightInformation"))
    (:file "_package_FlightInformation" :depends-on ("_package"))
    (:file "receiverCMD" :depends-on ("_package_receiverCMD"))
    (:file "_package_receiverCMD" :depends-on ("_package"))
  ))