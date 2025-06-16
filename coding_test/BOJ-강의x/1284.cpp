#include <iostream>
#include <string>
using namespace std;

int getWidth(char digit)
{
    if (digit == '0')
        return 4;
    if (digit == '1')
        return 2;
    return 3;
}

int main()
{
    string num;

    while (cin >> num && num != "0")
    {
        int width = 0;
        for (char ch : num)
        {
            width += getWidth(ch);
        }

        width += num.length() - 1 + 2;

        cout << width << '\n';
    }

    return 0;
}
