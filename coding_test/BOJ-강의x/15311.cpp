#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int N;
    cin >> N;

    // m = ceil(sqrt(N))로 결정 (N의 제곱근보다 작으면 올림)
    int m = sqrt(N);
    if (m * m < N)
        m++;

    // 필요한 봉지의 개수 K = 2*m - 1
    int K = 2 * m - 1;
    cout << K << "\n";

    // 첫 m개의 봉지에는 1알씩 채우고
    for (int i = 0; i < m; i++)
    {
        cout << 1 << " ";
    }
    // 다음 m-1개의 봉지에는 m알씩 채우기
    for (int i = 0; i < m - 1; i++)
    {
        cout << m << (i == m - 2 ? "\n" : " ");
    }

    return 0;
}