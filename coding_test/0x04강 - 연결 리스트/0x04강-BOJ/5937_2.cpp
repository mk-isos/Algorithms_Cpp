// Authored by : BaaaaaaaaaaarkingDog

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        list<char> L = {};
        string s;
        auto p = L.begin();

        cin >> s;
        
        for (auto c : s) {
        if (c == '<') {
            if (p != L.begin()) p--;
        }
        else if (c == '>') {
            if (p != L.end()) p++;
        }
        else if (c == '-') {
            if (p != L.begin()) {
            p--;
            p = L.erase(p);
            }
        }
        else
            L.insert(p, c);      
        }
        for (auto c : L) cout << c;
        cout << '\n';
    }
}

/*
두 풀이의 차이점:

1. 변수 이름:
   - 바킹독님의 풀이:
     - `n` : 테스트 케이스의 수
     - `L` : 리스트를 저장하는 변수
     - `p` : 커서 위치를 나타내는 반복자
   - 나의 풀이:
     - `T` : 테스트 케이스의 수
     - `password` : 리스트를 저장하는 변수
     - `cursor` : 커서 위치를 나타내는 반복자

2. 코드 구조:
   - 바킹독님의 풀이:
     - 테스트 케이스마다 리스트와 반복자를 초기화.
     - 문자열을 입력받고 문자 하나씩 처리.
     - 커서 이동 및 삽입, 삭제를 처리.
     - 처리된 리스트를 출력.
   - 나의 풀이:
     - while 루프를 사용하여 테스트 케이스 처리.
     - 문자열을 입력받고 문자 하나씩 처리.
     - 커서 이동 및 삽입, 삭제를 처리.
     - 처리된 리스트를 출력.

3. 로직의 차이:
   - 바킹독님의 풀이:
     - 커서가 L.begin()이 아닐 때만 커서를 이동하거나 문자를 삭제.
     - 삭제 시 p-- 후 L.erase(p)로 커서를 조정하고 삭제.
   - 나의 풀이:
     - 커서가 password.begin()이 아닐 때만 커서를 이동하거나 문자를 삭제.
     - 삭제 시 cursor = password.erase(--cursor)로 커서를 조정하고 삭제.

4. 리스트 초기화:
   - 바킹독님의 풀이:
     list<char> L = {};
   - 나의 풀이:
     list<char> password;

5. 문자열 입력 방식:
   - 바킹독님의 풀이:
     cin >> s;
   - 나의 풀이:
     cin >> input;
*/