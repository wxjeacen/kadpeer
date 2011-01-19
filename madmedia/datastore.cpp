/**
 * @file   datastore.cpp
 * @author Devil Wang <wxjeacen@gmail.com>
 * @date   Thu Jan 13 10:38:39 2011
 *
 * @brief
 *
 *
 */

#include "datastore.h"
#include <exception>
#include "TTimer.hh"
namespace kad {

    DataStore::DataStore(const uint32_t &t_refresh)
        : datastore_(), t_refresh_(0), mutex_() {
        t_refresh_ = t_refresh;
    }

    DataStore::~DataStore() {
        datastore_.clear();
    }

    bool DataStore::Keys(std::set<std::string> *keys) {
        keys->clear();
        boost::mutex::scoped_lock guard(mutex_);
        for (datastore::iterator it = datastore_.begin();
             it != datastore_.end(); ++it)
            keys->insert(it->key_);
        return true;
    }

    bool DataStore::StoreItem(const std::string &key, const std::string &value,
                              const int32_t &time_to_live,
                              const bool &hashable) {

        if (key.empty() || value.empty() || time_to_live == 0)
            return false;

        //
        TTimer timer;
        uint32_t time_stamp = static_cast<uint32_t>( timer.current());
        key_value_tuple tuple(key, value, time_stamp,
                              time_to_live + time_stamp, time_to_live, hashable);

        boost::mutex::scoped_lock guard(mutex_);

        std::pair<datastore::iterator, bool> p = datastore_.insert(tuple);

        if (!p.second) {
            if ((p.first->del_status_ == NOT_DELETED) ||
                (tuple.ttl_ == -1) ||
                (p.first->expire_time_ < tuple.expire_time_ && p.first->ttl_ != -1)) {
                datastore_.replace(p.first, tuple);
            } else {
                return false;
            }
        }
        return true;
    }

    bool DataStore::LoadItem(const std::string &key,
                             std::vector<std::string> *values) {
        values->clear();
        boost::mutex::scoped_lock guard(mutex_);
        std::pair<datastore::iterator, datastore::iterator> p =
            datastore_.equal_range(boost::make_tuple(key));
        if (p.first == p.second)
            return false;
        TTimer timer;
        uint32_t now = static_cast<uint32_t>(timer.current());
        while (p.first != p.second) {
            int32_t ttl_remaining = p.first->expire_time_ - now;
            if ((ttl_remaining > 0 || p.first->ttl_ == -1) &&
                (p.first->del_status_ == NOT_DELETED))
                values->push_back(p.first->value_);
            ++p.first;
        }
        if (values->empty())
            return false;
        return true;
    }

    bool DataStore::DeleteItem(const std::string &key, const std::string &value) {
        datastore::iterator it = datastore_.find(boost::make_tuple(key, value));
        boost::mutex::scoped_lock guard(mutex_);
        if (it == datastore_.end())
            return false;
        datastore_.erase(it);
        return true;
    }

    bool DataStore::DeleteKey(const std::string &key) {
        boost::mutex::scoped_lock guard(mutex_);
        std::pair<datastore::iterator, datastore::iterator> p =
            datastore_.equal_range(boost::make_tuple(key));
        if (p.first == p.second)
            return false;
        datastore_.erase(p.first, p.second);
        return true;
    }

    uint32_t DataStore::LastRefreshTime(const std::string &key,
                                        const std::string &value) {
        boost::mutex::scoped_lock guard(mutex_);
        datastore::iterator it = datastore_.find(boost::make_tuple(key, value));
        if (it == datastore_.end())
            return 0;
        return it->last_refresh_time_;
    }

    boost::uint32_t DataStore::ExpireTime(const std::string &key,
                                          const std::string &value) {
        boost::mutex::scoped_lock guard(mutex_);
        datastore::iterator it = datastore_.find(boost::make_tuple(key, value));
        if (it == datastore_.end())
            return 0;
        return it->expire_time_;
    }

    std::vector<refresh_value> DataStore::ValuesToRefresh() {
        TTimer timer;
        std::vector<refresh_value> values;
        datastore::index<kad::t_last_refresh_time>::type::iterator it, up_limit;
        boost::mutex::scoped_lock guard(mutex_);
        datastore::index<kad::t_last_refresh_time>::type& indx =
            datastore_.get<kad::t_last_refresh_time>();
        uint32_t now = static_cast<uint32_t>(timer.current());
        uint32_t time_limit = now - t_refresh_;
        up_limit = indx.upper_bound(time_limit);
        for (it = indx.begin(); it != up_limit; ++it) {
            if (it->ttl_ == -1 && it->del_status_ == NOT_DELETED) {
                values.push_back(refresh_value(it->key_, it->value_, it->ttl_));
            } else {
                int32_t ttl_remaining = it->expire_time_ - now;
                if (ttl_remaining > 0 && it->del_status_ == NOT_DELETED)
                    values.push_back(refresh_value(it->key_, it->value_, ttl_remaining));
                else if (it->del_status_ != NOT_DELETED)
                    values.push_back(refresh_value(it->key_, it->value_, it->del_status_));
            }
        }
        return values;
    }

