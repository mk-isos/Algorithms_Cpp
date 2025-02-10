#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        long long reversed = 0;
        int original = x;

        while (x > 0)
        {
            reversed = reversed * 10 + (x % 10);
            x /= 10;
        }

        return original == reversed;
    }
};

int main()
{
    Solution sol;
    int x;

    cin >> x;

    if (sol.isPalindrome(x))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
