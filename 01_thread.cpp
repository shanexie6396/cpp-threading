#include <iostream>
#include <thread>
using namespace std;

void helper (int x){
    cout << "Hello from thread!    (Should print before main!)" << endl;
    cout << "Argument: " << x << endl;
}


int main(){

    // creating thread with function test's adress & input 100
    thread myThread(&helper, 100);

    // use .join() to ensure main waits for the thread to finish (avoiding core dump)
    // You can use .detach() to run it on its own and away from main thread as well.
    // .join() blocks the current thread (this case main) until the thread (helper) indetified by *this finishes its exectution
    myThread.join();


    cout << "hello from main    (Should wait until helper finishes)" << endl;

    return 0;
}