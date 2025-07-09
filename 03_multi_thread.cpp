#include <iostream>
#include <thread>
#include <vector>
using namespace std;


int main(){


    // *** this file will have messy output, because the threads are running all to gether and printing on the same thing (cout)
    auto lamda=[](int x){
        // name space this_thread:: will provide functions that access the current thread
        cout << "Hello from thread " << this_thread::get_id() << endl;
        cout << "Argument: " << x << endl;
    };

    vector<thread> threads;

    for (int i = 0; i < 10; i++){
        threads.push_back(thread(lamda, i * 10));
    }

    // we need to .join() in another place other wise we are just launching ten threads one after the other
    for (int i = 0; i < 10; i++){
        threads[i].join();
    }

    cout << "hello from main    (Should wait until helper finishes)" << endl;

    return 0;
}