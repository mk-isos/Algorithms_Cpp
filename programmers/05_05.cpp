#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;

    answer.assign(arr1.size(), vector<int>(arr2[1].size(), 0));

    for (int i = 0; i < arr1.size(); i++)
        for (int j = 0; j < arr2[1].size(); j++)
            for (int k = 0; k < arr2.size(); k++)
                answer[i][j] += arr1[i][k] * arr2[k][j];

    return answer;
}

// 아래 코드는 테스트 코드 입니다.

#include <iterator>
#include <iostream>
void print2D(vector<vector<int>> vec)
{
    for (const auto &innerVec : vec)
    {
        copy(innerVec.begin(), innerVec.end(), std::ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    cout << endl;
}

int main()
{
    FIO;
    print2D(solution({{1, 4}, {3, 2}, {4, 1}}, {{3, 3}, {3, 3}}));
    /*
      15 15
      15 15
      15 15
    */
    print2D(solution({{2, 3, 2}, {4, 2, 4}, {3, 1, 4}}, {{5, 4, 3}, {2, 4, 1}, {3, 1, 1}})); // 1 2 3
    /*
      22 22 11
      36 28 18
      29 20 14
    */

    return 0;
}