#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, problem_type;
    cin >> N >> problem_type;

    vector<int> perm(N);
    if (problem_type == 1) {
        long long k;
        cin >> k;
        vector<int> numbers;
        for (int i = 1; i <= N; i++) numbers.push_back(i);
        
        k--;  // 1-based index -> 0-based index
        for (int i = 0; i < N; i++) {
            long long fact = 1;
            for (int j = 1; j < N - i; j++) fact *= j;

            int idx = k / fact;
            cout << numbers[idx] << " ";
            numbers.erase(numbers.begin() + idx);
            k %= fact;
        }
        cout << "\n";
    } 
    else if (problem_type == 2) {
        for (int i = 0; i < N; i++) cin >> perm[i];

        vector<int> numbers;
        for (int i = 1; i <= N; i++) numbers.push_back(i);
        
        long long k = 0;
        for (int i = 0; i < N; i++) {
            long long fact = 1;
            for (int j = 1; j < N - i; j++) fact *= j;

            int idx = find(numbers.begin(), numbers.end(), perm[i]) - numbers.begin();
            k += idx * fact;
            numbers.erase(numbers.begin() + idx);
        }
        cout << k + 1 << "\n";  // 0-based index -> 1-based index
    }

    return 0;
}
