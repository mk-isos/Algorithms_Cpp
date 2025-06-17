#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int r, c, t;
int room[50][50];
int cleaner_top = -1, cleaner_bottom = -1;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };



void dust_spread() {
    int temp[50][50] = {0}; // 확산 결과 저장용

    for(int i = 0; i < r; i++) {
        for(int j=0; j < c; j++) {
            if(room[i][j] > 0) {
                int spread_amount = room[i][j] / 5;
                int count = 0;

                for(int d = 0; d < 4; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];

                    if(ni>=0 && ni < r && nj>=0 && nj < c && room[ni][nj] != -1) {
                        temp[ni][nj] += spread_amount;
                        count++;
                    }
                }

                room[i][j] -= spread_amount * count;
                
            }
        }
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            room[i][j] += temp[i][j];
        }
    }
}
void air_cleaner() {
    int top = cleaner_top;
    int bottom = cleaner_bottom;

    // 위쪽: 반시계
    for (int i = top - 1; i > 0; i--) room[i][0] = room[i - 1][0];         // 아래
    for (int j = 0; j < c - 1; j++) room[0][j] = room[0][j + 1];           // 왼쪽
    for (int i = 0; i < top; i++) room[i][c - 1] = room[i + 1][c - 1];     // 위
    for (int j = c - 1; j > 1; j--) room[top][j] = room[top][j - 1];       // 오른쪽
    room[top][1] = 0;

    // 아래쪽: 시계
    for (int i = bottom + 1; i < r - 1; i++) room[i][0] = room[i + 1][0];      // 위
    for (int j = 0; j < c - 1; j++) room[r - 1][j] = room[r - 1][j + 1];       // 왼쪽
    for (int i = r - 1; i > bottom; i--) room[i][c - 1] = room[i - 1][c - 1];  // 아래
    for (int j = c - 1; j > 1; j--) room[bottom][j] = room[bottom][j - 1];     // 오른쪽
    room[bottom][1] = 0;
}


int dust_sum() {
    int total = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(room[i][j] > 0) total += room[i][j];
        }
    }
    return total;
}

int main(){

    FIO;

    cin >> r >> c >> t;

    for(int i=0; i<r; i++ ){
        for(int j=0; j < c; j++){
            cin >> room[i][j];
            if(room[i][j] == -1){
                if(cleaner_top == -1) cleaner_top = i;
                else cleaner_bottom = i;
            }
            
        }
    }

    while(t--) {
        dust_spread();
        air_cleaner();
    }

    cout << dust_sum();

}
