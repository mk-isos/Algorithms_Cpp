#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    for (int i = 0; i < 3; ++i)
    {
        string str;
        cin >> str;

        if (str[0] == 'F' || str[0] == 'B')
        {
            continue;
        }

        int num = stoi(str) + 3 - i;

        if (num % 3 && num % 5)
        {
            cout << num;
        }
        else
        {
            if (num % 3 == 0)
            {
                cout << "Fizz";
            }

            if (num % 5 == 0)
            {
                cout << "Buzz";
            }
        }

        break;
    }
    return 0;
}