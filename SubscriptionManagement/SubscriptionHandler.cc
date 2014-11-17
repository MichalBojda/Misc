#include "SubscriptionHandler.hh"


SubscriptionHandler::SubscriptionHandler( SubscriptionManager* aManager
                                        , const SubscriptionManager::Subscriptions::iterator& aSubscription )
    : iManager{ aManager, Unsubscriber{ aSubscription } }
    , iUnsubscribedManager{ nullptr }
{
}

SubscriptionHandler::~SubscriptionHandler()
{
}

void SubscriptionHandler::unsubscribe()
{
    if ( iManager )
    {
        iUnsubscribedManager.swap( iManager );
    }
}

void SubscriptionHandler::resubscribe()
{
    if ( !iManager )
    {
        iUnsubscribedManager.swap( iManager );
    }
}

SubscriptionHandler::Unsubscriber::Unsubscriber( const SubscriptionManager::Subscriptions::iterator& aSubscription )
    : iSubscription( aSubscription )
{
}

SubscriptionHandler::Unsubscriber::~Unsubscriber()
{
}

void SubscriptionHandler::Unsubscriber::operator()( SubscriptionManager* aManager )
{
    if ( aManager )
    {
        aManager->unsubscribe( iSubscription );
    }
}

