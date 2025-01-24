#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    while (N--) {
        string s1, s2;
        cin >> s1 >> s2;

        // 두 문자열의 길이가 다르면 불가능
        if (s1.length() != s2.length()) {
            cout << "Impossible\n";
            continue;
        }

        // 각 문자의 빈도를 저장하는 배열
        int count1[26] = {0}, count2[26] = {0};

        for (char c : s1) {
            count1[c - 'a']++;
        }
        for (char c : s2) {
            count2[c - 'a']++;
        }

        // 두 배열이 동일한지 확인
        bool possible = true;
        for (int i = 0; i < 26; ++i) {
            if (count1[i] != count2[i]) {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "Possible\n";
        } else {
            cout << "Impossible\n";
        }
    }
    return 0;
}
