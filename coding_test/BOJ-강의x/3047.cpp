#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);  
    cin.tie(0);

    int nums[3];
    char order[4];
    
    cin >> nums[0] >> nums[1] >> nums[2];
    cin >> order;
    
    sort(nums, nums + 3);
    
    for (int i = 0; i < 3; ++i) {
        cout << nums[order[i] - 'A'] << ' ';
    }
    return 0;
}
