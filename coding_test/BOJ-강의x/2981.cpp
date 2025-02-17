#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    FIO;

    int N;
    cin >> N;

    vector<int> numbers(N);
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    int g = numbers[1] - numbers[0]; // 첫 번째 차이로 초기화
    for (int i = 2; i < N; i++)
    {
        g = gcd(g, numbers[i] - numbers[i - 1]);
    }

    vector<int> result;
    for (int i = 2; i * i <= g; i++)
    {
        if (g % i == 0)
        {
            result.push_back(i);
            if (i != g / i)
                result.push_back(g / i);
        }
    }
    result.push_back(g);

    sort(result.begin(), result.end());
    for (int m : result)
    {
        cout << m << " ";
    }

    return 0;
}
