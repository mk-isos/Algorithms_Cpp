#include <iostream>
using namespace std;

int main()
{
    while (true)
    {
        int N;
        cin >> N;
        if (N == 0)
            break;

        int result = 0;
        for (int i = 1; i <= N; ++i)
        {
            result += i * i;
        }

        cout << result << '\n';
    }
    return 0;
}
