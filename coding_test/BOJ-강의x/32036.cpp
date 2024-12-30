#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;

int main(){
    FIO;
    int q;
    cin >> q;
    // Max heap for left half
    priority_queue<int> left_heap;
    // Min heap for right half
    priority_queue<int, vector<int>, std::greater<int>> right_heap;
    ll sum_left =0;
    ll sum_right=0;
    ll total_y =0;
    while(q--){
        int type;
        cin >> type;
        if(type ==1){
            int x;
            ll y;
            cin >> x >> y;
            // Insert x
            if(left_heap.empty() || x <= left_heap.top()){
                left_heap.push(x);
                sum_left +=x;
            }
            else{
                right_heap.push(x);
                sum_right +=x;
            }
            // Balance the heaps
            if(left_heap.size() > right_heap.size() +1){
                int top = left_heap.top();
                left_heap.pop();
                sum_left -= top;
                right_heap.push(top);
                sum_right +=top;
            }
            else if(left_heap.size() < right_heap.size()){
                int top = right_heap.top();
                right_heap.pop();
                sum_right -=top;
                left_heap.push(top);
                sum_left +=top;
            }
            // Update total_y
            total_y += y;
        }
        else if(type ==2){
            if(left_heap.empty()){
                // 첫 번째 쿼리는 항상 타입 1
                cout << "0 0\n";
                continue;
            }
            int m = left_heap.top();
            int size_left = left_heap.size();
            int size_right = right_heap.size();
            ll sum_j = (ll)m * size_left - sum_left + sum_right - (ll)m * size_right;
            ll A_m = sum_j + total_y;
            cout << m << " " << A_m << "\n";
        }
    }
}
