#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    queue<pair<int, int>> q;
    int time = 0, cur = 0, i = 0, n = (int)truck_weights.size();

    while (i < n || !q.empty())
    {
        time++;

        if (!q.empty() && q.front().second == time)
        {
            cur -= q.front().first;
            q.pop();
        }

        if (i < n)
        {
            if ((int)q.size() < bridge_length && cur + truck_weights[i] <= weight)
            {
                cur += truck_weights[i];
                q.push({truck_weights[i], time + bridge_length});
                i++;
            }
        }
    }
    return time;
}
