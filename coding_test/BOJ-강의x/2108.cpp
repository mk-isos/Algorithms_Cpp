#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int N;
    cin >> N;

    vector<int> numbers(N);
    map<int, int> freq;
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
        sum += numbers[i];
        freq[numbers[i]]++;
    }

    // 1. 산술평균 (반올림)
    int mean = round((double)sum / N);
    cout << mean << '\n';

    // 2. 중앙값
    sort(numbers.begin(), numbers.end());
    cout << numbers[N / 2] << '\n';

    // 3. 최빈값 찾기 (두 번째로 작은 값 선택)
    int maxFreq = 0;
    vector<int> modeCandidates;

    for (auto &p : freq)
    {
        if (p.second > maxFreq)
        {
            maxFreq = p.second;
            modeCandidates = {p.first};
        }
        else if (p.second == maxFreq)
        {
            modeCandidates.push_back(p.first);
        }
    }

    sort(modeCandidates.begin(), modeCandidates.end());

    if (modeCandidates.size() > 1)
        cout << modeCandidates[1] << '\n';
    else
        cout << modeCandidates[0] << '\n';

    cout << numbers.back() - numbers.front() << '\n';

    return 0;
}
