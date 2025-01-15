#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int freq[26];
int main(){
    FIO;

    string s;
    cin >> s;
    for(auto c : s){
        freq[c-'a']++;
    }
    for(int i=0;i<26;i++){
        cout << freq[i] <<' ';
    }

    return 0;
}