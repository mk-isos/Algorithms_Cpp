#include <bits/stdc++.h>
using namespace std;

int freq[26];   // 알파벳 빈도를 저장하는 배열
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for(auto c : s)
        freq[c-'a']++;  // 문자의 빈도를 계산하여 freq 배열에 저장
    for(int i = 0; i < 26; i++)
        cout << freq[i] << ' ';
}

/*
C++에서 문자는 아스키 코드 값으로 저장됩니다. 예를 들어, 'a'의 아스키 코드 값은 97입니다. 'b'는 98, 'c'는 99, 그리고 'z'는 122입니다.
예를 들어, c가 'b'라면, 'b' - 'a'는 98 - 97이 되어 1이 됩니다. 따라서 freq[1]이 증가
*/