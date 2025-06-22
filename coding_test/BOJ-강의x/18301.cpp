#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int n1, n2, n12;
    cin >> n1 >> n2 >> n12;

    int N = ((n1 + 1) * (n2 + 1)) / (n12 + 1) - 1;
    cout << N << '\n';
}
