/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
#ifndef contact_info_TYPES_H
#define contact_info_TYPES_H

#include <Thrift.h>
#include <TApplicationException.h>
#include <protocol/TProtocol.h>
#include <transport/TTransport.h>



namespace kad {

typedef struct _ContactInfo__isset {
  _ContactInfo__isset() : node_id(false), ip(false), port(false), local_ip(false), local_port(false), rendezvous_ip(false), rendezvous_port(false) {}
  bool node_id;
  bool ip;
  bool port;
  bool local_ip;
  bool local_port;
  bool rendezvous_ip;
  bool rendezvous_port;
} _ContactInfo__isset;

class ContactInfo {
 public:

  static const char* ascii_fingerprint; // = "457181BECBF275C1D1D18F73C238083C";
  static const uint8_t binary_fingerprint[16]; // = {0x45,0x71,0x81,0xBE,0xCB,0xF2,0x75,0xC1,0xD1,0xD1,0x8F,0x73,0xC2,0x38,0x08,0x3C};

  ContactInfo() : node_id(""), ip(""), port(0), local_ip(""), local_port(0), rendezvous_ip(""), rendezvous_port(0) {
  }

  virtual ~ContactInfo() throw() {}

  std::string node_id;
  std::string ip;
  int32_t port;
  std::string local_ip;
  int32_t local_port;
  std::string rendezvous_ip;
  int32_t rendezvous_port;

  _ContactInfo__isset __isset;

  bool operator == (const ContactInfo & rhs) const
  {
    if (!(node_id == rhs.node_id))
      return false;
    if (!(ip == rhs.ip))
      return false;
    if (!(port == rhs.port))
      return false;
    if (__isset.local_ip != rhs.__isset.local_ip)
      return false;
    else if (__isset.local_ip && !(local_ip == rhs.local_ip))
      return false;
    if (__isset.local_port != rhs.__isset.local_port)
      return false;
    else if (__isset.local_port && !(local_port == rhs.local_port))
      return false;
    if (__isset.rendezvous_ip != rhs.__isset.rendezvous_ip)
      return false;
    else if (__isset.rendezvous_ip && !(rendezvous_ip == rhs.rendezvous_ip))
      return false;
    if (__isset.rendezvous_port != rhs.__isset.rendezvous_port)
      return false;
    else if (__isset.rendezvous_port && !(rendezvous_port == rhs.rendezvous_port))
      return false;
    return true;
  }
  bool operator != (const ContactInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ContactInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

} // namespace

#endif
