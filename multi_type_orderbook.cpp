#include <iostream>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <limits>
#include <thread>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <memory>
#include <variant>
#include <optional>
#include <tuple>
#include <format>
#include <condition_variable>
#include <mutex>

/*
An orderbook is a data structure. A collection of orders partitioned by buys and sells.
Such that buy orders and sell orders are matched by price-time priority.
An order that is the best bid is going to be matched first against a sell order thats looking to aggress against the buy side (looking to sell into the
orderbook).
*/

#include "Orderbook.h"


int main() {

    Orderbook orderbook;
    /*
    const OrderId orderId = 1;
    orderbook.addOrder(std::make_shared<Order>(OrderType::GoodTillCancel, orderId, Side::Buy, 100, 10));
    std::cout << orderbook.Size() << std::endl; // size should be 1
    orderbook.CancelOrder(orderId);
    std::cout << orderbook.Size() << std::endl; // size should be 0
    */

    return 0;
}

