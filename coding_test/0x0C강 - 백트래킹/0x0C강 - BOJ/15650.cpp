#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N, M;
vector<int> seq;

void backtrack(int start) {
    if (seq.size()==M) {
        for (int num : seq) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i =start; i <= N; i++) {
        seq.push_back(i);
        backtrack(i+1);
        seq.pop_back();
    }
}

int main(){
    FIO;

    cin >> N >> M;
    backtrack(1);
    return 0;
}