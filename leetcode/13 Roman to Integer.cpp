#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int result = 0, prev_value = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            int curr_value = roman[s[i]];
            if (curr_value < prev_value) result -= curr_value;
            else result += curr_value;
            prev_value = curr_value;
        }

        return result;
    }
};

int main() {
    FIO;
    Solution sol;
    string s;
    cin >> s;
    cout << sol.romanToInt(s) << "\n";
}
