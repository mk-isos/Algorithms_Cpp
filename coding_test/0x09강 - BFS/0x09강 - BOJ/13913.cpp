#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n, k;
int dist[200002];     // 최단 시간 저장
int prev_pos[200002]; // 이전 위치 저장

int main()
{
    FIO;

    cin >> n >> k;
    int MX = 200000;
    fill(dist, dist + MX, -1);

    queue<int> q;
    q.push(n);
    dist[n] = 0;
    prev_pos[n] = -1; // 시작점은 이전 위치가 없음

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == k)
            break;

        for (int nxt : {cur - 1, cur + 1, 2 * cur})
        {
            if (nxt < 0 || nxt >= MX || dist[nxt] != -1)
                continue;
            dist[nxt] = dist[cur] + 1;
            prev_pos[nxt] = cur; // 이전 위치 저장
            q.push(nxt);
        }
    }

    cout << dist[k] << '\n';

    // 2. 경로 역추적 후 출력
    vector<int> path;
    for (int i = k; i != -1; i = prev_pos[i])
    {
        path.push_back(i);
    }
    reverse(path.begin(), path.end());

    for (int p : path)
        cout << p << " ";
}

/*

prev[]를 배열로 선언했지만, C++ 표준 라이브러리에도 std::prev()라는 함수가 존재함.
#include <bits/stdc++.h>를 사용하면 <iterator> 헤더가 포함되면서 std::prev()가 자동으로 로드됨.
따라서 prev[n]을 사용할 때 C++ 표준 라이브러리의 std::prev()와 충돌하여 ambiguous(모호한) 에러 발생.

*/