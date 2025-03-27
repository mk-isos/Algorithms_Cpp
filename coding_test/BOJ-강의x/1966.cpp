#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for (int i = 0; i < N; ++i)
        {
            int priority;
            cin >> priority;

            q.push({i, priority});
            pq.push(priority);
        }

        int print_order = 0;

        while (!q.empty())
        {
            int index = q.front().first;
            int priority = q.front().second;
            q.pop();

            if (priority == pq.top())
            {
                // 인쇄
                pq.pop();
                print_order++;

                if (index == M)
                {
                    cout << print_order << '\n';
                    break;
                }
            }
            else
            {
                // 뒤로 보내기
                q.push({index, priority});
            }
        }
    }
    return 0;
}
