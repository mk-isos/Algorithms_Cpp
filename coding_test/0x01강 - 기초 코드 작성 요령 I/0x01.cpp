// 시간 제한이 1초 : 1초에 대략 3-5억 개 정도의 연산을 처리
// 단, 연산이 비트 AND, OR, 비교, 덧셈과 같은 단순한 연산인지,  아니면 나눗셈, 곱셈, 대입, 함수 호출과 같은 복잡한 연산인지에 따라 횟수에 좀 차이가 날 수 있어서 3-5억이라는 것은 어림을 잡은 값인건 주의

#include <iostream>
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    cout << a + b;
}

int funcl (int arr[], int n) {
    int cnt = 0;                    // cnt 변수를 선언하고 0을 넣는 과정에서 1번
    for(int i = 0; i < n; i++){     // i에 초기 값으로 0을 대입할 때 1번, 그 다음에는 n번에 걸쳐 반복되는 일인데 03번째 줄을 계속 보면 i가 n보다 작은지 확인하고 작을 경우 1 증가시키니 연산 2번
        if(arr[i] % 5 == 0) cnt++;  //5로 나눈 나머지를 계산하고 그게 0과 일치하는지 확인할 때 연산 2번, 5의 배수라고 치면 cnt를 1 증가시켜야 하니 연산 1번
    }
    return cnt;                     //cnt를 반환할 때 연산 1번이 추가
}

// 이 함수는 5n + 3번의 연산이 필요
// n에 비례한다고 생각하기

// lg N : 밑이 2인 로그만 나오기 때문에 로그는 해당 수가 2의 몇 거듭제곱인지를 의미하고 lg 2 = 1, lg 4 = 2, lg 8 = 3, lg 16 = 4, lg 32 = 5


////////////
//공간 복잡도

//512MB = 1.2억개의 int (int 1개 4byte니까)