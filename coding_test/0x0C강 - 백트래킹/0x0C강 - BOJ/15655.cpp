#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N, M;
vector<int> num, seq;

void backtrack(int start) {
    if(seq.size()==M) {
        for(int num : seq) cout << num << " ";
        cout << "\n";
        return;
    }

    for(int i = start; i < N; i++) {
        seq.push_back(num[i]);
        backtrack(i+1);
        seq.pop_back();
    }
}

int main(){
    FIO;

    cin >> N >> M;
    num.resize(N);

    for(int i = 0; i < N; i++) cin >> num[i];

    sort(num.begin(), num.end());

    backtrack(0);
    return 0;
}