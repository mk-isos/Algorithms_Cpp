#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n, w, L;
queue<int> trucks;            // 대기 중인 트럭
deque<pair<int, int>> bridge; // 현재 다리 위에 있는 트럭 (올라간 시간, 무게)
int bridgeWeight = 0;         // 현재 다리 위 총 무게

int main()
{
    FIO;
    cin >> n >> w >> L;

    for (int i = 0; i < n; i++)
    {
        int weight;
        cin >> weight;
        trucks.push(weight);
    }

    int time = 0;

    while (!trucks.empty() || !bridge.empty())
    { // 모든 트럭이 다리를 건널 때까지!!
        time++;

        // 1️. 다리에서 트럭이 나갈 시간이 되면 제거
        if (!bridge.empty() && time - bridge.front().first == w)
        {
            bridgeWeight -= bridge.front().second; // 다리 무게 감소
            bridge.pop_front();                    // 가장 오래된 트럭 제거
        }

        // 2️. 새로운 트럭이 올라갈 수 있는지 확인
        if (!trucks.empty() && bridgeWeight + trucks.front() <= L)
        {
            int newTruck = trucks.front();
            trucks.pop();

            bridge.push_back({time, newTruck}); // (현재 시간, 트럭 무게)
            bridgeWeight += newTruck;
        }
    }

    cout << time << '\n';
}
