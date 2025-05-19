#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    return n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17;
}

int main()
{
    double a, b;
    cin >> a >> b;
    a /= 100.0;
    b /= 100.0;

    vector<vector<double>> dp_a(19, vector<double>(19, 0.0));
    vector<vector<double>> dp_b(19, vector<double>(19, 0.0));

    dp_a[0][0] = 1.0;
    dp_b[0][0] = 1.0;

    for (int i = 1; i <= 18; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (j > 0)
                dp_a[i][j] += dp_a[i - 1][j - 1] * a;
            dp_a[i][j] += dp_a[i - 1][j] * (1 - a);

            if (j > 0)
                dp_b[i][j] += dp_b[i - 1][j - 1] * b;
            dp_b[i][j] += dp_b[i - 1][j] * (1 - b);
        }
    }

    double result = 0.0;
    for (int i = 0; i <= 18; ++i)
    {
        for (int j = 0; j <= 18; ++j)
        {
            if (is_prime(i) || is_prime(j))
            {
                result += dp_a[18][i] * dp_b[18][j];
            }
        }
    }

    cout << fixed << setprecision(10) << result << '\n';
    return 0;
}