    void DataStore::DeleteExpiredValues() {
        TTimer timer;
        datastore::index<kad::t_expire_time>::type::iterator up_limit, down_limit, it;
        boost::mutex::scoped_lock guard(mutex_);
        datastore::index<kad::t_expire_time>::type& indx =
            datastore_.get<kad::t_expire_time>();
        uint32_t now = static_cast<uint32_t>(timer.current());
        up_limit = indx.lower_bound(now);
        down_limit = indx.upper_bound(0);
        indx.erase(down_limit, up_limit);
    }

    void DataStore::Clear() {
        boost::mutex::scoped_lock guard(mutex_);
        datastore_.clear();
    }

    int32_t DataStore::TimeToLive(const std::string &key,
                                  const std::string &value) {
        boost::mutex::scoped_lock guard(mutex_);
        datastore::iterator it = datastore_.find(boost::make_tuple(key, value));
        if (it == datastore_.end())
            return 0;
        return it->ttl_;
    }

    uint32_t DataStore::t_refresh() const {
        return t_refresh_;
    }

    std::vector<std::pair<std::string, bool> > DataStore::LoadKeyAppendableAttr(
        const std::string &key) {
        std::vector< std::pair<std::string, bool> > result;
        boost::mutex::scoped_lock guard(mutex_);
        std::pair<datastore::iterator, datastore::iterator> p =
            datastore_.equal_range(boost::make_tuple(key));
        while (p.first != p.second) {
            result.push_back(std::pair<std::string, bool>(p.first->value_,
                                                          p.first->hashable_));
            ++p.first;
        }
        return result;
    }

    bool DataStore::RefreshItem(const std::string &key,
                                const std::string &value,
                                std::string *str_delete_req) {
        TTimer timer;
        boost::mutex::scoped_lock guard(mutex_);
        datastore::iterator it = datastore_.find(boost::make_tuple(key, value));
        if (it == datastore_.end())
            return false;
        if (it->del_status_ != NOT_DELETED) {
            str_delete_req->clear();
            *str_delete_req = it->ser_delete_req_;
            return false;
        }
        uint32_t time_stamp = static_cast<uint32_t>(timer.current());
        key_value_tuple tuple(key, value, time_stamp);
        tuple.ttl_ = it->ttl_;
        tuple.expire_time_ = it->expire_time_;
        tuple.hashable_ = it->hashable_;

        return datastore_.replace(it, tuple);
    }

    bool DataStore::MarkForDeletion(const std::string &key,
                                    const std::string &value,
                                    const std::string &ser_del_request) {
        boost::mutex::scoped_lock guard(mutex_);
        datastore::iterator it = datastore_.find(boost::make_tuple(key, value));
        if (it == datastore_.end())
            return false;
        // Check if already deleted or marked as deleted
        if (it->del_status_ != NOT_DELETED)
            return true;
        key_value_tuple tuple(key, value, 0);
        tuple.ttl_ = it->ttl_;
        tuple.expire_time_ = it->expire_time_;
        tuple.hashable_ = it->hashable_;
        tuple.last_refresh_time_ = it->last_refresh_time_;
        tuple.ser_delete_req_ = ser_del_request;
        tuple.del_status_ = MARKED_FOR_DELETION;

        return datastore_.replace(it, tuple);
    }

    bool DataStore::MarkAsDeleted(const std::string &key,
                                  const std::string &value) {
        boost::mutex::scoped_lock guard(mutex_);
        datastore::iterator it = datastore_.find(boost::make_tuple(key, value));
        if (it == datastore_.end() || it->del_status_ != MARKED_FOR_DELETION)
            return false;
        key_value_tuple tuple(key, value, 0);
        tuple.ttl_ = it->ttl_;
        tuple.expire_time_ = it->expire_time_;
        tuple.hashable_ = it->hashable_;
        tuple.last_refresh_time_ = it->last_refresh_time_;
        tuple.ser_delete_req_ = it->ser_delete_req_;
        tuple.del_status_ = DELETED;

        return datastore_.replace(it, tuple);
    }

    bool DataStore::UpdateItem(const std::string &key,
                               const std::string &old_value,
                               const std::string &new_value,
                               const boost::int32_t &time_to_live,
                               const bool &hashable) {
        TTimer timer;
        boost::mutex::scoped_lock guard(mutex_);
        datastore::iterator it = datastore_.find(boost::make_tuple(key, old_value));
        if (it == datastore_.end() || it->del_status_ == MARKED_FOR_DELETION ||
            it->del_status_ == DELETED)
            return false;

        key_value_tuple tuple(key, new_value, 0);
        uint32_t now = static_cast<uint32_t>(timer.current());
        tuple.ttl_ = time_to_live;
        tuple.expire_time_ = now + time_to_live;
        tuple.last_refresh_time_ = now;
        tuple.del_status_ = NOT_DELETED;
        tuple.hashable_ = hashable;

        return datastore_.replace(it, tuple);
    }

}
