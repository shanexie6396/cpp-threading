#include <iostream>
#include <mutex>
#include <chrono>
#include <condition_variable>

using namespace std;

// Notes
// incentives: since having the threads to check and wait all the time is computation heavy,
// we can use unique_lock and std::condition_variable to allow the thread to wait until notify.
// unique meaning: It has unique ownership of the mutex it’s managing.

// ?? Why unique_lock ??
// mutex        =  the raw lock tool (you manage everything yourself)
// lock_guard   =  automatic, simple, safe (no manual unlocks, no flexibility)
// unique_lock  =  automatic but flexible (auto lock/unlock + manual control if needed)

// condition_variable::wait() needs something that can be unlocked and relocked safely while it waits.
// ** Only unique_lock provides that interface.

mutex gLock;
int global_value = 0;
bool work_is_done = false;
condition_variable gCondition;


int main (){

    thread waiting_thread([&]{
        unique_lock<mutex> uni_lock(gLock);
        if (!work_is_done){
            cout << "[] waiting for working thread to finish, expect 5 seconds!" << endl;
            // wait until the lock is free
            gCondition.wait(uni_lock);
        }
        cout << "[] reporting: The resulting global value is " << global_value << endl;
    });



    thread working_thread([&]{
        unique_lock<mutex> uni_lock(gLock);
        this_thread::sleep_for(chrono::seconds(5));\

        // Do the work
        global_value  = global_value + 2 + 48;
        
        work_is_done = true;
        cout << "[] work is done from working thread" << endl;

        // notify the thread waiting for the condition variable
        gCondition.notify_one();
    });


    waiting_thread.join();
    working_thread.join();

    return 0;
}