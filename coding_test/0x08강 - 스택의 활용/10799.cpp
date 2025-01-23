#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;

string s;
ll ans = 0;
stack<char> st;

int main()
{
    FIO;
    cin >> s;
    int sz = s.length();

    for (int i = 0; i < sz; i++)
    {
        if (s[i] == '(')
            st.push(s[i]);
        else
        {
            if (s[i - 1] == '(')
            {                     // 레이저일 경우
                st.pop();         // 앞에서 막대라고 착각하고 stack에 s[i]를 넣었으므로 pop
                ans += st.size(); // 막대의 개수만큼 ans에 추가
            }
            else
            {             // 막대의 끝일 경우
                st.pop(); // 막대의 개수를 1 감소
                ans++;    // 막대 1개가 절단된 것과 동일한 상황이므로 ans에 1 추가
            }
        }
    }
    cout << ans << "\n";

    return 0;
}