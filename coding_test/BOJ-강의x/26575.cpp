#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << fixed << setprecision(2); // 소수점 둘째 자리까지 고정
    while (n--)
    {
        double d, f, p;
        cin >> d >> f >> p;
        double total = d * f * p;
        cout << "$" << total << endl;
    }
    return 0;
}
