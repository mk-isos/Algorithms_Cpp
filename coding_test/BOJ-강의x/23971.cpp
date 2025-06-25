#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int H, W, N, M;
    cin >> H >> W >> N >> M;

    int row = (H + N) / (N + 1);
    int col = (W + M) / (M + 1);

    cout << row * col << '\n';
}
