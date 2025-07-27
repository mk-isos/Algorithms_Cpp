#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    FIO;
    int T;
    cin >> T;
    while (T--) {
        int G, C, E;
        cin >> G >> C >> E;
        int need = max(0, E - C);
        int dist = 0;
        if (G == 1) dist = 1;
        else if (G == 2) dist = 3;
        else dist = 5;
        cout << need * dist << '\n';
    }
    return 0;
}
