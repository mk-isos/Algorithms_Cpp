#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, A, B;
    cin >> N >> A >> B;

    int maxChickenByDrinks = A / 2 + B;
    cout << min(N, maxChickenByDrinks) << "\n";
    
    return 0;
}
