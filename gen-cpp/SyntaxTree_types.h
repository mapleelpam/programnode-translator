/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
#ifndef SyntaxTree_TYPES_H
#define SyntaxTree_TYPES_H

#include <Thrift.h>
#include <TApplicationException.h>
#include <protocol/TProtocol.h>
#include <transport/TTransport.h>



namespace tw { namespace maple { namespace generated {

struct ExpressionType {
  enum type {
    IDENTIFIER = 0,
    CALL = 1
  };
};

extern const std::map<int, const char*> _ExpressionType_VALUES_TO_NAMES;

struct IdentifierType {
  enum type {
    TYPE_IDENTIFIER = 0,
    ATTR_IDENTIFIER = 1,
    IDENTIFIER = 2
  };
};

extern const std::map<int, const char*> _IdentifierType_VALUES_TO_NAMES;

struct ObjectType {
  enum type {
    TYPE_CLASS = 0,
    TYPE_INTERFACE = 1
  };
};

extern const std::map<int, const char*> _ObjectType_VALUES_TO_NAMES;

struct FunctionType {
  enum type {
    TF_NORMAL = 0,
    TF_GETTER = 1,
    TF_SETTER = 2
  };
};

extern const std::map<int, const char*> _FunctionType_VALUES_TO_NAMES;

typedef struct _Identifier__isset {
  _Identifier__isset() : type(false), name(false), qualifier(false) {}
  bool type;
  bool name;
  bool qualifier;
} _Identifier__isset;

class Identifier {
 public:

  static const char* ascii_fingerprint; // = "38C252E94E93B69D04EB3A6EE2F9EDFB";
  static const uint8_t binary_fingerprint[16]; // = {0x38,0xC2,0x52,0xE9,0x4E,0x93,0xB6,0x9D,0x04,0xEB,0x3A,0x6E,0xE2,0xF9,0xED,0xFB};

  Identifier() : name(""), qualifier("") {
  }

  virtual ~Identifier() throw() {}

  IdentifierType::type type;
  std::string name;
  std::string qualifier;

  _Identifier__isset __isset;

