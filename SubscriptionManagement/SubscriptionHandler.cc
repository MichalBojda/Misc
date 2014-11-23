#include "SubscriptionHandler.hh"

#include "SubscriptionManager.hh"

#include <iostream>


SubscriptionHandler::SubscriptionHandler( SubscriptionManager* aManager, const SubscriptionCallback& aCallback )
    : iManagerPtr{ aManager }
    , iCallback{ aCallback }
{
}

