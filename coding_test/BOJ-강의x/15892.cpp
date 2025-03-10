#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

const int r = 31;
const int M = 1234567891;

int main()
{
    FIO;

    int L;
    string s;
    cin >> L >> s;

    long long hash_value = 0;
    long long power = 1; // r^i를 계산할 변수

    for (int i = 0; i < L; i++)
    {
        int a_i = s[i] - 'a' + 1; // 문자 값을 숫자로 변환
        hash_value = (hash_value + a_i * power) % M;
        power = (power * r) % M; // r^i 값 업데이트 (모듈러 연산)
    }

    cout << hash_value << "\n";
    return 0;
}
