// Authored by : twinkite
// Co-authored by : BaaaaaaaaaaarkingDog

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

/*
#define X first:
pair의 첫 번째 값인 first를 X로 간단히 참조할 수 있게 합니다.
#define Y second:
pair의 두 번째 값인 second를 Y로 간단히 참조할 수 있게 합니다.
*/

int N;
stack<pair<int,int>> tower;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;  
    tower.push({100000001, 0});
    
    for (int i = 1; i <= N; i++) {
        int height;
        cin >> height;
        
        while (tower.top().X < height)
        tower.pop();    
        cout << tower.top().Y << " ";
        tower.push({height, i});      
    }
}