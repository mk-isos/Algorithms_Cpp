#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N, M, x, y, K, command;
int board[21][21];  

int dice[7];      
int dx[5] = {0, 0, 0, -1, 1}; // (dummy, 동, 서, 북, 남)
int dy[5] = {0, 1, -1, 0, 0}; // (dummy, 동, 서, 북, 남)

bool isValid(int nx, int ny) {
    return nx >= 0 && nx < N && ny >= 0 && ny < M;
}

void rollDice(int dir) {
    int temp[7];
    for (int i = 1; i <= 6; i++) temp[i] = dice[i];

    if (dir == 1) { // 동쪽
        dice[2] = temp[5];
        dice[6] = temp[4];
        dice[5] = temp[6];
        dice[4] = temp[2];
    } 
    else if (dir == 2) { // 서쪽
        dice[2] = temp[4];
        dice[6] = temp[5];
        dice[5] = temp[2];
        dice[4] = temp[6];
    } 
    else if (dir == 3) { // 북쪽
        dice[2] = temp[3];
        dice[6] = temp[1];
        dice[3] = temp[6];
        dice[1] = temp[2];
    } 
    else if (dir == 4) { // 남쪽
        dice[2] = temp[1];
        dice[6] = temp[3];
        dice[3] = temp[2];
        dice[1] = temp[6];
    }
}

void move(int dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if (!isValid(nx, ny)) return; // 범위 벗어나면 무시

    x = nx; 
    y = ny;
    rollDice(dir);

    if (board[x][y] == 0) {
        board[x][y] = dice[6]; // 주사위 바닥 값을 지도에 복사
    } else {
        dice[6] = board[x][y]; // 지도 값을 주사위 바닥에 복사
        board[x][y] = 0; // 지도 값 초기화
    }

    cout << dice[2] << '\n'; // 윗면 출력
}


int main()
{
    FIO;

    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];

    while (K--)
    {
        cin >> command;
        move(command);
    }
}