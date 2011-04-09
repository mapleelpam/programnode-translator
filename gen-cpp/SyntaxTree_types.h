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

typedef std::vector<std::string>  StringList;

typedef struct _Identifier__isset {
  _Identifier__isset() : type(false), name(false) {}
  bool type;
  bool name;
} _Identifier__isset;

class Identifier {
 public:

  static const char* ascii_fingerprint; // = "19B5240589E680301A7E32DF3971EFBE";
  static const uint8_t binary_fingerprint[16]; // = {0x19,0xB5,0x24,0x05,0x89,0xE6,0x80,0x30,0x1A,0x7E,0x32,0xDF,0x39,0x71,0xEF,0xBE};

  Identifier() : name("") {
  }

  virtual ~Identifier() throw() {}

  IdentifierType::type type;
  std::string name;

  _Identifier__isset __isset;

  bool operator == (const Identifier & rhs) const
  {
    if (!(type == rhs.type))
      return false;
    if (!(name == rhs.name))
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
  _CallExpression__isset() : is_new(false) {}
  bool is_new;
} _CallExpression__isset;

class CallExpression {
 public:

  static const char* ascii_fingerprint; // = "5892306F7B861249AE8E27C8ED619593";
  static const uint8_t binary_fingerprint[16]; // = {0x58,0x92,0x30,0x6F,0x7B,0x86,0x12,0x49,0xAE,0x8E,0x27,0xC8,0xED,0x61,0x95,0x93};

  CallExpression() : is_new(false) {
  }

  virtual ~CallExpression() throw() {}

  bool is_new;

  _CallExpression__isset __isset;

  bool operator == (const CallExpression & rhs) const
  {
    if (!(is_new == rhs.is_new))
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