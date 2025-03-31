#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

const int MAX = 11;
int n, m, k;
int A[MAX][MAX];            // 겨울에 추가되는 양분
int field[MAX][MAX];        // 현재 땅에 있는 양분
deque<int> trees[MAX][MAX]; // 각 칸에 존재하는 나무들
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
    FIO;
    cin >> n >> m >> k;

    // 겨울에 뿌릴 양분 A 입력
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> A[i][j];
            field[i][j] = 5;
        }

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        trees[x][y].push_back(z); // 위치 (x, y)에 나이 z인 나무 심기
    }

    while (k--)
    {
        // 봄 + 여름
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (trees[i][j].empty())
                    continue;

                deque<int> new_tree;
                int dead_nutrient = 0;

                sort(trees[i][j].begin(), trees[i][j].end()); // 어린 나무부터 양분 먹기

                for (int age : trees[i][j])
                {
                    if (field[i][j] >= age)
                    {
                        field[i][j] -= age;
                        new_tree.push_back(age + 1);
                    }
                    else
                    {
                        dead_nutrient += age / 2;
                    }
                }

                trees[i][j] = new_tree;
                field[i][j] += dead_nutrient;
            }
        }

        // 가을
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                for (int age : trees[i][j])
                {
                    if (age % 5 == 0)
                    {
                        for (int dir = 0; dir < 8; dir++)
                        {
                            int ni = i + dx[dir];
                            int nj = j + dy[dir];
                            if (ni < 1 || nj < 1 || ni > n || nj > n)
                                continue;
                            trees[ni][nj].push_front(1); // 나이 1인 나무 번식 (어린 나무는 앞에 넣어야 함)
                        }
                    }
                }
            }
        }

        // 겨울
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                field[i][j] += A[i][j];
    }

    int answer = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            answer += trees[i][j].size();

    cout << answer;
}
