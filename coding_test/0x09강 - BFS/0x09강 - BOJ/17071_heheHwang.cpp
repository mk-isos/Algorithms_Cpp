// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/884a292d995243cd92d78c1f1dde977b

#include <bits/stdc++.h>
using namespace std;

const int LMT = 500'000;
int board[LMT + 2];
int vis[2][LMT + 2];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int bro, sis, ans = 0;
    queue<pair<int, int>> Q;
    cin >> sis >> bro;
    Q.push({sis, 0});
    for (int i = 0; i < 2; i++)
        fill(vis[i], vis[i] + LMT + 2, -1);
    vis[0][sis] = 0;
    while (!Q.empty())
    {
        int v, vt, nvt;
        tie(v, vt) = Q.front();
        nvt = vt + 1;
        Q.pop();
        for (int nv : {2 * v, v + 1, v - 1})
        {
            if (nv < 0 || LMT < nv)
                continue;
            if (vis[nvt % 2][nv] != -1)
                continue;
            vis[nvt % 2][nv] = nvt;
            Q.push({nv, nvt});
        }
    }
    bool found = false;
    while (bro <= LMT)
    {
        if (vis[ans % 2][bro] <= ans)
        {
            found = true;
            break;
        }
        bro += ++ans;
    }
    if (found)
        cout << ans;
    else
        cout << -1;
}

/*
이코드 보다 내코드가 메모리를 덜 씀 (수식을 직접계산해서 그런가 )

방문 체크 방식:
내 코드는 true/false만 체크.
제공된 코드는 int 값으로 저장하여 더 유연한 경로 탐색이 가능.

동생 위치 계산:
내 코드는 수식으로 계산 (더 효율적일 가능성 있음).
제공된 코드는 반복문을 이용해 직접 계산 (더 직관적).

BFS 탐색 종료:
내 코드는 BFS 중 즉시 종료 가능.
제공된 코드는 후처리 방식.

*/