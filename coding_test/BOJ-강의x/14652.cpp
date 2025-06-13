#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int N, M;
    long long K;
    cin >> N >> M >> K;

    int row = K / M;
    int col = K % M;

    cout << row << " " << col << '\n';
}
