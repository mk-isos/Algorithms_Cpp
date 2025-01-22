#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    string result;
    for (int i = 0; i < N; ++i) {
        result += to_string(N);
    }

    // 필요한 경우에 앞 M자리까지만 
    cout << result.substr(0, M) << endl;

    return 0;
}
