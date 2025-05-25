#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int T;
    cin >> T;
    cout << fixed << setprecision(3);

    while (T--)
    {
        int N;
        cin >> N;
        vector<int> scores(N);
        int sum = 0;

        for (int i = 0; i < N; ++i)
        {
            cin >> scores[i];
            sum += scores[i];
        }

        double avg = (double)sum / N;
        int count = 0;

        for (int i = 0; i < N; ++i)
        {
            if (scores[i] > avg)
                count++;
        }

        double result = (double)count / N * 100.0;
        cout << result << "%" << '\n';
    }

    return 0;
}
