#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    unordered_map<string, int> ph;

    for (int i = 0; i < participant.size(); i++)
        ph[participant[i]]++;

    for (int i = 0; i < completion.size(); i++)
    {
        ph[completion[i]]--;
        if (ph[completion[i]] == 0)
            ph.erase(ph.find(completion[i]));
    }
    return ph.begin()->first;
}