#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define X first
#define Y second

using namespace std;

int N;
stack<pair<int, int>> tower;

int main()
{
    FIO;

    cin >> N;
    tower.push({100000001, 0});
    for (int i = 1; i <= N; i++)
    {
        int height;
        cin >> height;
        while (tower.top().X < height)
            tower.pop();
        cout << tower.top().Y << " ";
        tower.push({height, i});
    }
}