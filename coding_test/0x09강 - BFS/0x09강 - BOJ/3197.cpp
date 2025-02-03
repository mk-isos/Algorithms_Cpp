// 플레 나중에 다시..

// 풀이 1 시간 초과

/*

#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int R, C;
vector<string> lake;
queue<pair<int, int>> waterQueue, nextWaterQueue;
pair<int, int> swans[2];
bool visited[1500][1500];
bool swanVisited[1500][1500];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// 물 공간 확장
void meltIce() {
    while (!waterQueue.empty()) {
        auto [x, y] = waterQueue.front();
        waterQueue.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (lake[nx][ny] == 'X') {
                lake[nx][ny] = '.';
                nextWaterQueue.push({nx, ny});
            }
        }
    }
}

// 백조 경로 탐색
bool canSwansMeet() {
    queue<pair<int, int>> swanQueue;
    memset(swanVisited, 0, sizeof(swanVisited));
    swanQueue.push(swans[0]);
    swanVisited[swans[0].first][swans[0].second] = true;

    while (!swanQueue.empty()) {
        auto [x, y] = swanQueue.front();
        swanQueue.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (swanVisited[nx][ny]) continue;

            if (lake[nx][ny] == '.') {
                swanQueue.push({nx, ny});
            } else if (lake[nx][ny] == 'X') {
                nextWaterQueue.push({nx, ny});
            }
            swanVisited[nx][ny] = true;

            // 두 번째 백조에 도달하면 만남 가능
            if (nx == swans[1].first && ny == swans[1].second) return true;
        }
    }
    return false;
}

int main() {
    FIO;
    cin >> R >> C;
    lake.resize(R);

    int swanCount = 0;
    for (int i = 0; i < R; ++i) {
        cin >> lake[i];
        for (int j = 0; j < C; ++j) {
            if (lake[i][j] == 'L') {
                swans[swanCount++] = {i, j};
                lake[i][j] = '.';
            }
            if (lake[i][j] == '.') {
                waterQueue.push({i, j});
            }
        }
    }

    int days = 0;
    while (true) {
        if (canSwansMeet()) {
            cout << days << '\n';
            break;
        }
        meltIce();
        waterQueue = nextWaterQueue;
        while (!nextWaterQueue.empty()) nextWaterQueue.pop();
        days++;
    }

    return 0;
}


*/

// 풀이 2

#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int R, C;
vector<string> grid;
pair<int, int> swanStart, swanEnd;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    FIO;
    cin >> R >> C;
    grid.resize(R);

    // 백조 위치 저장 및 입력 받기
    vector<pair<int, int>> swans;
    for (int i = 0; i < R; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < C; j++)
        {
            if (grid[i][j] == 'L')
            {
                swans.push_back({i, j});
            }
        }
    }
    // 백조 두 마리의 위치 지정
    swanStart = swans[0];
    swanEnd = swans[1];

    // 물(및 백조가 있는 칸) 녹이기 위한 BFS 준비
    queue<pair<int, int>> waterQ, nextWaterQ;
    vector<vector<bool>> waterVisited(R, vector<bool>(C, false));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (grid[i][j] == '.' || grid[i][j] == 'L')
            {
                waterQ.push({i, j});
                waterVisited[i][j] = true;
            }
        }
    }

    // 백조 이동 BFS 준비
    queue<pair<int, int>> swanQ, nextSwanQ;
    vector<vector<bool>> swanVisited(R, vector<bool>(C, false));
    swanQ.push(swanStart);
    swanVisited[swanStart.first][swanStart.second] = true;

    int days = 0;
    bool meet = false;

    // 시뮬레이션: 백조가 만날 때까지 반복
    while (!meet)
    {
        // 백조 이동 BFS 진행
        while (!swanQ.empty() && !meet)
        {
            auto cur = swanQ.front();
            swanQ.pop();
            int x = cur.first, y = cur.second;
            // 두 번째 백조를 만난 경우
            if (x == swanEnd.first && y == swanEnd.second)
            {
                meet = true;
                break;
            }
            // 상하좌우 탐색
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                    continue;
                if (swanVisited[nx][ny])
                    continue;
                swanVisited[nx][ny] = true;
                // 물이면 바로 이동
                if (grid[nx][ny] == '.' || grid[nx][ny] == 'L')
                {
                    swanQ.push({nx, ny});
                }
                // 얼음이면, 다음 날 녹은 후에 이동할 후보로 저장
                else if (grid[nx][ny] == 'X')
                {
                    nextSwanQ.push({nx, ny});
                }
            }
        }

        // 만난 경우 while 종료
        if (meet)
            break;

        // 하루 지남 -> 얼음 녹이기 BFS 진행
        days++;
        while (!waterQ.empty())
        {
            auto cur = waterQ.front();
            waterQ.pop();
            int x = cur.first, y = cur.second;
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                    continue;
                if (waterVisited[nx][ny])
                    continue;
                // 인접한 칸이 얼음이면 녹임
                if (grid[nx][ny] == 'X')
                {
                    grid[nx][ny] = '.';
                    waterVisited[nx][ny] = true;
                    nextWaterQ.push({nx, ny});
                }
            }
        }
        // 다음 날을 위한 물 큐 갱신
        swap(waterQ, nextWaterQ);

        // 백조 BFS 후보 업데이트: 다음 날 녹은 얼음을 포함
        swap(swanQ, nextSwanQ);
    }

    cout << days;
    return 0;
}
