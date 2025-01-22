#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int main() {
    FIO;

    int H, W;
    cin >> H >> W;
    vector<int> height(W);
    for (int i = 0; i < W; i++) {
        cin >> height[i];
    }

    vector<int> left_max(W), right_max(W);
    
    // 왼쪽에서 가장 높은 블록 구하기
    left_max[0] = height[0];
    for (int i = 1; i < W; i++) {
        left_max[i] = max(left_max[i - 1], height[i]);
    }

    // 오른쪽에서 가장 높은 블록 구하기
    right_max[W - 1] = height[W - 1];
    for (int i = W - 2; i >= 0; i--) {
        right_max[i] = max(right_max[i + 1], height[i]);
    }

    // 고이는 빗물 계산
    int water = 0;
    for (int i = 0; i < W; i++) {
        water += min(left_max[i], right_max[i]) - height[i];
    }

    cout << water << "\n";
    return 0;
}
