#include <iostream>
#include <thread>
using namespace std;

void printMessage() {
    cout << "스레드 실행 중\n";
}

int main() {
    thread t1(printMessage);
    t1.join();
    return 0;
}
