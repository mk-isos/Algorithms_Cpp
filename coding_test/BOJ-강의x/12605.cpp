#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int T;
    cin >> T;
    cin.ignore(); // 개행문자 제거

    for (int t = 1; t <= T; ++t)
    {
        string line;
        getline(cin, line);

        stringstream ss(line);
        vector<string> words;
        string word;

        while (ss >> word)
        {
            words.push_back(word);
        }

        reverse(words.begin(), words.end());

        cout << "Case #" << t << ": ";
        for (int i = 0; i < words.size(); ++i)
        {
            cout << words[i];
            if (i != words.size() - 1)
                cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
