#pragma once

#include <set>
#include <functional>

#include "SubscriptionHandler.hh"

class SubscriptionManager
{
    public:

        using SubscriptionCallback =    std::function< void( void ) >;
        using Subscriptions =           std::set< SubscriptionCallback >;

        ~SubscriptionManager();

        SubscriptionHandler subscribe( const SubscriptionCallback& aCallback );

        void unsubscribe( const Subscriptions::iterator& aSubscription );

    private:

        Subscriptions iSubscriptions;
};

