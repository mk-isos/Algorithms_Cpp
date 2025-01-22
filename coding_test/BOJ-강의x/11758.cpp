#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    int ccw = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    
    if (ccw > 0)
        cout << 1 << '\n';  // 반시계 방향
    else if (ccw < 0)
        cout << -1 << '\n'; // 시계 방향
    else
        cout << 0 << '\n';  // 일직선
    
    return 0;
}
