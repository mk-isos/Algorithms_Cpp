#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int L, C;
vector<char> letters, password;
string vowels = "aeiou"; // vowel : 모음

void backtrack(int idx, int vowel_count, int consonant_count)
{
    if (password.size() == L)
    {
        if (vowel_count >= 1 && consonant_count >= 2)
        { // 모음 1개 이상, 자음 2개 이상 조건 만족
            for (char ch : password)
                cout << ch;
            cout << "\n";
        }
        return;
    }

    for (int i = idx; i < C; i++)
    {
        password.push_back(letters[i]);

        if (vowels.find(letters[i]) != string::npos)
            backtrack(i + 1, vowel_count + 1, consonant_count);
        else
            backtrack(i + 1, vowel_count, consonant_count + 1);

        password.pop_back();
    }
}

int main()
{
    FIO;
    cin >> L >> C;

    letters.resize(C);
    for (int i = 0; i < C; i++)
        cin >> letters[i];

    sort(letters.begin(), letters.end()); // 사전순 정렬

    backtrack(0, 0, 0); // 백트래킹 시작

    return 0;
}
