#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string N;
    cin >> N;

    int counts[10] = {0}; // 각 숫자의 빈도를 저장

    // 방 번호의 각 숫자의 빈도를 계산
    for (char c : N) {
        counts[c - '0']++;  //c - '0': 문자를 숫자로 변환하는 방법
    }

    // 6과 9를 합쳐서 계산
    int sixNineCount = counts[6] + counts[9];
    counts[6] = counts[9] = (sixNineCount + 1) / 2; // +1의 이유 : 6과 9의 총 개수가 5인 경우, (5 + 1) / 2 = 3이 되어 3개의 세트가 필요

    // 필요한 세트의 최대값을 계산
    int maxCount = *max_element(counts, counts + 10);   //헤더 파일: max_element 함수는 <algorithm> 헤더 파일에 정의
    
    cout << maxCount << endl;

    return 0;
}
