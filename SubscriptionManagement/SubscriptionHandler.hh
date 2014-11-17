#pragma once

#include <memory>

#include "SubscriptionManager.hh"

//class SubscriptionManager;

class SubscriptionHandler
{
    public:

        SubscriptionHandler( SubscriptionManager* aManager, const SubscriptionManager::Subscriptions::iterator& aSubscription );

        ~SubscriptionHandler();

        void unsubscribe();

        void resubscribe();

    private:

        struct Unsubscriber
        {
            Unsubscriber( const SubscriptionManager::Subscriptions::iterator& aIterator );

            ~Unsubscriber();

            void operator()( SubscriptionManager* aManager );

            SubscriptionManager::Subscriptions::iterator iSubscription;
        };

        using SubscriptionService = std::unique_ptr< SubscriptionManager, Unsubscriber >;

        SubscriptionService iManager;
        SubscriptionService iUnsubscribedManager;
};

