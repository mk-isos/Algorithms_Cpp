#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N, M;
int arr[8];     // 수열을 저장할 배열
bool isused[8]; // 해당 숫자가 사용되었는지 여부를 저장

void backtrack(int k)
{ // k는 현재 선택한 숫자의 개수
    cout << "backtrack(" << k << ") called." << endl;

    if (k == M)
    { // M개의 숫자를 모두 선택한 경우
        for (int i = 0; i < M; i++)
        {
            cout << arr[i] << " "; // 수열 출력
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++)
    { // 1부터 N까지의 숫자 탐색
        if (!isused[i - 1])
        {                         // 숫자 i가 사용되지 않았다면
            arr[k] = i;           // 현재 위치 k에 숫자 i 저장
            isused[i - 1] = true; // 숫자 i를 사용했다고 표시

            // 현재 상태 출력
            cout << "k = " << k << ", arr = {";
            for (int j = 0; j < M; j++)
            {
                if (j < k)
                    cout << arr[j] << ", ";
                else
                    cout << "_ "; // 아직 채워지지 않은 부분은 '_'
            }
            cout << "}, isused = {";
            for (int j = 0; j < N; j++)
            {
                cout << isused[j] << " ";
            }
            cout << "}" << endl;

            backtrack(k + 1); // 다음 숫자를 고르기 위해 재귀 호출

            // 백트래킹(원래 상태로 되돌림)
            isused[i - 1] = false; // 숫자 i 사용 해제
            cout << "Backtracking: Reset isused[" << i - 1 << "] = false" << endl;
        }
    }
}

int main()
{
    FIO;
    cin >> N >> M;
    backtrack(0); // 백트래킹 시작
    return 0;
}
