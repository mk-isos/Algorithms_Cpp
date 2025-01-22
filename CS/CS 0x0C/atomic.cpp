#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

atomic<int> counter(0);

void increment() {
    for (int i = 0; i < 10000; ++i) {
        counter.fetch_add(1);
    }
}

int main() {
    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();

    cout << "Final Counter Value: " << counter.load() << endl;
    return 0;
}