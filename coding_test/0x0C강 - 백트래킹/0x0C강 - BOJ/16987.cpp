#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N, max_broken = 0;
vector<pair<int, int>> eggs; // (내구도, 무게)

void backtrack(int idx)
{
    if (idx == N)
    {
        int broken_count = 0;
        for (auto &egg : eggs)
            if (egg.first <= 0)
                broken_count++;
        max_broken = max(max_broken, broken_count);
        return;
    }

    if (eggs[idx].first <= 0)
    {
        backtrack(idx + 1);
        return;
    }

    bool hit = false; // 한 번이라도 계란을 친 경우 확인

    for (int j = 0; j < N; j++)
    {
        if (idx == j || eggs[j].first <= 0)
            continue; // 자기 자신이거나 이미 깨진 계란이면 건너뜀

        // 현재 계란과 상대 계란 충돌 , 양쪽 마이너스
        eggs[idx].first -= eggs[j].second;
        eggs[j].first -= eggs[idx].second;

        hit = true;         // 계란을 친 경우
        backtrack(idx + 1); // 다음 계란으로 이동

        // 원상복구
        eggs[idx].first += eggs[j].second;
        eggs[j].first += eggs[idx].second;
    }

    if (!hit)
        backtrack(idx + 1); // 계란을 하나도 못 친 경우 그냥 다음 계란으로 이동
}

int main()
{
    FIO;
    cin >> N;
    eggs.resize(N);

    for (int i = 0; i < N; i++)
        cin >> eggs[i].first >> eggs[i].second;

    backtrack(0);
    cout << max_broken << "\n";

    return 0;
}
