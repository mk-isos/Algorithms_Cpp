#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    // 각 학년(1-6)과 성별(0-여학생, 1-남학생) 별로 학생 수를 저장하는 배열
    int students[6][2] = {};

    // 학생 정보 입력
    for (int i = 0; i < N; ++i) {
        int gender, grade;
        cin >> gender >> grade;
        students[grade - 1][gender]++;
    }

    int rooms_needed = 0;

    // 각 학년과 성별 별로 필요한 방의 수 계산
    for (int grade = 0; grade < 6; ++grade) {
        for (int gender = 0; gender < 2; ++gender) {
            rooms_needed += (students[grade][gender] + K - 1) / K;
        }
    }

    cout << rooms_needed << '\n';
    return 0;
}


// (students[grade][gender] + K - 1) / K
/* 수학적 설명:
(students[grade][gender] + K - 1) / K는 x를 y로 나누는 정수 나눗셈의 올림을 계산하는 방법이다.
1. x를 y로 나눌 때 소수점 이하가 있으면 올림을 해야 한다.
2. x + y - 1은 x에 y - 1을 더해주는 방식으로 올림을 적용하는 역할을 한다.

예를 들어, x가 5이고 y가 3인 경우:
- 5 / 3의 정수 나눗셈 결과는 1이지만, 실제로는 1.666...이다.
- 5 + 3 - 1은 7이 되므로, 7 / 3의 정수 나눗셈 결과는 2가 된다. 이는 올림된 결과이다.

따라서 (students[grade][gender] + K - 1) / K는 각 학년과 성별의 학생 수를 최대 인원수 K로 나누어 올림한 값을 계산하여 필요한 방의 수를 구하는 식이다.
*/

