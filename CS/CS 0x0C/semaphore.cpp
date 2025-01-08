#include <iostream>
#include <thread>
#include <semaphore>
using namespace std;

int counter = 0;
counting_semaphore<1> sem(1);

void increment() {
    for (int i = 0; i < 10000; ++i) {
        sem.acquire();
        counter++;
        sem.release();
    }
}

int main() {
    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();

    cout << "Final Counter Value: " << counter << endl;
    return 0;
}