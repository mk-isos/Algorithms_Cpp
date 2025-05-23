#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        long long S;
        cin >> S;
        bool isValid = true;
        for (int i = 2; i <= 1000000; ++i)
        {
            if (S % i == 0)
            {
                isValid = false;
                break;
            }
        }
        cout << (isValid ? "YES" : "NO") << '\n';
    }
    return 0;
}
