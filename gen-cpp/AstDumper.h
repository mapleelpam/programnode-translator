/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
#ifndef AstDumper_H
#define AstDumper_H

#include <TProcessor.h>
#include "SyntaxTree_types.h"

namespace tw { namespace maple { namespace generated {

class AstDumperIf {
 public:
  virtual ~AstDumperIf() {}
  virtual void startProgram() = 0;
  virtual void endProgram() = 0;
  virtual void startPackage(const StringList& id) = 0;
  virtual void endPackage(const StringList& IDs) = 0;
  virtual void startExpressionList() = 0;
  virtual void startCallExpression(const CallExpression& call) = 0;
  virtual void startAgumentList() = 0;
  virtual void endAgumentList() = 0;
  virtual void endCallExpression() = 0;
  virtual void identifierExpression(const Identifier& id) = 0;
  virtual void endExpressionList() = 0;
  virtual void addImport(const StringList& packages) = 0;
  virtual void startStmtList() = 0;
  virtual void endStmtList() = 0;
  virtual void ping() = 0;
  virtual void ping2(const int32_t echo) = 0;
};

class AstDumperNull : virtual public AstDumperIf {
 public:
  virtual ~AstDumperNull() {}
  void startProgram() {
    return;
  }
  void endProgram() {
    return;
  }
  void startPackage(const StringList& /* id */) {
    return;
  }
  void endPackage(const StringList& /* IDs */) {
    return;
  }
  void startExpressionList() {
    return;
  }
  void startCallExpression(const CallExpression& /* call */) {
    return;
  }
  void startAgumentList() {
    return;
  }
  void endAgumentList() {
    return;
  }
  void endCallExpression() {
    return;
  }
  void identifierExpression(const Identifier& /* id */) {
    return;
  }
  void endExpressionList() {
    return;
  }
  void addImport(const StringList& /* packages */) {
    return;
  }
  void startStmtList() {
    return;
  }
  void endStmtList() {
    return;
  }
  void ping() {
    return;
  }
  void ping2(const int32_t /* echo */) {
    return;
  }
};


class AstDumper_startProgram_args {
 public:

  AstDumper_startProgram_args() {
  }

  virtual ~AstDumper_startProgram_args() throw() {}


