#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    int rows = N / 2;
    int cols = N - rows;
    
    cout << (rows + 1) * (cols + 1) << '\n';
    
    return 0;
}
