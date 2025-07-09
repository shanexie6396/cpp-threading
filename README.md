# C++ Threading Practice

A collection of small C++ programs to explore multithreading and concurrency.

## Topics Covered

- `std::thread` and `.join()`
- `std::mutex` and `std::lock_guard`
- `std::atomic`
- Lambdas in threading
- `std::jthread` (C++20)
- Deadlocks and safe locking
- SFML visualization (for fun)

Each file is numbered by study order (e.g. `02_lambda_thread.cpp`) with simple examples.

## How to Compile (example)

```bash
g++-15 -std=c++20 -o thread_example 02_lambda_thread.cpp -pthread