  bool operator == (const Identifier & rhs) const
  {
    if (!(type == rhs.type))
      return false;
    if (!(name == rhs.name))
      return false;
    if (!(qualifier == rhs.qualifier))
      return false;
    return true;
  }
  bool operator != (const Identifier &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Identifier & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Literal__isset {
  _Literal__isset() : value(false) {}
  bool value;
} _Literal__isset;

class Literal {
 public:

  static const char* ascii_fingerprint; // = "3E312230276B1228199AAA0AF12FDB38";
  static const uint8_t binary_fingerprint[16]; // = {0x3E,0x31,0x22,0x30,0x27,0x6B,0x12,0x28,0x19,0x9A,0xAA,0x0A,0xF1,0x2F,0xDB,0x38};

  Literal() : value("") {
  }

  virtual ~Literal() throw() {}

  std::string value;

  _Literal__isset __isset;

  bool operator == (const Literal & rhs) const
  {
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const Literal &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Literal & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _CallExpression__isset {
  _CallExpression__isset() : is_new(false), mode(false), callee(false) {}
  bool is_new;
  bool mode;
  bool callee;
} _CallExpression__isset;

class CallExpression {
 public:

  static const char* ascii_fingerprint; // = "9A7EA49D8DFC35C9972B3D9DD14CEAC5";
  static const uint8_t binary_fingerprint[16]; // = {0x9A,0x7E,0xA4,0x9D,0x8D,0xFC,0x35,0xC9,0x97,0x2B,0x3D,0x9D,0xD1,0x4C,0xEA,0xC5};

  CallExpression() : is_new(false), mode("") {
  }

  virtual ~CallExpression() throw() {}

  bool is_new;
  std::string mode;
  std::vector<std::string>  callee;

  _CallExpression__isset __isset;

  bool operator == (const CallExpression & rhs) const
  {
    if (!(is_new == rhs.is_new))
      return false;
    if (!(mode == rhs.mode))
      return false;
    if (!(callee == rhs.callee))
      return false;
    return true;
  }
  bool operator != (const CallExpression &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CallExpression & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClassDefinition__isset {
  _ClassDefinition__isset() : name(false), has_attr(false), has_baseclass(false), has_interface(false), has_stmt(false), inherits(false), interfaces(false), object_type(false), attributes(false) {}
  bool name;
  bool has_attr;
  bool has_baseclass;
  bool has_interface;
  bool has_stmt;
  bool inherits;
  bool interfaces;
  bool object_type;
  bool attributes;
} _ClassDefinition__isset;

class ClassDefinition {
 public:

  static const char* ascii_fingerprint; // = "5C27C1EA118BDBA39668DBAC0C1B134F";
  static const uint8_t binary_fingerprint[16]; // = {0x5C,0x27,0xC1,0xEA,0x11,0x8B,0xDB,0xA3,0x96,0x68,0xDB,0xAC,0x0C,0x1B,0x13,0x4F};

  ClassDefinition() : name(""), has_attr(0), has_baseclass(0), has_interface(0), has_stmt(0) {
  }

  virtual ~ClassDefinition() throw() {}

  std::string name;
  bool has_attr;
  bool has_baseclass;
  bool has_interface;
  bool has_stmt;
  std::vector<std::string>  inherits;
  std::vector<std::string>  interfaces;
  ObjectType::type object_type;
  std::vector<std::string>  attributes;

  _ClassDefinition__isset __isset;

  bool operator == (const ClassDefinition & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(has_attr == rhs.has_attr))
      return false;
    if (!(has_baseclass == rhs.has_baseclass))
      return false;
    if (!(has_interface == rhs.has_interface))
      return false;
    if (!(has_stmt == rhs.has_stmt))
      return false;
    if (!(inherits == rhs.inherits))
      return false;
    if (!(interfaces == rhs.interfaces))
      return false;
    if (!(object_type == rhs.object_type))
      return false;
    if (!(attributes == rhs.attributes))
      return false;
    return true;
  }
  bool operator != (const ClassDefinition &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClassDefinition & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _MetaData__isset {
  _MetaData__isset() : id(false), keyvalues(false), values(false) {}
  bool id;
  bool keyvalues;
  bool values;
} _MetaData__isset;

class MetaData {
 public:

  static const char* ascii_fingerprint; // = "11FD4C7541350B1F99928E3475DD29B4";
  static const uint8_t binary_fingerprint[16]; // = {0x11,0xFD,0x4C,0x75,0x41,0x35,0x0B,0x1F,0x99,0x92,0x8E,0x34,0x75,0xDD,0x29,0xB4};

  MetaData() : id("") {
  }

  virtual ~MetaData() throw() {}

  std::string id;
  std::map<std::string, std::string>  keyvalues;
  std::vector<std::string>  values;

  _MetaData__isset __isset;

  bool operator == (const MetaData & rhs) const
  {
    if (!(id == rhs.id))
      return false;
    if (!(keyvalues == rhs.keyvalues))
      return false;
    if (!(values == rhs.values))
      return false;
    return true;
  }
  bool operator != (const MetaData &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MetaData & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _VariableDeclare__isset {
  _VariableDeclare__isset() : name(false), type(false), attributes(false), has_initialize(false) {}
  bool name;
  bool type;
  bool attributes;
  bool has_initialize;
} _VariableDeclare__isset;

class VariableDeclare {
 public:

  static const char* ascii_fingerprint; // = "246E3DA277034CB0FF77EE09B6CC4A7B";
  static const uint8_t binary_fingerprint[16]; // = {0x24,0x6E,0x3D,0xA2,0x77,0x03,0x4C,0xB0,0xFF,0x77,0xEE,0x09,0xB6,0xCC,0x4A,0x7B};

  VariableDeclare() : name(""), has_initialize(0) {
  }

  virtual ~VariableDeclare() throw() {}

  std::string name;
  std::vector<std::string>  type;
  std::vector<std::string>  attributes;
  bool has_initialize;

  _VariableDeclare__isset __isset;

  bool operator == (const VariableDeclare & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(type == rhs.type))
      return false;
    if (!(attributes == rhs.attributes))
      return false;
    if (!(has_initialize == rhs.has_initialize))
      return false;
    return true;
  }
  bool operator != (const VariableDeclare &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const VariableDeclare & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _BinaryExpression__isset {
  _BinaryExpression__isset() : op(false) {}
  bool op;
} _BinaryExpression__isset;

class BinaryExpression {
 public:

  static const char* ascii_fingerprint; // = "EFB929595D312AC8F305D5A794CFEDA1";
  static const uint8_t binary_fingerprint[16]; // = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};

  BinaryExpression() : op("") {
  }

  virtual ~BinaryExpression() throw() {}

  std::string op;

  _BinaryExpression__isset __isset;

  bool operator == (const BinaryExpression & rhs) const
  {
    if (!(op == rhs.op))
      return false;
    return true;
  }
  bool operator != (const BinaryExpression &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const BinaryExpression & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UnaryExpression__isset {
  _UnaryExpression__isset() : op(false) {}
  bool op;
} _UnaryExpression__isset;

class UnaryExpression {
 public:

  static const char* ascii_fingerprint; // = "EFB929595D312AC8F305D5A794CFEDA1";
  static const uint8_t binary_fingerprint[16]; // = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};

  UnaryExpression() : op("") {
  }

  virtual ~UnaryExpression() throw() {}

  std::string op;

  _UnaryExpression__isset __isset;

  bool operator == (const UnaryExpression & rhs) const
  {
    if (!(op == rhs.op))
      return false;
    return true;
  }
  bool operator != (const UnaryExpression &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UnaryExpression & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

}}} // namespace

#endif
