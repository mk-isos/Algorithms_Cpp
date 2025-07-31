#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    cout << fixed << setprecision(10); // 소수점 10자리까지 정확도 보장

    int N;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    double V = 0.0; // 초기 방무 수치 0%
    for (int i = 0; i < N; ++i)
    {
        double Ai = A[i] / 100.0;
        V = 1.0 - (1.0 - V) * (1.0 - Ai);
        cout << V * 100.0 << '\n';
    }

    return 0;
}
