#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main(void)
{
    FIO;

    int N, M;
    cin >> N;

    unordered_map<long long, int> war;

    long long maxNum = -1, maxFreq = 0;
    long long num;

    while (N--)
    {
        cin >> M;

        for (int j = 0; j < M; j++)
        {
            cin >> num;
            war[num]++;

            if (war[num] > maxFreq)
            {
                maxFreq = war[num];
                maxNum = num;
            }
        }

        int halfM = M / 2;
        if (maxFreq > halfM)
        {
            cout << maxNum << '\n';
        }
        else
        {
            cout << "SYJKGW" << '\n';
        }
        war.clear();
        maxFreq = 0;
        maxNum = -1;
    }
    return 0;
}