#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main(){
    FIO;

    int A, B, C;
    cin >> A;
    cin >> B; 
    cin >> C;

    string A_str = to_string(A);
    string B_str = to_string(B);
    string C_str = to_string(C);

    cout << A + B - C << "\n";
    cout << (stoi(A_str + B_str) - stoi(C_str));
}