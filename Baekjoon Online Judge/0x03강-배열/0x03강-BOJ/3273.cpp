#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n;

    vector<int> a(n);   // 크기가 n인 int 타입의 벡터 a를 선언하고 초기화
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> x;

    unordered_map<int, int> num_map;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        int complement = x - a[i];
        if (num_map[complement]) {
            count++;
        }
        num_map[a[i]]++;
    }

    cout << count << '\n';
    return 0;
}

// unordered_map<int, int> num_map;
// unordered_map은 키-값 쌍을 저장하는 해시맵 기반의 자료구조
// unordered_map은 정수형 키와 정수형 값을 저장
// 키와 값의 삽입, 검색, 삭제, 존재 여부 확인 등의 기본적인 연산
// 평균적으로 O(1)의 시간 복잡도