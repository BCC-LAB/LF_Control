# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from class_model/FlightInformation.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class FlightInformation(genpy.Message):
  _md5sum = "fc743ed1ccbcb3c34c37472dd8dab444"
  _type = "class_model/FlightInformation"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """# FlightInformation.msg

# Custom GPS message
uint32 LAT
uint32 LON
uint32 ALT

# Flight information message
uint32 heading
"""
  __slots__ = ['LAT','LON','ALT','heading']
  _slot_types = ['uint32','uint32','uint32','uint32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       LAT,LON,ALT,heading

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(FlightInformation, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.LAT is None:
        self.LAT = 0
      if self.LON is None:
        self.LON = 0
      if self.ALT is None:
        self.ALT = 0
      if self.heading is None:
        self.heading = 0
    else:
      self.LAT = 0
      self.LON = 0
      self.ALT = 0
      self.heading = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_4I().pack(_x.LAT, _x.LON, _x.ALT, _x.heading))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 16
      (_x.LAT, _x.LON, _x.ALT, _x.heading,) = _get_struct_4I().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_4I().pack(_x.LAT, _x.LON, _x.ALT, _x.heading))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 16
      (_x.LAT, _x.LON, _x.ALT, _x.heading,) = _get_struct_4I().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_4I = None
def _get_struct_4I():
    global _struct_4I
    if _struct_4I is None:
        _struct_4I = struct.Struct("<4I")
    return _struct_4I
