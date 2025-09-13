#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

using ll = long long;
struct Line{ ll m,b; };

inline ll f(const Line& L, ll x){ return L.m*x + L.b; }

bool bad(const Line& l1, const Line& l2, const Line& l3){
    __int128 left  = (__int128)(l3.b - l1.b) * (l1.m - l2.m);
    __int128 right = (__int128)(l2.b - l1.b) * (l1.m - l3.m);
    return left <= right;
}

int main(){
    FIO;

    int n; 
    if(!(cin >> n)) return 0;
    vector<ll> x(n);
    for(int i=0;i<n;i++) cin >> x[i];

    deque<Line> dq;
    ll dp0 = 0;
    dq.push_back({-2*x[0], dp0 + x[0]*x[0]});

    for(int i=1;i<n;i++){
        ll xi = x[i];
        while(dq.size()>=2 && f(dq[0], xi) >= f(dq[1], xi)) dq.pop_front();
        ll best = f(dq.front(), xi);
        ll dpi = xi*xi + best;
        Line L = {-2*xi, dpi + xi*xi};
        while(dq.size()>=2 && bad(dq[dq.size()-2], dq.back(), L)) dq.pop_back();
        dq.push_back(L);
        if(i==n-1){
            cout << dpi << '\n';
        }
    }
    return 0;
}
