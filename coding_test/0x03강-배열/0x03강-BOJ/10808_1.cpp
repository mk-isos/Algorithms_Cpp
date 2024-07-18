#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);    // C++ 표준 입출력 속도를 향상시키기
    cin.tie(0); // cin과 cout의 묶음을 풀어줌으로써 입력과 출력의 성능을 높이기
    string s;
    cin >> s;
    for(char a = 'a'; a <= 'z'; a++){
        int cnt = 0;
        for(auto c : s) // 문자열 s의 각 문자를 c에 저장하며 반복
        if(a == c) cnt++;
        cout << cnt << ' ';
    }
}