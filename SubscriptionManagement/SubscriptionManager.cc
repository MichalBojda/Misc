#include "SubscriptionManager.hh"

SubscriptionManager::~SubscriptionManager()
{

}

SubscriptionHandler SubscriptionManager::subscribe( const SubscriptionCallback& aCallback )
{
    Subscriptions::iterator lInserted = iSubscriptions.insert( aCallback ).first;

    return SubscriptionHandler( this );
}

//void SubscriptionManager::unsubscribe( const Subscriptions::iterator& /*aSubscription*/ )
//{
//
//}

void SubscriptionManager::triggerCallbacks()
{

}

