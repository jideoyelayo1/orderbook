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
- **Market Order**: Takes the opposite side from the best price down. The book turns it into a Good Till Cancel order priced at the worst opposite level, so if it is larger than the whole opposite side, the remainder rests at that price. It is rejected if the opposite side is empty.
- **Good For Day**: Similar to Good Till Cancel, but a background thread cancels it at 16:00 local time.
- **Fill or Kill**: Must be filled immediately and entirely or canceled.

## Dependencies

The project relies on standard C++ libraries and includes Google Test framework for testing purposes.

## Testing

The tests use Google Test and live in `OrderbookTest/`:

- `test.cpp` replays the action files in `OrderbookTest/TestFiles/` and checks the order and level counts.
- `MatchingContractTests.cpp` checks which order traded, at which price and in which order: price and time priority, no trade without a cross, each order type, cancel, modify, a seeded random flow of all of them, and destroying many books.

On macOS or Linux you need CMake 3.20 or later and a C++20 compiler whose standard library has `std::format`. Build and run everything with:

```sh
cmake -S . -B build && cmake --build build && ctest --test-dir build --output-on-failure
```

CMake downloads Google Test 1.14.0 the first time it configures. Each test has a 20 s timeout, so a hang shows up as a failure. On Windows, the Visual Studio solution builds the same test project (`OrderbookTest`, with Google Test from NuGet).

To run under AddressSanitizer and UndefinedBehaviorSanitizer:

```sh
cmake -S . -B build-asan -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS="-fsanitize=address,undefined -fno-omit-frame-pointer"
cmake --build build-asan && UBSAN_OPTIONS=halt_on_error=1 ctest --test-dir build-asan --output-on-failure
```

For ThreadSanitizer, use `-fsanitize=thread` and `TSAN_OPTIONS=halt_on_error=1`.

On an Apple M1 Pro with Apple clang 21, all 39 tests pass 20 times each in a Release build, under AddressSanitizer and UndefinedBehaviorSanitizer, and under ThreadSanitizer. The raw output and the results from before the fixes are in `OrderbookTest/results/`. Only macOS has been tested.

## Contributing

Contributions are welcome! Feel free to open issues or pull requests for any improvements or bug fixes.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

Feel free to customize this README further to provide more detailed information about your project's features, usage, or any other relevant details.
