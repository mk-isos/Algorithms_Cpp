#include <iostream>
#include <csignal>
using namespace std;

void signalHandler(int signum) {
    cout << "Interrupt signal (" << signum << ") received.\n";
    exit(signum);
}

int main() {
    signal(SIGINT, signalHandler);
    cout << "Press Ctrl+C to trigger an interrupt." << endl;
    while (true);
    return 0;
}