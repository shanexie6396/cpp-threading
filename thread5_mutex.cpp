#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

// Notes**
// use mutex when things are shared between threads
// prevent data races
// std::mutex - mutual exclusion
// It’s a tool that lets only one thread at a time access a critical section of code
// protects whatever is between lock and unlock
mutex gLock;

static int shared_value = 0;

// .lock() locks the mutex, blocks if the mutex is not available
// .try_lock() tries to lock the mutex, return if the mutex is not available
// .unlock()


void shared_value_increment(){
    // anything here will not be protected by locks, can be shared and data race.
    gLock.lock(); // mutex locks
    // protected (atomic or cretical section) code
        shared_value = shared_value + 1;
    // ---
    gLock.unlock();
}

int main(){

    vector<thread> threads;

    // even if called a thousand time, it will always be 1000, without mutex, we may get 999, 998
    // *** prevent data race
    for (int i = 0; i < 1000; i++){
        threads.push_back(thread(shared_value_increment));
    }

    for (int i = 0; i < 1000; i++){
        threads[i].join();
    }

    cout << "Shared Value: " << shared_value << endl;

    return 0;
}