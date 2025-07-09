# C++ Threading Practice

A collection of small C++ programs to explore multithreading and concurrency.

## 📚 Inspiration / Learning Source

These examples are based on my self-study of multithreading in C++.  
Much of the material was inspired by lessons from https://www.youtube.com/@MikeShah

I built this repo to deepen my understanding through hands-on practice and personal understanding notes


## File Description

- 01 - single thread launching
- 02 - using lambda in thread
- 03 - launching multiple threads
- 04 - using std::jthread for auto joining
- 05 - using std::mutex to prevent data race
- 06 - using std::lock_gaurd to prevent dead lock
- 07 - using std::atomic instead of mutex
- 08 - sample threading ussage of a four color grid changing colors concurrently

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
