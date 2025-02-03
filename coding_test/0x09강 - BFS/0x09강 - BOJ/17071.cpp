#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define X first
#define Y second
using namespace std;

const int MAX = 500000;

int N, K;
bool visited[MAX + 1][2];

int bfs()
{
    queue<pair<int, int>> q;
    q.push({N, 0}); // (현재 위치, 시간)
    visited[N][0] = true;

    while (!q.empty())
    {
        int x = q.front().X;
        int t = q.front().Y;
        q.pop();

        // 동생의 현재 위치 계산
        int bro = K + (t * (t + 1)) / 2;
        if (bro > MAX)
            return -1;
        if (visited[bro][t % 2])
            return t;

        // 다음 이동 후보
        int next_positions[] = {x - 1, x + 1, 2 * x};
        for (int nx : next_positions)
        {
            if (nx >= 0 && nx <= MAX && !visited[nx][(t + 1) % 2])
            {
                visited[nx][(t + 1) % 2] = true;
                q.push({nx, t + 1});
            }
        }
    }
    return -1;
}

int main()
{
    FIO;
    cin >> N >> K;

    if (N == K)
    {
        cout << "0\n";
        return 0;
    }

    cout << bfs() << "\n";
}