  bool operator == (const AstDumper_startProgram_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const AstDumper_startProgram_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AstDumper_startProgram_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_startProgram_pargs {
 public:


  virtual ~AstDumper_startProgram_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_endProgram_args {
 public:

  AstDumper_endProgram_args() {
  }

  virtual ~AstDumper_endProgram_args() throw() {}


  bool operator == (const AstDumper_endProgram_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const AstDumper_endProgram_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AstDumper_endProgram_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_endProgram_pargs {
 public:


  virtual ~AstDumper_endProgram_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AstDumper_startPackage_args__isset {
  _AstDumper_startPackage_args__isset() : id(false) {}
  bool id;
} _AstDumper_startPackage_args__isset;

class AstDumper_startPackage_args {
 public:

  AstDumper_startPackage_args() {
  }

  virtual ~AstDumper_startPackage_args() throw() {}

  StringList id;

  _AstDumper_startPackage_args__isset __isset;

  bool operator == (const AstDumper_startPackage_args & rhs) const
  {
    if (!(id == rhs.id))
      return false;
    return true;
  }
  bool operator != (const AstDumper_startPackage_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AstDumper_startPackage_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_startPackage_pargs {
 public:


  virtual ~AstDumper_startPackage_pargs() throw() {}

  const StringList* id;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AstDumper_endPackage_args__isset {
  _AstDumper_endPackage_args__isset() : IDs(false) {}
  bool IDs;
} _AstDumper_endPackage_args__isset;

class AstDumper_endPackage_args {
 public:

  AstDumper_endPackage_args() {
  }

  virtual ~AstDumper_endPackage_args() throw() {}

  StringList IDs;

  _AstDumper_endPackage_args__isset __isset;

  bool operator == (const AstDumper_endPackage_args & rhs) const
  {
    if (!(IDs == rhs.IDs))
      return false;
    return true;
  }
  bool operator != (const AstDumper_endPackage_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AstDumper_endPackage_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_endPackage_pargs {
 public:


  virtual ~AstDumper_endPackage_pargs() throw() {}

  const StringList* IDs;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_startExpressionList_args {
 public:

  AstDumper_startExpressionList_args() {
  }

  virtual ~AstDumper_startExpressionList_args() throw() {}


  bool operator == (const AstDumper_startExpressionList_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const AstDumper_startExpressionList_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AstDumper_startExpressionList_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_startExpressionList_pargs {
 public:


  virtual ~AstDumper_startExpressionList_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AstDumper_startCallExpression_args__isset {
  _AstDumper_startCallExpression_args__isset() : call(false) {}
  bool call;
} _AstDumper_startCallExpression_args__isset;

class AstDumper_startCallExpression_args {
 public:

  AstDumper_startCallExpression_args() {
  }

  virtual ~AstDumper_startCallExpression_args() throw() {}

  CallExpression call;

  _AstDumper_startCallExpression_args__isset __isset;

  bool operator == (const AstDumper_startCallExpression_args & rhs) const
  {
    if (!(call == rhs.call))
      return false;
    return true;
  }
  bool operator != (const AstDumper_startCallExpression_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AstDumper_startCallExpression_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_startCallExpression_pargs {
 public:


  virtual ~AstDumper_startCallExpression_pargs() throw() {}

  const CallExpression* call;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_startAgumentList_args {
 public:

  AstDumper_startAgumentList_args() {
  }

  virtual ~AstDumper_startAgumentList_args() throw() {}


  bool operator == (const AstDumper_startAgumentList_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const AstDumper_startAgumentList_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AstDumper_startAgumentList_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_startAgumentList_pargs {
 public:


  virtual ~AstDumper_startAgumentList_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_endAgumentList_args {
 public:

  AstDumper_endAgumentList_args() {
  }

  virtual ~AstDumper_endAgumentList_args() throw() {}


  bool operator == (const AstDumper_endAgumentList_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const AstDumper_endAgumentList_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AstDumper_endAgumentList_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_endAgumentList_pargs {
 public:


  virtual ~AstDumper_endAgumentList_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_endCallExpression_args {
 public:

  AstDumper_endCallExpression_args() {
  }

  virtual ~AstDumper_endCallExpression_args() throw() {}


  bool operator == (const AstDumper_endCallExpression_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const AstDumper_endCallExpression_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AstDumper_endCallExpression_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_endCallExpression_pargs {
 public:


  virtual ~AstDumper_endCallExpression_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AstDumper_identifierExpression_args__isset {
  _AstDumper_identifierExpression_args__isset() : id(false) {}
  bool id;
} _AstDumper_identifierExpression_args__isset;

class AstDumper_identifierExpression_args {
 public:

  AstDumper_identifierExpression_args() {
  }

  virtual ~AstDumper_identifierExpression_args() throw() {}

  Identifier id;

  _AstDumper_identifierExpression_args__isset __isset;

  bool operator == (const AstDumper_identifierExpression_args & rhs) const
  {
    if (!(id == rhs.id))
      return false;
    return true;
  }
  bool operator != (const AstDumper_identifierExpression_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AstDumper_identifierExpression_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_identifierExpression_pargs {
 public:


  virtual ~AstDumper_identifierExpression_pargs() throw() {}

  const Identifier* id;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_endExpressionList_args {
 public:

  AstDumper_endExpressionList_args() {
  }

  virtual ~AstDumper_endExpressionList_args() throw() {}


  bool operator == (const AstDumper_endExpressionList_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const AstDumper_endExpressionList_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AstDumper_endExpressionList_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_endExpressionList_pargs {
 public:


  virtual ~AstDumper_endExpressionList_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AstDumper_addImport_args__isset {
  _AstDumper_addImport_args__isset() : packages(false) {}
  bool packages;
} _AstDumper_addImport_args__isset;

class AstDumper_addImport_args {
 public:

  AstDumper_addImport_args() {
  }

  virtual ~AstDumper_addImport_args() throw() {}

  StringList packages;

  _AstDumper_addImport_args__isset __isset;

  bool operator == (const AstDumper_addImport_args & rhs) const
  {
    if (!(packages == rhs.packages))
      return false;
    return true;
  }
  bool operator != (const AstDumper_addImport_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AstDumper_addImport_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_addImport_pargs {
 public:


  virtual ~AstDumper_addImport_pargs() throw() {}

  const StringList* packages;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_startStmtList_args {
 public:

  AstDumper_startStmtList_args() {
  }

  virtual ~AstDumper_startStmtList_args() throw() {}


  bool operator == (const AstDumper_startStmtList_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const AstDumper_startStmtList_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AstDumper_startStmtList_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_startStmtList_pargs {
 public:


  virtual ~AstDumper_startStmtList_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_endStmtList_args {
 public:

  AstDumper_endStmtList_args() {
  }

  virtual ~AstDumper_endStmtList_args() throw() {}


  bool operator == (const AstDumper_endStmtList_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const AstDumper_endStmtList_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AstDumper_endStmtList_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_endStmtList_pargs {
 public:


  virtual ~AstDumper_endStmtList_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_ping_args {
 public:

  AstDumper_ping_args() {
  }

  virtual ~AstDumper_ping_args() throw() {}


  bool operator == (const AstDumper_ping_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const AstDumper_ping_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AstDumper_ping_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_ping_pargs {
 public:


  virtual ~AstDumper_ping_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AstDumper_ping2_args__isset {
  _AstDumper_ping2_args__isset() : echo(false) {}
  bool echo;
} _AstDumper_ping2_args__isset;

class AstDumper_ping2_args {
 public:

  AstDumper_ping2_args() : echo(0) {
  }

  virtual ~AstDumper_ping2_args() throw() {}

  int32_t echo;

  _AstDumper_ping2_args__isset __isset;

  bool operator == (const AstDumper_ping2_args & rhs) const
  {
    if (!(echo == rhs.echo))
      return false;
    return true;
  }
  bool operator != (const AstDumper_ping2_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AstDumper_ping2_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AstDumper_ping2_pargs {
 public:


  virtual ~AstDumper_ping2_pargs() throw() {}

  const int32_t* echo;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

class AstDumperClient : virtual public AstDumperIf {
 public:
  AstDumperClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  AstDumperClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void startProgram();
  void send_startProgram();
  void endProgram();
  void send_endProgram();
  void startPackage(const StringList& id);
  void send_startPackage(const StringList& id);
  void endPackage(const StringList& IDs);
  void send_endPackage(const StringList& IDs);
  void startExpressionList();
  void send_startExpressionList();
  void startCallExpression(const CallExpression& call);
  void send_startCallExpression(const CallExpression& call);
  void startAgumentList();
  void send_startAgumentList();
  void endAgumentList();
  void send_endAgumentList();
  void endCallExpression();
  void send_endCallExpression();
  void identifierExpression(const Identifier& id);
  void send_identifierExpression(const Identifier& id);
  void endExpressionList();
  void send_endExpressionList();
  void addImport(const StringList& packages);
  void send_addImport(const StringList& packages);
  void startStmtList();
  void send_startStmtList();
  void endStmtList();
  void send_endStmtList();
  void ping();
  void send_ping();
  void ping2(const int32_t echo);
  void send_ping2(const int32_t echo);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class AstDumperProcessor : virtual public ::apache::thrift::TProcessor {
 protected:
  boost::shared_ptr<AstDumperIf> iface_;
  virtual bool process_fn(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, std::string& fname, int32_t seqid, void* callContext);
 private:
  std::map<std::string, void (AstDumperProcessor::*)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*)> processMap_;
  void process_startProgram(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_endProgram(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_startPackage(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_endPackage(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_startExpressionList(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_startCallExpression(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_startAgumentList(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_endAgumentList(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_endCallExpression(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_identifierExpression(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_endExpressionList(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_addImport(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_startStmtList(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_endStmtList(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_ping(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_ping2(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  AstDumperProcessor(boost::shared_ptr<AstDumperIf> iface) :
    iface_(iface) {
    processMap_["startProgram"] = &AstDumperProcessor::process_startProgram;
    processMap_["endProgram"] = &AstDumperProcessor::process_endProgram;
    processMap_["startPackage"] = &AstDumperProcessor::process_startPackage;
    processMap_["endPackage"] = &AstDumperProcessor::process_endPackage;
    processMap_["startExpressionList"] = &AstDumperProcessor::process_startExpressionList;
    processMap_["startCallExpression"] = &AstDumperProcessor::process_startCallExpression;
    processMap_["startAgumentList"] = &AstDumperProcessor::process_startAgumentList;
    processMap_["endAgumentList"] = &AstDumperProcessor::process_endAgumentList;
    processMap_["endCallExpression"] = &AstDumperProcessor::process_endCallExpression;
    processMap_["identifierExpression"] = &AstDumperProcessor::process_identifierExpression;
    processMap_["endExpressionList"] = &AstDumperProcessor::process_endExpressionList;
    processMap_["addImport"] = &AstDumperProcessor::process_addImport;
    processMap_["startStmtList"] = &AstDumperProcessor::process_startStmtList;
    processMap_["endStmtList"] = &AstDumperProcessor::process_endStmtList;
    processMap_["ping"] = &AstDumperProcessor::process_ping;
    processMap_["ping2"] = &AstDumperProcessor::process_ping2;
  }

  virtual bool process(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot, void* callContext);
  virtual ~AstDumperProcessor() {}
};

class AstDumperMultiface : virtual public AstDumperIf {
 public:
  AstDumperMultiface(std::vector<boost::shared_ptr<AstDumperIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~AstDumperMultiface() {}
 protected:
  std::vector<boost::shared_ptr<AstDumperIf> > ifaces_;
  AstDumperMultiface() {}
  void add(boost::shared_ptr<AstDumperIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void startProgram() {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->startProgram();
    }
  }

  void endProgram() {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->endProgram();
    }
  }

  void startPackage(const StringList& id) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->startPackage(id);
    }
  }

  void endPackage(const StringList& IDs) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->endPackage(IDs);
    }
  }

  void startExpressionList() {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->startExpressionList();
    }
  }

  void startCallExpression(const CallExpression& call) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->startCallExpression(call);
    }
  }

  void startAgumentList() {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->startAgumentList();
    }
  }

  void endAgumentList() {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->endAgumentList();
    }
  }

  void endCallExpression() {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->endCallExpression();
    }
  }

  void identifierExpression(const Identifier& id) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->identifierExpression(id);
    }
  }

  void endExpressionList() {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->endExpressionList();
    }
  }

  void addImport(const StringList& packages) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->addImport(packages);
    }
  }

  void startStmtList() {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->startStmtList();
    }
  }

  void endStmtList() {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->endStmtList();
    }
  }

  void ping() {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->ping();
    }
  }

  void ping2(const int32_t echo) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->ping2(echo);
    }
  }

};

}}} // namespace

#endif
