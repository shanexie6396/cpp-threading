#include <iostream>
#include <thread>
using namespace std;


int main(){
    // lamda replacing the helper in thread.cpp, doing the samething
    auto lamda=[](int x){
    cout << "Hello from thread!    (Should print before main!)" << endl;
    cout << "Argument: " << x << endl;
    };

    // creating thread with lamda & input 100, note no need adress
    thread myThread(lamda, 100);

    // use .join() to ensure main waits for the thread to finish (avoiding core dump)
    // .join() blocks the current thread (this case main) until the thread (lamda) indetified by *this finishes its exectution
    myThread.join();


    cout << "hello from main    (Should wait until helper finishes)" << endl;

    return 0;
}