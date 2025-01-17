#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int main(void){
    FIO;

    string init;
    cin >> init;

    // 초기 문자
    list<char> L;
    for(auto c : init) L.push_back(c);
    auto cursor = L.end();

    // 명령 개수
    int q;
    cin >> q;
    while(q--) {
        char op;
        cin >> op;

        if(op == 'P') {
            char add;
            cin >> add;
            L.insert(cursor, add);
        }
        else if (op=='L') {
            if(cursor != L.begin()) cursor--;
        }
        else if (op=='D') {
            if(cursor != L.end()) cursor++;
        }
        else {
            if(cursor != L.begin()) {
                cursor--;
                cursor = L.erase(cursor);
            }
        }
    }

    for (auto c : L) cout << c;
}