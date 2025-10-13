#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

bool compare(pair<int, float> &a, pair<int, float> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages)
{

    vector<int> answer;
    vector<float> challenger(N + 2, 0.0);
    vector<float> fail(N + 2, 0.0);

    for (int i = 0; i < stages.size(); i++)
    {
        for (int j = 1; j <= stages[i]; j++)
            challenger[j]++;

        fail[stages[i]]++;
    }

    vector<pair<int, float>> failRatio(N);

    for (int i = 0; i < N; i++)
    {
        failRatio[i].first = i + 1;

        if (challenger[i + 1] == 0)
            failRatio[i].second = 0;
        else
            failRatio[i].second = fail[i + 1] / challenger[i + 1];
    }

    sort(failRatio.begin(), failRatio.end(), compare);

    for (int i = 0; i < N; i++)
    {
        answer.push_back(failRatio[i].first);
    }

    return answer;
}

// 아래 코드는 테스트 코드 입니다.

#include <iterator>
#include <iostream>
void print(vector<int> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    print(solution(5, {2, 1, 2, 6, 2, 4, 3, 3})); // 3 4 2 1 5
    print(solution(4, {4, 4, 4, 4, 4}));          // 4 1 2 3

    return 0;
}