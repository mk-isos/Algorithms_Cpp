//다시 풀기 

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);  
    cin.tie(0);

    int n, mini = -2e9, maxi = 2e9, s = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (i % 2) mini = max(mini, s - a);
        else maxi = min(maxi, a - s);
        s = 2 * a - s;
    }
    
    cout << max(maxi - mini + 1, 0) << '\n';
    
    return 0;
}
