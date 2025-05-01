#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int N, M;
    cin >> N >> M;

    unordered_map<string, string> passwordMap;

    for (int i = 0; i < N; i++)
    {
        string site, password;
        cin >> site >> password;
        passwordMap[site] = password;
    }

    for (int i = 0; i < M; i++)
    {
        string query;
        cin >> query;
        cout << passwordMap[query] << '\n';
    }
}
