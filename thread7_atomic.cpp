#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

using namespace std;

// NOTES:
// Use std::atomic instead of a mutex for simple variable types like int.
// Ensures the variable is accessed safely by multiple threads (no race conditions).
// Only use supported atomic operations: ++, --, +=, -=, etc. 
// ⚠️ Avoid expressions like: x = x + 1;  // not atomic (reads + writes separately)

// ✅ std::atomic supports:
// - int, bool, char
// - pointers (e.g., int*)
// ⚠️ float, double (C++20+, not always lock-free)
// ❌ Not supported:
// - std::string, std::vector
// - custom classes (use mutex instead)


static atomic<int> shared_value = 0;

void shared_value_increment(){
    shared_value++;
    // shared_value += 1; this works as well
    // shared_value = shared_value + 1;    This is buggy **
    // because ++ and += are overloaded operaters in atomic<T>
}

int main(){

    vector<thread> threads;
    for (int i = 0; i < 1000; i++){
        threads.push_back(thread(shared_value_increment));
    }

    for (int i = 0; i < 1000; i++){
        threads[i].join();
    }

    cout << "Shared Value: " << shared_value << endl;

    return 0;
}

//g++-15 -std=c++20 -o atomic thread7_atomic.cpp