#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int board[502][502] =
    {{1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
     {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
     {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
     {1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
     {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}; // 1이 파란 칸, 0이 빨간 칸에 대응

bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장

int n = 7, m = 10; // n = 행의 수, m = 열의 수

//dx,dy 


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int,int>> Q;

    vis[0][0] = 1;
    Q.push({0,0});

    while(!Q.empty()) {
        pair<int,int> cur = Q.front; Q.pop;
        cout << '(' << cur.X << ", " << cur.Y << ") -> ";

        
    }
}