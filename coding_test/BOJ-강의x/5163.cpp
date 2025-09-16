#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int K;
    if (!(cin >> K))
        return 0;
    const long double PI = acosl(-1.0L);
    for (int tc = 1; tc <= K; ++tc)
    {
        int b;
        long double w;
        cin >> b >> w;
        long double vol = 0;
        for (int i = 0; i < b; i++)
        {
            long double r;
            cin >> r;
            vol += (4.0L / 3.0L) * PI * r * r * r;
        }
        long double lift = vol / 1000.0L;
        cout << "Data Set " << tc << ":\n";
        cout << (lift + 1e-12L >= w ? "Yes" : "No") << "\n\n";
    }
}
