#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

const int n = 100000; // 테스트 반복 횟수

void testWithEndl(ofstream &file) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        file << i << endl; // endl 사용 (매번 flush)
    }
    auto end = high_resolution_clock::now();
    cout << "Time with endl: " << duration<double>(end - start).count() << "s\n";
    cout.flush(); // 강제 플러시 (터미널에서 사라지는 문제 해결)
}

void testWithNewline(ofstream &file) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        file << i << '\n'; // '\n' 사용 (버퍼링됨)
    }
    auto end = high_resolution_clock::now();
    cout << "Time with \\n: " << duration<double>(end - start).count() << "s\n";
    cout.flush(); // 강제 플러시
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ofstream file1("output_endl.txt");
    ofstream file2("output_newline.txt");

    cout << "Running tests...\n";
    cout.flush(); // 플러시 추가

    // endl 테스트
    testWithEndl(file1);
    file1.close();

    // '\n' 테스트
    testWithNewline(file2);
    file2.close();

    cout << "Tests completed.\n";
    cout.flush(); // 결과가 사라지는 문제 방지

    return 0;
}
