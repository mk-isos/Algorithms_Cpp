#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    list<int> people;
    for (int i = 1; i <= N; ++i) {
        people.push_back(i);
    }
    
    auto it = people.begin();
    vector<int> result;
    
    while (!people.empty()) {
        // K-1 번 이동
        for (int i = 1; i < K; ++i) {
            ++it;
            if (it == people.end()) it = people.begin();
        }
        // 현재 가리키는 사람을 결과에 추가하고, 리스트에서 제거
        result.push_back(*it);
        it = people.erase(it);
        if (it == people.end()) it = people.begin();
    }
    
    //결과
    cout << "<";
    for (size_t i = 0; i < result.size(); ++i) {
        if (i > 0) cout << ", ";
        cout << result[i];
    }
    cout << ">\n";
    
    return 0;
}
