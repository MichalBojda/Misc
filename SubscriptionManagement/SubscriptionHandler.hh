#pragma once

#include <memory>

class SubscriptionManager;

class SubscriptionHandler
{
    public:

        using SubscriptionCallback = std::function< void( void ) >;


        SubscriptionHandler( SubscriptionManager* aManager, const SubscriptionCallback& aCallback );

        SubscriptionHandler( SubscriptionHandler&& aOther ) = default;

        ~SubscriptionHandler();

    private:


        using ManagerPtr = std::unique_ptr< SubscriptionManager >;

        ManagerPtr              iManagerPtr;
        SubscriptionCallback    iCallback;
};

