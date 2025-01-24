#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    // 각 문자의 빈도를 저장
    int count1[26] = {0}, count2[26] = {0};

    // 빈도 계산
    for (char c : s1) {
        count1[c - 'a']++;
    }

    // 빈도 계산
    for (char c : s2) {
        count2[c - 'a']++;
    }

    // 개수 계산
    int remove_count = 0;
    for (int i = 0; i < 26; ++i) {
        remove_count += abs(count1[i] - count2[i]);
    }

    cout << remove_count << '\n';

    return 0;
}
