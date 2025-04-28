// 엄청난 부자2 - BigInteger 나눗셈 구현

#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

char a[1001], b[1001], q[1001];

char *big(char *a, char *b)
{
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] < b[i])
            return b;
        if (a[i] > b[i])
            return a;
    }
    return a;
}

void subtract(char *a, char *b)
{
    for (int i = 0; i < strlen(b); i++)
    {
        a[i] = a[i] - b[i] + '0';
    }
    for (int i = strlen(b) - 1; i >= 0; i--)
    {
        if (a[i] < '0')
        {
            a[i] += 10;
            a[i - 1]--;
        }
    }
}

void devidesubtract(char *a, char *b, char *q, int index)
{
    q[index] = '0';
    while (a[index - 1] > '0' || big(a + index, b) == a + index)
    {
        subtract(a + index, b);
        ++q[index];
    }
}

void devide(char *a, char *b, char *q)
{
    int index = 0;
    int digit = strlen(a) - strlen(b);
    while (index <= digit)
    {
        devidesubtract(a, b, q, index++);
    }
    q[index] = '\0';
}

int main()
{
    FIO;
    cin >> a >> b;
    devide(a, b, q);

    int qi = 0, ai = 0;
    while (q[qi] == '0' && q[qi + 1] != '\0')
        qi++;
    while (a[ai] == '0' && a[ai + 1] != '\0')
        ai++;

    cout << q + qi << '\n';
    cout << a + ai << '\n';

    return 0;
}
