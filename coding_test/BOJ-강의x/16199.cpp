#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int birth_year, birth_month, birth_day;
    int current_year, current_month, current_day;

    cin >> birth_year >> birth_month >> birth_day;
    // 기준 날짜 입력
    cin >> current_year >> current_month >> current_day;

    // 만 나이 계산
    int age = current_year - birth_year;
    if (current_month < birth_month || (current_month == birth_month && current_day < birth_day)) {
        age--;
    }
    cout << age << "\n";

    // 세는 나이 계산
    cout << (current_year - birth_year + 1) << "\n";

    // 연 나이 계산
    cout << (current_year - birth_year) << "\n";

    return 0;
}
