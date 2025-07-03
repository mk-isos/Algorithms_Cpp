#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    string pattern = "WelcomeToSMUPC";
    int N;
    cin >> N;
    cout << pattern[(N - 1) % pattern.size()] << '\n';
    return 0;
}
