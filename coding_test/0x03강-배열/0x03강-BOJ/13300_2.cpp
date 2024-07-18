#include <bits/stdc++.h>
using namespace std;

int N, K, ans=0;
int s[2][7]={};  // 성별/반별 학생 수를 저장하는 배열

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    // 학생 수 저장
    for (int i=0; i<N; ++i) {
        int a, b;
        cin >> a >> b;
        s[a][b]++;
    }

    // 필요한 방의 개수 계산
    for (int i=0; i<2; ++i) {
        for (int j=1; j<7; ++j) {
        // 배정에 필요한 만큼 방의 개수 추가
        ans += s[i][j] / K;
        // 학생이 남을 경우, 하나의 방이 더 필요하므로 방의 개수 추가
        if (s[i][j] % K) ++ans;
        }
    }
    cout << ans;
}

/*
코드 비교:

나의 풀이는 배열 인덱스를 학년(0-5)과 성별(0-1)로 설정하고, 
(students[grade][gender] + K - 1) / K를 사용하여 필요한 방의 개수를 계산. (올림 계산)

바킹독님 풀이는 배열 인덱스를 성별(0-1)과 학년(1-6)으로 설정하고, 
s[i][j] / K와 나머지 조건을 사용하여 필요한 방의 개수를 계산.
*/
