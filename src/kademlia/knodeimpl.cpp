/**
 * @file   knodeimpl.cpp
 * @author Devil Wang <wxjeacen@gmail.com>
 * @date   Thu Mar  3 19:06:58 2011
 *
 * @brief
 *
 *
 */

#include "knodeimpl.h"
#include <boost/assert.hpp>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>
#include "datastore.h"
#include "kadrpc.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "kadid.h"
namespace fs = boost::filesystem;

namespace kad
{

    // bool CompareContact(const ContactAndTargetKey &first,
    //                     const ContactAndTargetKey &second) {

    //     // if (kademlia_distance(first.contact.node_id(), first.target_key) <
    //     //     kademlia_distance(second.contact.node_id(), second.target_key))
    //     if ( first.contact.node_id() ^ first.target_key < second.contact.node_id() ^ second.target_key)
    //         return true;
    //     else
    //         return false;
    // }


}
