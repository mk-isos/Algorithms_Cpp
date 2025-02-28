#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define X first
#define Y second

int N, M;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;

int main()
{
    FIO;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int val;
            cin >> val;

            if (val == 1)
                houses.push_back({i, j});
            else if (val == 2)
                chickens.push_back({i, j});
        }
    }

    // 치킨집 선택을 위한 조합 설정
    vector<int> selection(chickens.size(), 1);
    fill(selection.begin(), selection.begin() + chickens.size() - M, 0); // 앞쪽은 0, 뒤쪽 M개는 1 ex) [0, 0, 0, 1, 1]

    int minCityChickenDist = INT_MAX;

    do
    {
        int cityChickenDist = 0;

        for (auto house : houses)
        {
            int minHouseChickenDist = INT_MAX;

            for (int i = 0; i < chickens.size(); i++)
            {
                if (selection[i] == 0)
                    continue; // 선택되지 않은 치킨집은 패스

                int dist = abs(chickens[i].X - house.X) + abs(chickens[i].Y - house.Y);
                minHouseChickenDist = min(minHouseChickenDist, dist); // 최소 거리 갱신
            }

            cityChickenDist += minHouseChickenDist; // 해당 집의 최소 치킨 거리 누적
        }

        minCityChickenDist = min(minCityChickenDist, cityChickenDist); // 최솟값 갱신

    } while (next_permutation(selection.begin(), selection.end()));

    cout << minCityChickenDist << "\n"; // 최소 치킨 거리 출력

    return 0;
}
