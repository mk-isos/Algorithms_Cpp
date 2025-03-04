#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

string board[12];
bool vis[12][6];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

// BFS로 같은 색 뿌요 찾기
vector<pair<int, int>> bfs(int x, int y, char color) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> puyoList; // 연결된 뿌요 좌표 저장

    q.push({x, y});
    puyoList.push_back({x, y});
    vis[x][y] = true;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue; // 범위 벗어나면 패스
            if (vis[nx][ny] || board[nx][ny] != color) continue; // 방문했거나 색 다르면 패스

            vis[nx][ny] = true;
            q.push({nx, ny});
            puyoList.push_back({nx, ny});
        }
    }

    return puyoList; // 연결된 뿌요 좌표 반환
}

// 터뜨리기 함수
bool removePuyo() {
    memset(vis, false, sizeof(vis)); 
    bool isPopped = false; 

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            if (board[i][j] != '.' && !vis[i][j]) { // 뿌요가 있고 방문하지 않은 경우
                vector<pair<int, int>> puyoList = bfs(i, j, board[i][j]);

                if (puyoList.size() >= 4) { 
                    isPopped = true;
                    for (auto [x, y] : puyoList) {
                        board[x][y] = '.'; 
                    }
                }
            }
        }
    }
    return isPopped; 
}

void applyGravity() {
    for (int col = 0; col < 6; col++) {
        for (int row = 10; row >= 0; row--) { 
            if (board[row][col] == '.') continue; // 빈 칸이면 패스

            int newRow = row;
            while (newRow + 1 < 12 && board[newRow + 1][col] == '.') { 
                swap(board[newRow][col], board[newRow + 1][col]); // 아래로 이동
                newRow++;
            }
        }
    }
}


int main()
{
    FIO;

    for (int i = 0; i < 12; ++i)
        cin >> board[i];

    int chainCount = 0; 

    while (removePuyo()) { // 뿌요가 터질 동안 반복
        applyGravity(); // 중력 적용
        chainCount++; // 연쇄 횟수 증가
    }

    cout << chainCount << '\n'; 
}