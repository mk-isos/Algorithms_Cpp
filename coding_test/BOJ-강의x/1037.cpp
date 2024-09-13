#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;

    vector<int> divisors(num);
    for (int i = 0; i < num; i++) {
        cin >> divisors[i];
    }

    int N = *min_element(divisors.begin(), divisors.end()) * *max_element(divisors.begin(), divisors.end());
    
    cout << N << endl;
    return 0;
}
