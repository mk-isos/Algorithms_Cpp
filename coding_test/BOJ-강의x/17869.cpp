// 아래는 시간초과 풀이

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
    
//     unsigned int n;
//     cin >> n;
    
//     int steps = 0;  
//     while (n != 1) {  
//         if (n % 2 == 0) {  
//             n /= 2;
//         } else {  
//             n += 1;
//         }
//         steps++;
//     }
    
//     cout << steps << '\n';  
//     return 0;
// }

// int 자료형 바꾸기
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    unsigned long long n;  // 'unsigned long long' 사용
    cin >> n;
    
    int steps = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n += 1;
        }
        steps++;
    }
    
    cout << steps << '\n';
    return 0;
}

