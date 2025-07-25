#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int N, M;
    cin >> N >> M;

    vector<int> boxes(N);
    for (int i = 0; i < N; ++i)
        cin >> boxes[i];

    vector<int> books(M);
    for (int i = 0; i < M; ++i)
        cin >> books[i];

    int box_idx = 0;
    for (int i = 0; i < M; ++i)
    {
        while (books[i] > boxes[box_idx])
        {
            box_idx++;
        }
        boxes[box_idx] -= books[i];
    }

    int waste = 0;
    for (int i = 0; i < N; ++i)
        waste += boxes[i];
    cout << waste << '\n';
    return 0;
}
