#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

char cube[6][3][3];
char color[] = {'w', 'y', 'r', 'o', 'g', 'b'}; // UP, DOWN, FRONT, BACK, LEFT, RIGHT

void initCube() {
    for (int f = 0; f < 6; f++)
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cube[f][i][j] = color[f];
}

void rotateFace(int face, bool clockwise) {
    char temp[3][3];

    // 시계 방향 회전 1번 또는 반시계 방향 회전은 3번 회전
    int rot = clockwise ? 1 : 3;

    while (rot--) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                temp[j][2 - i] = cube[face][i][j];
        memcpy(cube[face], temp, sizeof(temp));
    }
}

void rotateSide(int face, bool clockwise) {
    rotateFace(face, clockwise);  // 해당 면 자체 회전

    int rot = clockwise ? 1 : 3; // 반시계는 시계로 3번 돌리기

    while (rot--) {
        if (face == 2) { // FRONT
            for (int i = 0; i < 3; i++) {
                char temp = cube[0][2][i]; // UP 아래줄
                cube[0][2][i] = cube[4][2 - i][2]; // LEFT 오른쪽 열 -> 위
                cube[4][2 - i][2] = cube[1][0][2 - i]; // DOWN 윗줄 -> 왼쪽
                cube[1][0][2 - i] = cube[5][i][0]; // RIGHT 왼쪽열 -> 아래
                cube[5][i][0] = temp; // 위에서 받아온 값 -> 오른쪽
            }
        }
        else if (face == 3) { // BACK
            for (int i = 0; i < 3; i++) {
                char temp = cube[0][0][i];
                cube[0][0][i] = cube[5][i][2];
                cube[5][i][2] = cube[1][2][2 - i];
                cube[1][2][2 - i] = cube[4][2 - i][0];
                cube[4][2 - i][0] = temp;
            }
        }
        else if (face == 4) { // LEFT
            for (int i = 0; i < 3; i++) {
                char temp = cube[0][i][0];
                cube[0][i][0] = cube[3][i][0];
                cube[3][i][0] = cube[1][i][0];
                cube[1][i][0] = cube[2][i][0];
                cube[2][i][0] = temp;
            }
        }
        else if (face == 5) { // RIGHT
            for (int i = 0; i < 3; i++) {
                char temp = cube[0][i][2];
                cube[0][i][2] = cube[2][i][2];
                cube[2][i][2] = cube[1][i][2];
                cube[1][i][2] = cube[3][i][2];
                cube[3][i][2] = temp;
            }
        }
        else if (face == 0) { // UP
            for (int i = 0; i < 3; i++) {
                char temp = cube[2][0][i];
                cube[2][0][i] = cube[5][0][i];
                cube[5][0][i] = cube[3][2][2 - i];
                cube[3][2][2 - i] = cube[4][0][i];
                cube[4][0][i] = temp;
            }
        }
        else if (face == 1) { // DOWN
            for (int i = 0; i < 3; i++) {
                char temp = cube[2][2][i];
                cube[2][2][i] = cube[4][2][i];
                cube[4][2][i] = cube[3][0][2 - i];
                cube[3][0][2 - i] = cube[5][2][i];
                cube[5][2][i] = temp;
            }
        }
    }
}

int getFaceIndex(char c) {
    if (c == 'U') return 0;
    if (c == 'D') return 1;
    if (c == 'F') return 2;
    if (c == 'B') return 3;
    if (c == 'L') return 4;
    return 5; // 'R'
}

int main() {
    FIO;
    int T;
    cin >> T;
    while (T--) {
        initCube(); // 큐브 초기화
        int n;
        cin >> n;
        while (n--) {
            string cmd;
            cin >> cmd;
            int face = getFaceIndex(cmd[0]);
            bool clockwise = (cmd[1] == '+');
            rotateSide(face, clockwise);
        }

        // 윗면 출력
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cout << cube[0][i][j];
            cout << '\n';
        }
    }
}
