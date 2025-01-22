#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

void parse(string &tmp, deque<int> &d)
{
    int cur = 0;
    for (int i = 1; i + 1 < tmp.size(); i++)
    {
        if (tmp[i] == ',')
        {
            d.push_back(cur);
            cur = 0;
        }
        else
        {
            cur = 10 * cur + (tmp[i] - '0');
            /* 예를 들어, 숫자 12를 처리하려면, '1'을 처리한 후 '2'를 추가해야 합니다.
                이를 다음과 같이 계산합니다:
                첫 번째 문자 '1': cur = 0 * 10 + 1 = 1
                두 번째 문자 '2': cur = 10 * 1 + 2 = 12 */
        }
    }
    if (cur != 0)
        d.push_back(cur);
}

void print_result(deque<int> &d)
{
    cout << '[';
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i];
        if (i + 1 != d.size())
            cout << ',';
    }
    cout << "]\n";
}

int t;
int main()
{
    FIO;

    cin >> t;
    while (t--)
    {
        deque<int> d;
        int rev = 0;
        int n;
        bool isWrong = false;
        string query, tmp;

        cin >> query;
        cin >> n;
        cin >> tmp;

        parse(tmp, d);

        for (char c : query)
        {
            if (c == 'R')
            {
                rev = 1 - rev; // 뒤집기 상태를 toggle
            }
            else
            {
                if (d.empty())
                {
                    isWrong = true; // 빈 배열에서 'D' 연산 시 에러
                    break;
                }
                if (!rev)
                    d.pop_front(); // 현재 상태가 뒤집혀 있지 않으면 앞에서 제거
                else
                    d.pop_back(); // 뒤집혀 있으면 뒤에서 제거
            }
        }

        if (isWrong)
        {
            cout << "error\n"; // 에러 발생 시
        }
        else
        {
            if (rev)
                reverse(d.begin(), d.end()); // 최종적으로 뒤집힌 상태라면 배열 뒤집기
            print_result(d);                 // 결과 출력
        }
    }
}