#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

// NOTES:
// Preventing deadlock with std::lock_guard in modern C++
// Deadlock is when you lock and forgot to unlock, 
// the lock is dead and whatever is protected by the mutex is not accessable
// Use lock_guard to auto do that for you

//** lock_gaurd<T> needs a lockable type (with .lock() & .unlock() ), usually mutex, so no int, string */

mutex gLock;

static int shared_value = 0;

void shared_value_increment(){
    lock_guard<mutex> Gaurd(gLock);
    shared_value = shared_value + 1;
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