// 다시보기 240726
// Authored by : haneulkimdev

#include <bits/stdc++.h>
using namespace std;

int a[1000000];
int ans[1000000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    stack<int> S;
    for (int i = n - 1; i >= 0; i--) {
        while (!S.empty() && S.top() <= a[i]) S.pop();
        if (S.empty())
        ans[i] = -1;
        else
        ans[i] = S.top();
        S.push(a[i]);
    }
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}

/*
차이점 정리:
1. 변수 선언 위치:
   - 나의 풀이: `vector<int> heights(N)`와 같이 동적 배열 사용.
   - haneulkimdev: `int a[1000000]`와 같이 정적 배열 사용.

2. 결과 저장 방식:
   - 나의 풀이: `long long result`를 사용해 결과 합을 직접 계산.
   - haneulkimdev: `int ans[1000000]`를 사용해 각 위치의 결과 저장.

3. 스택 처리 방식:
   - 나의 풀이: 현재 위치의 오른쪽으로만 스택을 이용해 처리.
   - haneulkimdev: 뒤에서부터 접근하여 스택을 이용해 처리.

4. 시간 복잡도:
   - 두 풀이 모두 O(N)으로 효율적이나, haneulkimdev님의 풀이는 뒤에서부터 접근해 비교적 덜 복잡하게 처리.
*/