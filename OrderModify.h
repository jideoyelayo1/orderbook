#pragma once

#include <numeric>
#include "OrderType.h"
#include "Side.h"

// Alias types
using Price = std::int32_t;
using Quantity = std::uint32_t;
using OrderId = std::uint64_t;


class OrderModify {
private:
    OrderId _id;
    Side _side;
    Price _price;
    Quantity _qty;
public:
    OrderModify(OrderId id, Side side, Price price, Quantity qty)
        : _id{ id }, _side{ side }, _price{ price }, _qty{ qty }
    {};


    OrderId getOrderId() const;
    Side getSide() const;
    Price getPrice() const;
    Quantity getQty() const;

    OrderPtr toOrderPtr(OrderType type) const;

};

