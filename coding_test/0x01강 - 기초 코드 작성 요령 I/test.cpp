//시간복잡도 공부

#include <bits/stdc++.h>
using namespace std;

int func1(int N){
    int ret = 0;
    for(int i=1; i<= N; i++){
        if(i%3==0 || i % 5 ==0) ret += i;
    }
  return ret;
}
// 시간복잡도 O(N)

int func2(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[i] + arr[j] == 100) return i;
        }
    }
    return 0;
}
// 시간복잡도 O(N^2)
// O(N) 풀이가 있음
/*
보조 배열? 해시맵? 0x03강 배열에서 배운다고 함
*/


int func3(int N){
  for(int i = 1; i * i <= N; i++){
    if(i*i == N) return 1;
  }
  return 0;
}

// 시간복잡도 O(루트N)

int func4(int N){
  int val = 1;
  while(2*val <= N) val *= 2;
  return val;
}

// 시간복잡도 O(lgN)
//  N이 2^k 이상 2^k+1 미만이라고 할 때 while문 안에서 val은 최대 k번만 2배로 커집니다. 
// 그러고나면 val은 2^k가 되고, 이후 2*val <= N이 거짓이 되기 때문입니다. 
// 그러니까 N이 2^k 이상 2^k+1 미만이라고 할 때 시간복잡도가 O(k)이고 로그의 정의에 입각해서 생각할 때 
// k는 lgN이니 결국 시간복잡도는 O(lgN)이 됩니다.

void test1(){
  cout << "****** func1 test ******\n";
  int n[3] = {16, 34567, 27639};
  int ans[3] = {60, 278812814, 178254968};
  for(int i = 0; i < 3; i++){
    int result = func1(n[i]);
    cout << "TC #" << i << '\n';
    cout << "expected : " << ans[i] << " result : " << result;
    if(ans[i] == result) cout << " ... Correct!\n";
    else cout << " ... Wrong!\n";
  }
  cout << "*************************\n\n";
}

void test2(){
  cout << "****** func2 test ******\n";
  int arr[3][4] = {{1,52,48}, {50,42}, {4,13,63,87}};
  int n[3] = {3, 2, 4};
  int ans[3] = {1, 0, 1};
  for(int i = 0; i < 3; i++){
    int result = func2(arr[i], n[i]);
    cout << "TC #" << i << '\n';
    cout << "expected : " << ans[i] << " result : " << result;
    if(ans[i] == result) cout << " ... Correct!\n";
    else cout << " ... Wrong!\n";
  }
  cout << "*************************\n\n";
}

void test3(){
  cout << "****** func3 test ******\n";
  int n[3] = {9, 693953651, 756580036};
  int ans[3] = {1, 0, 1};
  for(int i = 0; i < 3; i++){
    int result = func3(n[i]);
    cout << "TC #" << i << '\n';
    cout << "expected : " << ans[i] << " result : " << result;
    if(ans[i] == result) cout << " ... Correct!\n";
    else cout << " ... Wrong!\n";
  }
  cout << "*************************\n\n";
}

void test4(){
  cout << "****** func4 test ******\n";
  int n[3] = {5, 97615282, 1024};
  int ans[3] = {4, 67108864, 1024};
  for(int i = 0; i < 3; i++){
    int result = func4(n[i]);
    cout << "TC #" << i << '\n';
    cout << "expected : " << ans[i] << " result : " << result;
    if(ans[i] == result) cout << " ... Correct!\n";
    else cout << " ... Wrong!\n";
  }
  cout << "*************************\n\n";
}

int main(void){
  test1();
  test2();
  test3();
  test4();
}