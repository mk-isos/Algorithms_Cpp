//제일 마음에 든다.

// Authored by : haneulkimdev

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    queue<int> Q;
    for (int i = 1; i <= n; i++) Q.push(i);
    
    cout << '<';
    while (!Q.empty()) {
        for (int i = 0; i < k - 1; i++) {
        Q.push(Q.front());
        Q.pop();
        }
        cout << Q.front();
        Q.pop();
        if (Q.size()) cout << ", ";
    }
    cout << '>';
}

/*
STL queue를 이용한 풀이
*/

/*
이 코드는 queue를 사용하여 원형 리스트를 구현하고, 
매 K번째 사람을 제거하는 방식으로 요세푸스 순열을 생성. 
각 단계에서 큐의 맨 앞 요소를 맨 뒤로 이동시키고, K번째 사람을 제거하며 결과를 출력
*/