// Generated by gencpp from file class_model/FlightInformation.msg
// DO NOT EDIT!


#ifndef CLASS_MODEL_MESSAGE_FLIGHTINFORMATION_H
#define CLASS_MODEL_MESSAGE_FLIGHTINFORMATION_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace class_model
{
template <class ContainerAllocator>
struct FlightInformation_
{
  typedef FlightInformation_<ContainerAllocator> Type;

  FlightInformation_()
    : LAT(0)
    , LON(0)
    , ALT(0)
    , heading(0)  {
    }
  FlightInformation_(const ContainerAllocator& _alloc)
    : LAT(0)
    , LON(0)
    , ALT(0)
    , heading(0)  {
  (void)_alloc;
    }



   typedef uint32_t _LAT_type;
  _LAT_type LAT;

   typedef uint32_t _LON_type;
  _LON_type LON;

   typedef uint32_t _ALT_type;
  _ALT_type ALT;

   typedef uint32_t _heading_type;
  _heading_type heading;





  typedef boost::shared_ptr< ::class_model::FlightInformation_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::class_model::FlightInformation_<ContainerAllocator> const> ConstPtr;

}; // struct FlightInformation_

typedef ::class_model::FlightInformation_<std::allocator<void> > FlightInformation;

typedef boost::shared_ptr< ::class_model::FlightInformation > FlightInformationPtr;
typedef boost::shared_ptr< ::class_model::FlightInformation const> FlightInformationConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::class_model::FlightInformation_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::class_model::FlightInformation_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::class_model::FlightInformation_<ContainerAllocator1> & lhs, const ::class_model::FlightInformation_<ContainerAllocator2> & rhs)
{
  return lhs.LAT == rhs.LAT &&
    lhs.LON == rhs.LON &&
    lhs.ALT == rhs.ALT &&
    lhs.heading == rhs.heading;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::class_model::FlightInformation_<ContainerAllocator1> & lhs, const ::class_model::FlightInformation_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace class_model

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::class_model::FlightInformation_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::class_model::FlightInformation_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::class_model::FlightInformation_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::class_model::FlightInformation_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::class_model::FlightInformation_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::class_model::FlightInformation_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::class_model::FlightInformation_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fc743ed1ccbcb3c34c37472dd8dab444";
  }

  static const char* value(const ::class_model::FlightInformation_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xfc743ed1ccbcb3c3ULL;
  static const uint64_t static_value2 = 0x4c37472dd8dab444ULL;
};

template<class ContainerAllocator>
struct DataType< ::class_model::FlightInformation_<ContainerAllocator> >
{
  static const char* value()
  {
    return "class_model/FlightInformation";
  }

  static const char* value(const ::class_model::FlightInformation_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::class_model::FlightInformation_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# FlightInformation.msg\n"
"\n"
"# Custom GPS message\n"
"uint32 LAT\n"
"uint32 LON\n"
"uint32 ALT\n"
"\n"
"# Flight information message\n"
"uint32 heading\n"
;
  }

  static const char* value(const ::class_model::FlightInformation_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::class_model::FlightInformation_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.LAT);
      stream.next(m.LON);
      stream.next(m.ALT);
      stream.next(m.heading);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct FlightInformation_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::class_model::FlightInformation_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::class_model::FlightInformation_<ContainerAllocator>& v)
  {
    s << indent << "LAT: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.LAT);
    s << indent << "LON: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.LON);
    s << indent << "ALT: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.ALT);
    s << indent << "heading: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.heading);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CLASS_MODEL_MESSAGE_FLIGHTINFORMATION_H