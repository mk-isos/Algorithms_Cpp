#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int N, M, K;
    cin >> N >> M >> K;

    int move = K - 3;
    int current_idx = M - 1;

    int next_idx = (current_idx + move) % N;
    if (next_idx < 0)
        next_idx += N;

    cout << next_idx + 1 << '\n';
    return 0;
}
