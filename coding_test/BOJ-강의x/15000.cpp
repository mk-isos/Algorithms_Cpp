#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    
    for (char &c : s) {
        c = toupper(c);
    }

    cout << s << "\n";
    return 0;
}

/*
toupper 함수는 
C++ 표준 라이브러리 <cctype>에 정의되어 있으며
소문자 문자를 대문자로 변환해 반환.
*/