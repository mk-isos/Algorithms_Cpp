#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N;
vector<int> nums;
vector<vector<int>> adj;
vector<int> match, visited;

bool isPrime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

// 이분 매칭
bool dfs(int cur)
{
    for (int nxt : adj[cur])
    {
        if (visited[nxt])
            continue;
        visited[nxt] = 1;
        if (match[nxt] == -1 || dfs(match[nxt]))
        {
            match[nxt] = cur;
            return true;
        }
    }
    return false;
}

int main()
{
    FIO;
    cin >> N;
    nums.resize(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    vector<int> answer;

    for (int i = 1; i < N; i++)
    {
        if (!isPrime(nums[0] + nums[i]))
            continue;

        vector<int> rest;
        for (int j = 1; j < N; j++)
        {
            if (j != i)
                rest.push_back(nums[j]);
        }

        vector<int> left, right;
        for (int x : rest)
        {
            if (x % 2)
                left.push_back(x);
            else
                right.push_back(x);
        }

        // nums[0]와 nums[i]는 먼저 짝지음 → 남은 수들로 이분 그래프
        // 이때 left.size() == right.size() 여야 모든 쌍이 가능
        if (left.size() != right.size())
            continue;

        int L = left.size();
        adj.assign(L, vector<int>());

        // 그래프 구성
        for (int li = 0; li < L; li++)
        {
            for (int ri = 0; ri < L; ri++)
            {
                if (isPrime(left[li] + right[ri]))
                {
                    adj[li].push_back(ri);
                }
            }
        }

        match.assign(L, -1);
        int cnt = 0;
        for (int li = 0; li < L; li++)
        {
            visited.assign(L, 0);
            if (dfs(li))
                cnt++;
        }

        if (cnt == L)
        {
            answer.push_back(nums[i]);
        }
    }

    if (answer.empty())
        cout << -1;
    else
    {
        sort(answer.begin(), answer.end());
        for (int x : answer)
            cout << x << ' ';
    }
}
