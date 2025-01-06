#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        cout << "자식 프로세스 실행\n";
    } else {
        cout << "부모 프로세스 실행\n";
    }
    return 0;
}
