#pragma once

#include <list>
#include <exception>
#include <format>
#include <memory>
#include <cmath>

#include "using.h"
#include "ordertype.h"
#include "side.h"
#include "constants.h"


class Order
{
public:
    Order(OrderType orderType, OrderId orderId, Side side, Price price, Quantity quantity)
        : orderType_(orderType), orderId_(orderId), side_(side), price_(price), initialQuantity_(quantity), remainingQuantity_(quantity) {}
    OrderId GetOrderId() const { return orderId_; }
    Side GetSide() const { return side_; }
    Price GetPrice() const { return price_; }
    OrderType GetOrderType() const { return orderType_; }
    Quantity GetInitialQuantity() const { return initialQuantity_; }
    Quantity GetRemainingQuantity() const { return remainingQuantity_; }
    Quantity GetFilledQuantity() const { return GetInitialQuantity() - GetRemainingQuantity(); }

    Order(OrderId orderId , Side side , Quantity quantity)
        : Order(OrderType::Market, orderId, side , constants::InvalidPrice , quantity){}
    bool isFilled() const
    {
        return remainingQuantity_ == 0;
    }
    void Fill(Quantity quantity)
    {
        if (quantity > GetRemainingQuantity())
        {
            throw std::logic_error("Order ({}) cannot be filled for more than its remaining quantiy.");
        }
        remainingQuantity_ -= quantity;
    }
    void ToGoodTillCancel(Price price) 
    { 
        if (GetOrderType() != OrderType::Market)
        {
            throw std::logic_error("Order {} cannot have its price adjusted, only market orders can.");
        }
        if (std::isfinite(price)) {
            throw std::logic_error("Order must be a Tradable price");
        }
        price_ = price;
        orderType_ = OrderType::GoodTillCancel;
    }


private: 
    OrderType orderType_;
    OrderId orderId_;
    Side side_;
    Price price_;
    Quantity initialQuantity_;
    Quantity remainingQuantity_;
};

using OrderPointer = std::shared_ptr<Order>;
using OrderPointers = std::list<OrderPointer>;