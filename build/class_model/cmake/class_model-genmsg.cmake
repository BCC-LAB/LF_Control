# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "class_model: 2 messages, 0 services")

set(MSG_I_FLAGS "-Iclass_model:/home/dodo/LFtest/src/class_model/msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(class_model_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/dodo/LFtest/src/class_model/msg/FlightInformation.msg" NAME_WE)
add_custom_target(_class_model_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "class_model" "/home/dodo/LFtest/src/class_model/msg/FlightInformation.msg" ""
)

get_filename_component(_filename "/home/dodo/LFtest/src/class_model/msg/receiverCMD.msg" NAME_WE)
add_custom_target(_class_model_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "class_model" "/home/dodo/LFtest/src/class_model/msg/receiverCMD.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(class_model
  "/home/dodo/LFtest/src/class_model/msg/FlightInformation.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/class_model
)
_generate_msg_cpp(class_model
  "/home/dodo/LFtest/src/class_model/msg/receiverCMD.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/class_model
)

### Generating Services

### Generating Module File
_generate_module_cpp(class_model
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/class_model
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(class_model_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(class_model_generate_messages class_model_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dodo/LFtest/src/class_model/msg/FlightInformation.msg" NAME_WE)
add_dependencies(class_model_generate_messages_cpp _class_model_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dodo/LFtest/src/class_model/msg/receiverCMD.msg" NAME_WE)
add_dependencies(class_model_generate_messages_cpp _class_model_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(class_model_gencpp)
add_dependencies(class_model_gencpp class_model_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS class_model_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(class_model
  "/home/dodo/LFtest/src/class_model/msg/FlightInformation.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/class_model
)
_generate_msg_eus(class_model
  "/home/dodo/LFtest/src/class_model/msg/receiverCMD.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/class_model
)

### Generating Services

### Generating Module File
_generate_module_eus(class_model
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/class_model
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(class_model_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(class_model_generate_messages class_model_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dodo/LFtest/src/class_model/msg/FlightInformation.msg" NAME_WE)
add_dependencies(class_model_generate_messages_eus _class_model_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dodo/LFtest/src/class_model/msg/receiverCMD.msg" NAME_WE)
add_dependencies(class_model_generate_messages_eus _class_model_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(class_model_geneus)
add_dependencies(class_model_geneus class_model_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS class_model_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(class_model
  "/home/dodo/LFtest/src/class_model/msg/FlightInformation.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/class_model
)
_generate_msg_lisp(class_model
  "/home/dodo/LFtest/src/class_model/msg/receiverCMD.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/class_model
)

### Generating Services

### Generating Module File
_generate_module_lisp(class_model
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/class_model
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(class_model_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(class_model_generate_messages class_model_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dodo/LFtest/src/class_model/msg/FlightInformation.msg" NAME_WE)
add_dependencies(class_model_generate_messages_lisp _class_model_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dodo/LFtest/src/class_model/msg/receiverCMD.msg" NAME_WE)
add_dependencies(class_model_generate_messages_lisp _class_model_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(class_model_genlisp)
add_dependencies(class_model_genlisp class_model_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS class_model_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(class_model
  "/home/dodo/LFtest/src/class_model/msg/FlightInformation.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/class_model
)
_generate_msg_nodejs(class_model
  "/home/dodo/LFtest/src/class_model/msg/receiverCMD.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/class_model
)

### Generating Services

### Generating Module File
_generate_module_nodejs(class_model
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/class_model
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(class_model_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(class_model_generate_messages class_model_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dodo/LFtest/src/class_model/msg/FlightInformation.msg" NAME_WE)
add_dependencies(class_model_generate_messages_nodejs _class_model_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dodo/LFtest/src/class_model/msg/receiverCMD.msg" NAME_WE)
add_dependencies(class_model_generate_messages_nodejs _class_model_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(class_model_gennodejs)
add_dependencies(class_model_gennodejs class_model_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS class_model_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(class_model
  "/home/dodo/LFtest/src/class_model/msg/FlightInformation.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/class_model
)
_generate_msg_py(class_model
  "/home/dodo/LFtest/src/class_model/msg/receiverCMD.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/class_model
)

### Generating Services

### Generating Module File
_generate_module_py(class_model
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/class_model
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(class_model_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(class_model_generate_messages class_model_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dodo/LFtest/src/class_model/msg/FlightInformation.msg" NAME_WE)
add_dependencies(class_model_generate_messages_py _class_model_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dodo/LFtest/src/class_model/msg/receiverCMD.msg" NAME_WE)
add_dependencies(class_model_generate_messages_py _class_model_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(class_model_genpy)
add_dependencies(class_model_genpy class_model_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS class_model_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/class_model)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/class_model
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/class_model)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/class_model
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/class_model)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/class_model
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/class_model)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/class_model
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/class_model)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/class_model\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/class_model
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
