//BOJ 10093풀다가 int ,long long 직접 출력해보고 싶어짐.

#include <iostream>
using namespace std;

int main() {
    int a = 2147483647; // int의 최대값
    long long b = 9223372036854775807LL; // long long의 최대값

    cout << "int a: " << a << endl;
    cout << "long long b: " << b << endl;

    // int 오버플로우 예시
    a += 1;
    cout << "int a 오버플로우 후: " << a << endl; // 오버플로우 발생

    // long long 오버플로우 예시 (가장 큰 값에 1을 더하면 오버플로우 발생)
    b += 1;
    cout << "long long b 오버플로우 후: " << b << endl; // 오버플로우 발생

    return 0;
}

/*
int는 4바이트 크기의 정수 타입으로, 범위는 약 -2.1억 ~ 2.1억입니다.
long long은 8바이트 크기의 정수 타입으로, 범위는 약 -9.2경 ~ 9.2경입니다.
int는 메모리 사용이 적고 빠른 반면, long long은 매우 큰 정수 값을 다룰 수 있습니다.
*/