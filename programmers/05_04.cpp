#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

using namespace std;

vector<int> firstPattern = {1, 2, 3, 4, 5};
vector<int> secondPattern = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> thirdPattern = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers)
{

    vector<int> answer;

    vector<int> matchCnt(3);

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == firstPattern[i % firstPattern.size()])
            matchCnt[0]++;
        if (answers[i] == secondPattern[i % secondPattern.size()])
            matchCnt[1]++;
        if (answers[i] == thirdPattern[i % thirdPattern.size()])
            matchCnt[2]++;
    }
    int max_score = *max_element(matchCnt.begin(), matchCnt.end());

    for (int i = 0; i < 3; i++)
    {
        if (matchCnt[i] == max_score)
            answer.push_back(i + 1);
    }

    return answer;
}

// 아래 코드는 테스트 코드 입니다.

void print(vector<int> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    FIO;
    print(solution({1, 2, 3, 4, 5})); // 1
    print(solution({1, 3, 2, 4, 2})); // 1 2 3

    return 0;
}