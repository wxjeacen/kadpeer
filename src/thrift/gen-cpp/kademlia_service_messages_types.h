/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
#ifndef kademlia_service_messages_TYPES_H
#define kademlia_service_messages_TYPES_H

#include <Thrift.h>
#include <TApplicationException.h>
#include <protocol/TProtocol.h>
#include <transport/TTransport.h>

#include "contact_info_types.h"
#include "signed_kadvalue_types.h"


namespace kad {

typedef struct _PingRequest__isset {
  _PingRequest__isset() : ping(false), sender_info(false) {}
  bool ping;
  bool sender_info;
} _PingRequest__isset;

class PingRequest {
 public:

  static const char* ascii_fingerprint; // = "B124875FD2E410C9174324EBC9B5D6CF";
  static const uint8_t binary_fingerprint[16]; // = {0xB1,0x24,0x87,0x5F,0xD2,0xE4,0x10,0xC9,0x17,0x43,0x24,0xEB,0xC9,0xB5,0xD6,0xCF};

  PingRequest() : ping("") {
  }

  virtual ~PingRequest() throw() {}

  std::string ping;
  kad::ContactInfo sender_info;

  _PingRequest__isset __isset;

  bool operator == (const PingRequest & rhs) const
  {
    if (!(ping == rhs.ping))
      return false;
    if (!(sender_info == rhs.sender_info))
      return false;
    return true;
  }
  bool operator != (const PingRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PingRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _PingResponse__isset {
  _PingResponse__isset() : result(false), echo(false), node_id(false) {}
  bool result;
  bool echo;
  bool node_id;
} _PingResponse__isset;

class PingResponse {
 public:

  static const char* ascii_fingerprint; // = "4BF81DD46A7371532E49811022D58D36";
  static const uint8_t binary_fingerprint[16]; // = {0x4B,0xF8,0x1D,0xD4,0x6A,0x73,0x71,0x53,0x2E,0x49,0x81,0x10,0x22,0xD5,0x8D,0x36};

  PingResponse() : result(""), echo(""), node_id("") {
  }

  virtual ~PingResponse() throw() {}

  std::string result;
  std::string echo;
  std::string node_id;

  _PingResponse__isset __isset;

  bool operator == (const PingResponse & rhs) const
  {
    if (!(result == rhs.result))
      return false;
    if (__isset.echo != rhs.__isset.echo)
      return false;
    else if (__isset.echo && !(echo == rhs.echo))
      return false;
    if (__isset.node_id != rhs.__isset.node_id)
      return false;
    else if (__isset.node_id && !(node_id == rhs.node_id))
      return false;
    return true;
  }
  bool operator != (const PingResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PingResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FindRequest__isset {
  _FindRequest__isset() : key(false), sender_info(false), is_boostrap(false), sender_ext_ip(false), sender_ext_port(false) {}
  bool key;
  bool sender_info;
  bool is_boostrap;
  bool sender_ext_ip;
  bool sender_ext_port;
} _FindRequest__isset;

class FindRequest {
 public:

  static const char* ascii_fingerprint; // = "A5716409383E885C499DCC0AAF853BF5";
  static const uint8_t binary_fingerprint[16]; // = {0xA5,0x71,0x64,0x09,0x38,0x3E,0x88,0x5C,0x49,0x9D,0xCC,0x0A,0xAF,0x85,0x3B,0xF5};

  FindRequest() : key(""), is_boostrap(0), sender_ext_ip(""), sender_ext_port(0) {
  }

  virtual ~FindRequest() throw() {}

  std::string key;
  kad::ContactInfo sender_info;
  bool is_boostrap;
  std::string sender_ext_ip;
  int32_t sender_ext_port;

  _FindRequest__isset __isset;

  bool operator == (const FindRequest & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    if (!(sender_info == rhs.sender_info))
      return false;
    if (__isset.is_boostrap != rhs.__isset.is_boostrap)
      return false;
    else if (__isset.is_boostrap && !(is_boostrap == rhs.is_boostrap))
      return false;
    if (__isset.sender_ext_ip != rhs.__isset.sender_ext_ip)
      return false;
    else if (__isset.sender_ext_ip && !(sender_ext_ip == rhs.sender_ext_ip))
      return false;
    if (__isset.sender_ext_port != rhs.__isset.sender_ext_port)
      return false;
    else if (__isset.sender_ext_port && !(sender_ext_port == rhs.sender_ext_port))
      return false;
    return true;
  }
  bool operator != (const FindRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FindRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FindResponse__isset {
  _FindResponse__isset() : result(false), closest_nodes(false), values(false), signed_values(false), alternative_value_holder(false), needs_cache_copy(false), requester_ext_addr(false), node_id(false) {}
  bool result;
  bool closest_nodes;
  bool values;
  bool signed_values;
  bool alternative_value_holder;
  bool needs_cache_copy;
  bool requester_ext_addr;
  bool node_id;
} _FindResponse__isset;

class FindResponse {
 public:

  static const char* ascii_fingerprint; // = "0B33A1108B56325B1B13DADA6E7C51A3";
  static const uint8_t binary_fingerprint[16]; // = {0x0B,0x33,0xA1,0x10,0x8B,0x56,0x32,0x5B,0x1B,0x13,0xDA,0xDA,0x6E,0x7C,0x51,0xA3};

  FindResponse() : result(""), needs_cache_copy(""), requester_ext_addr(""), node_id("") {
  }

  virtual ~FindResponse() throw() {}

  std::string result;
  std::vector<kad::ContactInfo>  closest_nodes;
  std::vector<std::string>  values;
  std::vector<kad::SignedValue>  signed_values;
  kad::ContactInfo alternative_value_holder;
  std::string needs_cache_copy;
  std::string requester_ext_addr;
  std::string node_id;

  _FindResponse__isset __isset;

  bool operator == (const FindResponse & rhs) const
  {
    if (!(result == rhs.result))
      return false;
    if (!(closest_nodes == rhs.closest_nodes))
      return false;
    if (!(values == rhs.values))
      return false;
    if (!(signed_values == rhs.signed_values))
      return false;
    if (__isset.alternative_value_holder != rhs.__isset.alternative_value_holder)
      return false;
    else if (__isset.alternative_value_holder && !(alternative_value_holder == rhs.alternative_value_holder))
      return false;
    if (__isset.needs_cache_copy != rhs.__isset.needs_cache_copy)
      return false;
    else if (__isset.needs_cache_copy && !(needs_cache_copy == rhs.needs_cache_copy))
      return false;
    if (__isset.requester_ext_addr != rhs.__isset.requester_ext_addr)
      return false;
    else if (__isset.requester_ext_addr && !(requester_ext_addr == rhs.requester_ext_addr))
      return false;
    if (__isset.node_id != rhs.__isset.node_id)
      return false;
    else if (__isset.node_id && !(node_id == rhs.node_id))
      return false;
    return true;
  }
  bool operator != (const FindResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FindResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FindNodeResult__isset {
  _FindNodeResult__isset() : result(false), contact(false), node_id(false) {}
  bool result;
  bool contact;
  bool node_id;
} _FindNodeResult__isset;

class FindNodeResult {
 public:

  static const char* ascii_fingerprint; // = "4BF81DD46A7371532E49811022D58D36";
  static const uint8_t binary_fingerprint[16]; // = {0x4B,0xF8,0x1D,0xD4,0x6A,0x73,0x71,0x53,0x2E,0x49,0x81,0x10,0x22,0xD5,0x8D,0x36};

  FindNodeResult() : result(""), contact(""), node_id("") {
  }

  virtual ~FindNodeResult() throw() {}

  std::string result;
  std::string contact;
  std::string node_id;

  _FindNodeResult__isset __isset;

  bool operator == (const FindNodeResult & rhs) const
  {
    if (!(result == rhs.result))
      return false;
    if (__isset.contact != rhs.__isset.contact)
      return false;
    else if (__isset.contact && !(contact == rhs.contact))
      return false;
    if (__isset.node_id != rhs.__isset.node_id)
      return false;
    else if (__isset.node_id && !(node_id == rhs.node_id))
      return false;
    return true;
  }
  bool operator != (const FindNodeResult &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FindNodeResult & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _StoreRequest__isset {
  _StoreRequest__isset() : key(false), value(false), sig_value(false), ttl(false), sender_info(false), publish(false), signed_request(false) {}
  bool key;
  bool value;
  bool sig_value;
  bool ttl;
  bool sender_info;
  bool publish;
  bool signed_request;
} _StoreRequest__isset;

class StoreRequest {
 public:

  static const char* ascii_fingerprint; // = "0C6EB76C444807DF8546533B5AE87125";
  static const uint8_t binary_fingerprint[16]; // = {0x0C,0x6E,0xB7,0x6C,0x44,0x48,0x07,0xDF,0x85,0x46,0x53,0x3B,0x5A,0xE8,0x71,0x25};

  StoreRequest() : key(""), value(""), ttl(0), publish(0) {
  }

  virtual ~StoreRequest() throw() {}

  std::string key;
  std::string value;
  kad::SignedValue sig_value;
  int32_t ttl;
  kad::ContactInfo sender_info;
  bool publish;
  kad::SignedRequest signed_request;

  _StoreRequest__isset __isset;

  bool operator == (const StoreRequest & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    if (__isset.value != rhs.__isset.value)
      return false;
    else if (__isset.value && !(value == rhs.value))
      return false;
    if (__isset.sig_value != rhs.__isset.sig_value)
      return false;
    else if (__isset.sig_value && !(sig_value == rhs.sig_value))
      return false;
    if (!(ttl == rhs.ttl))
      return false;
    if (!(sender_info == rhs.sender_info))
      return false;
    if (!(publish == rhs.publish))
      return false;
    if (__isset.signed_request != rhs.__isset.signed_request)
      return false;
    else if (__isset.signed_request && !(signed_request == rhs.signed_request))
      return false;
    return true;
  }
  bool operator != (const StoreRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const StoreRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _StoreResponse__isset {
  _StoreResponse__isset() : result(false), node_id(false), signed_request(false) {}
  bool result;
  bool node_id;
  bool signed_request;
} _StoreResponse__isset;

class StoreResponse {
 public:

  static const char* ascii_fingerprint; // = "4599D2A22DAAC6D75396642A6A886FAE";
  static const uint8_t binary_fingerprint[16]; // = {0x45,0x99,0xD2,0xA2,0x2D,0xAA,0xC6,0xD7,0x53,0x96,0x64,0x2A,0x6A,0x88,0x6F,0xAE};

  StoreResponse() : result(""), node_id("") {
  }

  virtual ~StoreResponse() throw() {}

  std::string result;
  std::string node_id;
  kad::SignedRequest signed_request;

  _StoreResponse__isset __isset;

  bool operator == (const StoreResponse & rhs) const
  {
    if (!(result == rhs.result))
      return false;
    if (__isset.node_id != rhs.__isset.node_id)
      return false;
    else if (__isset.node_id && !(node_id == rhs.node_id))
      return false;
    if (__isset.signed_request != rhs.__isset.signed_request)
      return false;
    else if (__isset.signed_request && !(signed_request == rhs.signed_request))
      return false;
    return true;
  }
  bool operator != (const StoreResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const StoreResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DownlistRequest__isset {
  _DownlistRequest__isset() : downlist(false), sender_info(false) {}
  bool downlist;
  bool sender_info;
} _DownlistRequest__isset;

class DownlistRequest {
 public:

  static const char* ascii_fingerprint; // = "057BE37F71643E0F152B9B3CD12EEE01";
  static const uint8_t binary_fingerprint[16]; // = {0x05,0x7B,0xE3,0x7F,0x71,0x64,0x3E,0x0F,0x15,0x2B,0x9B,0x3C,0xD1,0x2E,0xEE,0x01};

  DownlistRequest() {
  }

  virtual ~DownlistRequest() throw() {}

  std::vector<kad::ContactInfo>  downlist;
  kad::ContactInfo sender_info;

  _DownlistRequest__isset __isset;

  bool operator == (const DownlistRequest & rhs) const
  {
    if (!(downlist == rhs.downlist))
      return false;
    if (!(sender_info == rhs.sender_info))
      return false;
    return true;
  }
  bool operator != (const DownlistRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DownlistRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DownlistResponse__isset {
  _DownlistResponse__isset() : result(false), node_id(false) {}
  bool result;
  bool node_id;
} _DownlistResponse__isset;

class DownlistResponse {
 public:

  static const char* ascii_fingerprint; // = "5B708A954C550ECA9C1A49D3C5CAFAB9";
  static const uint8_t binary_fingerprint[16]; // = {0x5B,0x70,0x8A,0x95,0x4C,0x55,0x0E,0xCA,0x9C,0x1A,0x49,0xD3,0xC5,0xCA,0xFA,0xB9};

  DownlistResponse() : result(""), node_id("") {
  }

  virtual ~DownlistResponse() throw() {}

  std::string result;
  std::string node_id;

  _DownlistResponse__isset __isset;

  bool operator == (const DownlistResponse & rhs) const
  {
    if (!(result == rhs.result))
      return false;
    if (__isset.node_id != rhs.__isset.node_id)
      return false;
    else if (__isset.node_id && !(node_id == rhs.node_id))
      return false;
    return true;
  }
  bool operator != (const DownlistResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DownlistResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _BootstrapRequest__isset {
  _BootstrapRequest__isset() : newcomer_id(false), newcomer_local_ip(false), newcomer_local_port(false), node_type(false), newcomer_ext_ip(false), newcomer_ext_port(false) {}
  bool newcomer_id;
  bool newcomer_local_ip;
  bool newcomer_local_port;
  bool node_type;
  bool newcomer_ext_ip;
  bool newcomer_ext_port;
} _BootstrapRequest__isset;

class BootstrapRequest {
 public:

  static const char* ascii_fingerprint; // = "0874C2BFB0A4B3FC6DB35F09B978D424";
  static const uint8_t binary_fingerprint[16]; // = {0x08,0x74,0xC2,0xBF,0xB0,0xA4,0xB3,0xFC,0x6D,0xB3,0x5F,0x09,0xB9,0x78,0xD4,0x24};

  BootstrapRequest() : newcomer_id(""), newcomer_local_ip(""), newcomer_local_port(0), node_type(0), newcomer_ext_ip(""), newcomer_ext_port(0) {
  }

  virtual ~BootstrapRequest() throw() {}

  std::string newcomer_id;
  std::string newcomer_local_ip;
  int32_t newcomer_local_port;
  int32_t node_type;
  std::string newcomer_ext_ip;
  int32_t newcomer_ext_port;

  _BootstrapRequest__isset __isset;

  bool operator == (const BootstrapRequest & rhs) const
  {
    if (!(newcomer_id == rhs.newcomer_id))
      return false;
    if (!(newcomer_local_ip == rhs.newcomer_local_ip))
      return false;
    if (!(newcomer_local_port == rhs.newcomer_local_port))
      return false;
    if (!(node_type == rhs.node_type))
      return false;
    if (__isset.newcomer_ext_ip != rhs.__isset.newcomer_ext_ip)
      return false;
    else if (__isset.newcomer_ext_ip && !(newcomer_ext_ip == rhs.newcomer_ext_ip))
      return false;
    if (__isset.newcomer_ext_port != rhs.__isset.newcomer_ext_port)
      return false;
    else if (__isset.newcomer_ext_port && !(newcomer_ext_port == rhs.newcomer_ext_port))
      return false;
    return true;
  }
  bool operator != (const BootstrapRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const BootstrapRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _BootstrapResponse__isset {
  _BootstrapResponse__isset() : result(false), bootstrap_id(false), newcomer_ext_ip(false), newcomer_ext_port(false), nat_type(false) {}
  bool result;
  bool bootstrap_id;
  bool newcomer_ext_ip;
  bool newcomer_ext_port;
  bool nat_type;
} _BootstrapResponse__isset;

class BootstrapResponse {
 public:

  static const char* ascii_fingerprint; // = "CBE249FEAC2BB737776A77DB88635356";
  static const uint8_t binary_fingerprint[16]; // = {0xCB,0xE2,0x49,0xFE,0xAC,0x2B,0xB7,0x37,0x77,0x6A,0x77,0xDB,0x88,0x63,0x53,0x56};

  BootstrapResponse() : result(""), bootstrap_id(""), newcomer_ext_ip(""), newcomer_ext_port(0), nat_type(0) {
  }

  virtual ~BootstrapResponse() throw() {}

  std::string result;
  std::string bootstrap_id;
  std::string newcomer_ext_ip;
  int32_t newcomer_ext_port;
  int32_t nat_type;

  _BootstrapResponse__isset __isset;

  bool operator == (const BootstrapResponse & rhs) const
  {
    if (!(result == rhs.result))
      return false;
    if (__isset.bootstrap_id != rhs.__isset.bootstrap_id)
      return false;
    else if (__isset.bootstrap_id && !(bootstrap_id == rhs.bootstrap_id))
      return false;
    if (__isset.newcomer_ext_ip != rhs.__isset.newcomer_ext_ip)
      return false;
    else if (__isset.newcomer_ext_ip && !(newcomer_ext_ip == rhs.newcomer_ext_ip))
      return false;
    if (__isset.newcomer_ext_port != rhs.__isset.newcomer_ext_port)
      return false;
    else if (__isset.newcomer_ext_port && !(newcomer_ext_port == rhs.newcomer_ext_port))
      return false;
    if (__isset.nat_type != rhs.__isset.nat_type)
      return false;
    else if (__isset.nat_type && !(nat_type == rhs.nat_type))
      return false;
    return true;
  }
  bool operator != (const BootstrapResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const BootstrapResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeleteRequest__isset {
  _DeleteRequest__isset() : key(false), value(false), signed_request(false), sender_info(false) {}
  bool key;
  bool value;
  bool signed_request;
  bool sender_info;
} _DeleteRequest__isset;

class DeleteRequest {
 public:

  static const char* ascii_fingerprint; // = "DFE2E3B0DDF46A49C5F5309AE3A5096B";
  static const uint8_t binary_fingerprint[16]; // = {0xDF,0xE2,0xE3,0xB0,0xDD,0xF4,0x6A,0x49,0xC5,0xF5,0x30,0x9A,0xE3,0xA5,0x09,0x6B};

  DeleteRequest() : key("") {
  }

  virtual ~DeleteRequest() throw() {}

  std::string key;
  kad::SignedValue value;
  kad::SignedRequest signed_request;
  kad::ContactInfo sender_info;

  _DeleteRequest__isset __isset;

  bool operator == (const DeleteRequest & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    if (!(value == rhs.value))
      return false;
    if (!(signed_request == rhs.signed_request))
      return false;
    if (!(sender_info == rhs.sender_info))
      return false;
    return true;
  }
  bool operator != (const DeleteRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeleteRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeleteResponse__isset {
  _DeleteResponse__isset() : result(false), node_id(false) {}
  bool result;
  bool node_id;
} _DeleteResponse__isset;

class DeleteResponse {
 public:

  static const char* ascii_fingerprint; // = "5B708A954C550ECA9C1A49D3C5CAFAB9";
  static const uint8_t binary_fingerprint[16]; // = {0x5B,0x70,0x8A,0x95,0x4C,0x55,0x0E,0xCA,0x9C,0x1A,0x49,0xD3,0xC5,0xCA,0xFA,0xB9};

  DeleteResponse() : result(""), node_id("") {
  }

  virtual ~DeleteResponse() throw() {}

  std::string result;
  std::string node_id;

  _DeleteResponse__isset __isset;

  bool operator == (const DeleteResponse & rhs) const
  {
    if (!(result == rhs.result))
      return false;
    if (__isset.node_id != rhs.__isset.node_id)
      return false;
    else if (__isset.node_id && !(node_id == rhs.node_id))
      return false;
    return true;
  }
  bool operator != (const DeleteResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeleteResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UpdateRequest__isset {
  _UpdateRequest__isset() : key(false), new_value(false), old_value(false), ttl(false), request(false), sender_info(false) {}
  bool key;
  bool new_value;
  bool old_value;
  bool ttl;
  bool request;
  bool sender_info;
} _UpdateRequest__isset;

class UpdateRequest {
 public:

  static const char* ascii_fingerprint; // = "4FA77E37173C59B45221E40E34BFE2AC";
  static const uint8_t binary_fingerprint[16]; // = {0x4F,0xA7,0x7E,0x37,0x17,0x3C,0x59,0xB4,0x52,0x21,0xE4,0x0E,0x34,0xBF,0xE2,0xAC};

  UpdateRequest() : key(""), ttl(0) {
  }

  virtual ~UpdateRequest() throw() {}

  std::string key;
  kad::SignedValue new_value;
  kad::SignedValue old_value;
  int32_t ttl;
  kad::SignedRequest request;
  kad::ContactInfo sender_info;

  _UpdateRequest__isset __isset;

  bool operator == (const UpdateRequest & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    if (!(new_value == rhs.new_value))
      return false;
    if (!(old_value == rhs.old_value))
      return false;
    if (!(ttl == rhs.ttl))
      return false;
    if (!(request == rhs.request))
      return false;
    if (!(sender_info == rhs.sender_info))
      return false;
    return true;
  }
  bool operator != (const UpdateRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UpdateRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UpdateResponse__isset {
  _UpdateResponse__isset() : result(false), node_id(false) {}
  bool result;
  bool node_id;
} _UpdateResponse__isset;

class UpdateResponse {
 public:

  static const char* ascii_fingerprint; // = "5B708A954C550ECA9C1A49D3C5CAFAB9";
  static const uint8_t binary_fingerprint[16]; // = {0x5B,0x70,0x8A,0x95,0x4C,0x55,0x0E,0xCA,0x9C,0x1A,0x49,0xD3,0xC5,0xCA,0xFA,0xB9};

  UpdateResponse() : result(""), node_id("") {
  }

  virtual ~UpdateResponse() throw() {}

  std::string result;
  std::string node_id;

  _UpdateResponse__isset __isset;

  bool operator == (const UpdateResponse & rhs) const
  {
    if (!(result == rhs.result))
      return false;
    if (__isset.node_id != rhs.__isset.node_id)
      return false;
    else if (__isset.node_id && !(node_id == rhs.node_id))
      return false;
    return true;
  }
  bool operator != (const UpdateResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UpdateResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

} // namespace

#endif
