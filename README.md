# Orderbook Data Structure

This project implements an orderbook data structure in C++. An orderbook is a critical component of financial markets, used to manage and match buy and sell orders efficiently.

## Overview

The project consists of several key components:

- **Orderbook**: The main class representing the orderbook. It manages buy and sell orders and matches them based on price-time priority.

- **Order**: Represents an individual order with attributes such as order type, side (buy/sell), price, and quantity.

- **Order Modify**: Handles modifications to existing orders, such as price or quantity adjustments.

- **Trade**: Represents a trade executed between a buy and sell order.

- **Google Tests**: The project includes tests implemented using Google Test framework to ensure correctness and reliability.

## Usage

To use the orderbook, you can create an instance of the `Orderbook` class and interact with it by adding, canceling, or modifying orders. Here's a simple example:

```cpp
Orderbook orderbook;

// Add a buy order
const OrderId orderId = 1;
orderbook.addOrder(std::make_shared<Order>(OrderType::GoodTillCancel, orderId, Side::Buy, 100, 10));

// Check the size of the orderbook
std::cout << "Orderbook size: " << orderbook.Size() << std::endl;

// Cancel the order
orderbook.CancelOrder(orderId);

// Check the size again
std::cout << "Orderbook size after cancellation: " << orderbook.Size() << std::endl;
```

## Order Types

The project supports various order types including:

- **Good Till Cancel**: The order remains active until filled, canceled, or expires.
- **Fill and Kill**: The order is filled as much as possible, and any remaining quantity is canceled immediately.
- **Market Order**: Filled at the best available price.
- **Good For Day**: Similar to Good Till Cancel, but automatically canceled at the end of the trading day.
- **Fill or Kill**: Must be filled immediately and entirely or canceled.

## Dependencies

The project relies on standard C++ libraries and includes Google Test framework for testing purposes.

## Testing

The project includes comprehensive unit tests implemented using Google Test framework to ensure correctness and reliability. To run the tests, you can run the following file:
```
test.cpp
```

## Contributing

Contributions are welcome! Feel free to open issues or pull requests for any improvements or bug fixes.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

Feel free to customize this README further to provide more detailed information about your project's features, usage, or any other relevant details.
