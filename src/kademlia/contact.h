/**
 * @file   contact.h
 * @author Devil Wang <wxjeacen@gmail.com>
 * @date   Tue Nov 30 13:27:27 2010
 *
 * @brief  Kademlia Algorithm constructor contact information
 *
 *
 **/

#ifndef __CONTACT__H__
#define __CONTACT__H__

#include <string>
#include "kadid.h"
#include "tinyxml.h"

namespace kad{


    class ContactInfo;

    class Contact{

    public:

        friend class ContactInfo;
        /*
         *Default Contact constructor
         */

        Contact();

        virtual ~Contact(){}

        Contact(const BigInt::Rossi &node_id, const std::string &host_ip,
                const unsigned short int &host_port, const std::string &local_ip,
                const unsigned short int &local_port, const std::string &rendezvous_ip,
                const unsigned short int &rendezvous_port);

        Contact(const BigInt::Rossi &node_id, const std::string &host_ip,
                const unsigned short int &host_port);
        Contact(const BigInt::Rossi &node_id, const std::string &host_ip,
                const unsigned short int &host_port, const std::string &local_ip,
                const unsigned short int &local_port);
        Contact(const KadID &node_id, const std::string &host_ip,
                const unsigned short int &host_port, const std::string &local_ip,
                const unsigned short int &local_port, const std::string &rendezvous_ip,
                const unsigned short int &rendezvous_port);
        Contact(const KadID &node_id, const std::string &host_ip,
                const unsigned short int &host_port);
        Contact(const KadID &node_id, const std::string &host_ip,
                const unsigned short int &host_port, const std::string &local_ip,
                const unsigned short int &local_port);

        explicit Contact(const ContactInfo &contact_info);

        //bool SerialiseToXmlElement(ContactInfo *serialised_output);
        bool ParseFromThrift(const ContactInfo &data);

        ContactInfo ParseToThrift();

        std::string DebugString() const;
        inline bool Equals( const Contact & other ){
            return this->node_id_ == other.node_id_;
        }
        inline const KadID& node_id() const { return node_id_; }
        inline const std::string& host_ip() const { return host_ip_; }
        inline unsigned short host_port() const { return host_port_; }
        const std::string& rendezvous_ip() const { return rendezvous_ip_; }
        unsigned short rendezvous_port() const { return rendezvous_port_; }
        int64_t last_seen() const { return last_seen_; }

        void set_last_seen(int64_t last_seen){
            last_seen_ = last_seen;
        }
        inline const std::string& local_ip() const { return local_ip_; }
        inline unsigned short int local_port() const { return local_port_; }

    private:

        KadID node_id_;
        std::string host_ip_;
        unsigned short host_port_;
        std::string rendezvous_ip_;
        unsigned short rendezvous_port_;
        std::string local_ip_;
        unsigned short local_port_;
        int64_t last_seen_;
    };
}
#endif
