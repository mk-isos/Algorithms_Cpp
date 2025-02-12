#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    FIO; // 입출력 속도 최적화

    int n;
    cout << "배열 크기를 입력하세요: ";
    cin >> n;

    vector<int> a(n);
    cout << "배열 요소를 입력하세요 (공백으로 구분): ";
    for (int i = 0; i < n; i++) cin >> a[i];

    // 입력된 배열 정렬 (사전순 순열을 위해 필요)
    sort(a.begin(), a.end());

    cout << "\n모든 순열 출력:\n";
    do {
        for (int x : a) cout << x << " ";
        cout << '\n';
    } while (next_permutation(a.begin(), a.end())); // 다음 순열 생성

    cout << "\n순열 생성 완료!\n";

    return 0;
}
