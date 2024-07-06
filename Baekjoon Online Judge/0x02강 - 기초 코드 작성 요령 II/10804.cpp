#include <bits/stdc++.h>
using namespace std;

//STL reverse를 이용한 풀이
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cards[21]; 

    for (int i = 1; i <= 20; i++) cards[i] = i;
    

    for (int i = 0; i < 10; i++)
    {
        int a, b;
        cin >> a >> b;
        // 구간 [a, b]를 역순으로 변경
        reverse(cards + a, cards + b + 1);
    }

    for (int i = 1; i <= 20; i++) cout << cards[i] << " ";
    //cout << endl;

    return 0;
}

// 왜 바킹독님은 int cards[21]; 등을 전역변수로 둘까..?
