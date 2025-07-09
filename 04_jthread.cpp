#include <iostream>
#include <thread>
#include <vector>
using namespace std;

// g++-15 -std=c++20 -o thread_jthread thread_jthread.cpp
// jthread is C++20 or above
int main(){


    // *** this file will have messy output, because the threads are running all to gether and printing on the same thing (cout)
    auto lamda=[](int x){
        // name space this_thread:: will provide functions that access the current thread
        cout << "Hello from thread " << this_thread::get_id() << endl;
        cout << "Argument: " << x << endl;
    };


    // use of std::jthreads will auto matically call join
    vector<jthread> Jthreads;

    for (int i = 0; i < 10; i++){
        Jthreads.push_back(jthread(lamda, i * 10));
    }

    cout << "hello from main    (Should wait until helper finishes)" << endl;

    return 0;
}