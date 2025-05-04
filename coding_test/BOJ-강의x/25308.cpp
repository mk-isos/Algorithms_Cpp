#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
typedef long long ll;

int ans = 0;
ll arr[8];
bool visited[8];
vector<ll> vec;

bool anglechk(ll &x, ll &y, ll &z)
{
    return (x + z) * (x + z) * y * y >= 2 * x * x * z * z;
}

void func(int cnt)
{
    if (cnt == 8)
    {
        if (anglechk(vec[0], vec[1], vec[2]) &&
            anglechk(vec[1], vec[2], vec[3]) &&
            anglechk(vec[2], vec[3], vec[4]) &&
            anglechk(vec[3], vec[4], vec[5]) &&
            anglechk(vec[4], vec[5], vec[6]) &&
            anglechk(vec[5], vec[6], vec[7]) &&
            anglechk(vec[6], vec[7], vec[0]) &&
            anglechk(vec[7], vec[0], vec[1]))
            ans++;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        if (visited[i])
            continue;
        visited[i] = 1;
        vec.emplace_back(arr[i]);
        func(cnt + 1);
        vec.pop_back();
        visited[i] = 0;
    }
}

int main()
{
    FIO;

    for (int i = 0; i < 8; i++)
        cin >> arr[i];

    func(0);

    cout << ans;
}