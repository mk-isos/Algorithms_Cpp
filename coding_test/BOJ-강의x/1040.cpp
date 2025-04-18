#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

// N에 사용된 서로 다른 숫자 종류 개수
int numkind(const string &N)
{
    set<char> s(N.begin(), N.end());
    return s.size();
}

// N에서 사용된 숫자/사용하지 않은 숫자 리스트 구하기
pair<vector<int>, vector<int>> numList(const string &N)
{
    vector<int> tmp(10, 0);
    for (char c : N)
        tmp[c - '0'] = 1;
    vector<int> unused, used;
    for (int i = 0; i < 10; ++i)
    {
        if (tmp[i])
            used.push_back(i);
        else
            unused.push_back(i);
    }
    return {unused, used};
}

// 숫자 리스트를 문자열로 합치기
string concat(const vector<int> &L)
{
    string s;
    for (int c : L)
        s += char(c + '0');
    return s;
}

void solve(string N, int K)
{
    if (numkind(N) == K)
    {
        cout << N << '\n';
        return;
    }

    int len = N.size();
    for (int prefix_i = len - 1; prefix_i >= 0; --prefix_i)
    {
        for (int prefix_last = N[prefix_i] - '0' + 1; prefix_last <= 9; ++prefix_last)
        {
            string prefix = N.substr(0, prefix_i) + char(prefix_last + '0');

            int kind = numkind(prefix);
            int leftnum = K - kind;           // 추가해야 할 숫자 종류 수
            int leftlen = len - prefix_i - 1; // 남은 자리 수

            if (leftnum < 0 || leftnum > leftlen)
                continue;

            auto [unused, used] = numList(prefix);

            if (leftnum == 0)
            {
                cout << prefix << string(leftlen, char(used[0] + '0')) << '\n';
                return;
            }
            else
            {
                cout << prefix
                     << string(leftlen - leftnum, '0')
                     << concat({unused.begin(), unused.begin() + leftnum}) << '\n';
                return;
            }
        }
    }

    // 여기에 도달하면 N 자리로는 해결 불가능 → 자릿수 늘리기
    int newlen = max(K, (int)N.size() + 1);
    string result = "1" + string(newlen - K + 1, '0');
    string tail = "23456789";
    for (int i = 0; i < K - 2; ++i)
        result += tail[i];
    cout << result << '\n';
}

int main()
{
    FIO;

    string N;
    int K;
    cin >> N >> K;
    solve(N, K);
}
