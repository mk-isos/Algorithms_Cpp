#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int count2 = 0, counte = 0;
    for (char c : s) {
        if (c == '2') count2++;
        else if (c == 'e') counte++;
    }

    if (count2 > counte) cout << "2";
    else if (counte > count2) cout << "e";
    else cout << "yee";

    return 0;
}
