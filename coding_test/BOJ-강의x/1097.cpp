#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N, K, totalLength = 0;
vector<string> words;
vector<bool> check;

int kmp(const string &word)
{
    int len = word.length();
    vector<int> pi(len, 0);
    int pIdx = 0;

    for (int i = 1; i < len; i++)
    {
        while (pIdx > 0 && word[i] != word[pIdx])
        {
            pIdx = pi[pIdx - 1];
        }
        if (word[i] == word[pIdx])
        {
            pi[i] = ++pIdx;
        }
    }

    int cycle = len - pi[len - 1];
    if (len % cycle != 0)
    {
        return (K == 1) ? 1 : 0;
    }
    return (K - 1 == pi[len - 1] / cycle) ? 1 : 0;
}

int getComb(string word)
{
    if ((int)word.length() == totalLength)
    {
        return kmp(word);
    }

    int ret = 0;
    for (int i = 0; i < N; i++)
    {
        if (check[i])
            continue;
        check[i] = true;
        ret += getComb(word + words[i]);
        check[i] = false;
    }
    return ret;
}

int main()
{
    FIO;
    cin >> N;
    words.resize(N);
    check.resize(N, false);

    for (int i = 0; i < N; i++)
    {
        cin >> words[i];
        totalLength += words[i].length();
    }
    cin >> K;

    cout << getComb("") << '\n';
    return 0;
}
