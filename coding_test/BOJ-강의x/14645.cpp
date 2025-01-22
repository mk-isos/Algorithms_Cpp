#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    int passengers = K;
    for (int i = 0; i < N; ++i) {
        int A, B;
        cin >> A >> B;
        passengers += A - B;
    }

    cout << "비와이\n";
    return 0;
}
