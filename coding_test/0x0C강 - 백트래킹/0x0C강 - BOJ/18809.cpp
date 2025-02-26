// 예제 얼추 맞았는데 시간 고려안해서 틀림.. 도저히 더 풀 자신이 없다 다음에 ㄱㄱ

#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N, M, G, R, max_flowers = 0;
int garden[50][50], temp[50][50];
vector<pair<int, int>> fertile_land; // 배양액을 뿌릴 수 있는 땅
vector<int> colors;                  // 0: 선택 안함, 1: 초록, 2: 빨강
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs()
{
    queue<pair<int, int>> q;
    int flower_count = 0;
    memset(temp, -1, sizeof(temp));

    for (int i = 0; i < fertile_land.size(); i++)
    {
        if (colors[i] > 0)
        { // 초록(1) 또는 빨강(2)인 경우 배양액 뿌리기
            int x = fertile_land[i].first, y = fertile_land[i].second;
            temp[x][y] = colors[i]; // 1: 초록, 2: 빨강
            q.push({x, y});
        }
    }

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        if (temp[x][y] == 3)
            continue; // 꽃이 피면 확산 중단

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M || garden[nx][ny] == 0)
                continue;
            if (temp[nx][ny] == -1)
            {
                temp[nx][ny] = temp[x][y];
                q.push({nx, ny});
            }
            else if (temp[nx][ny] + temp[x][y] == 3)
            { // 초록과 빨강이 동시에 도달하면 꽃이 핌
                flower_count++;
                temp[nx][ny] = 3;
            }
        }
    }
    max_flowers = max(max_flowers, flower_count);
}

void place_liquids(int idx, int green, int red)
{
    if (green == G && red == R)
    {          // 모든 배양액을 사용
        bfs(); // BFS 실행하여 꽃 개수 계산
        return;
    }

    if (idx >= fertile_land.size())
        return; // 모든 땅을 탐색했을 경우 종료

    // 초록색 배양액 배치
    if (green < G)
    {
        colors[idx] = 1;
        place_liquids(idx + 1, green + 1, red);
        colors[idx] = 0;
    }

    // 빨간색 배양액 배치
    if (red < R)
    {
        colors[idx] = 2;
        place_liquids(idx + 1, green, red + 1);
        colors[idx] = 0;
    }

    // 배양액을 배치하지 않는 경우
    place_liquids(idx + 1, green, red);
}

int main()
{
    FIO;
    cin >> N >> M >> G >> R;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> garden[i][j];
            if (garden[i][j] == 2)
                fertile_land.push_back({i, j});
        }
    }

    colors.resize(fertile_land.size(), 0);
    place_liquids(0, 0, 0); // 배양액 배치 시작
    cout << max_flowers << "\n";

    return 0;
}
