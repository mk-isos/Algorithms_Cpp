

// STL

// C++에는 미리 다양한 알고리즘과 자료구조가 STL에 구현
// 배열과 비슷한 기능을 수행하는 vector STL
// vector는 일종의 가변배열로 크기를 마음대로 늘렸다 줄였다 할 수 있다.

// 표준입출력

// scanf/printf에서 단 한 가지 아쉬운 점이라고 한다면, C++ string을 처리할 수가 없다.
// 아시다시피 C에서는 char*으로 문자열을 다루는데 사실 char*보다 C++ string이 월등하게 편하다.


#include <bits/stdc++.h>
using namespace std;

// 1. scanf의 옵션
char a1[10];
scanf("%[^\n]", a1);

// 2. gets 함수 (보안상의 이유로 C++14 이상에서는 제거됨)
char a2[10];
gets(a2);
puts(a2);

// 3. getline 함수
string s;
getline(cin, s);
cout << s;

// 3. getline 사용 (1은 외우기 힘들고, 2는 c++ 14이상에서 제거)

// ios::sync_with_stdio(0), cin.tie(0)
// scanf/printf와 다르게 cin/cout은 입출력으로 인한 시간초과를 막기 위해서 ios::sync_with_stdio(0), cin.tie(0)이라는 두 명령을 실행

// ios::sync_with_stdio(0)
// 코드의 흐름과 실제 출력이 동일하기 위해서 기본적으로 프로그램에서는 C++ stream과 C stream을 동기화하고 있습니다. 그런데 내가 C++ stream만 쓸거면 굳이 두 stream을 동기화하고 있을 필요가 없게 됩니다. 쓸데 없이 시간만 잡아먹으니까요.
// 그렇기 때문에 C++ stream만 쓸거면 동기화를 끊어버려서 프로그램 수행 시간에서 이득을 챙길 수 있고, 동기화를 끊는 명령이 sync_with_stdio(0)입니다. 엄밀히 말해 인자가 bool type이라 sync_with_stdio(false)가 더 맞긴 한데 false보다 0이 더 짧으니 그냥 0으로 하겠습니다.

// cin.tie(0)
// 굳이 cin 명령을 수행하기 전에 cout 버퍼를 비울 필요가 없다는걸 알 수 있습니다. 그래서 cin 명령을 수행하기 전에 cout 버퍼를 비우지 않도록 하는 코드가 cin.tie(nullptr)인거고, 엄밀히는 type을 지켜서 nullptr로 쓰는게 좋지만 그냥 타이핑도 아낄겸 0으로 쓰겠습니다.
// 자세히 다시 보려면 https://blog.encrypted.gg/923

// endl 절대 사용 금지
// endl은 개행문자("\n")를 출력하고 출력 버퍼를 비워라는 명령입니다
// endl 말고 그냥 개행문자를 출력하기

// 코딩테스트 코드 작성 팁

// 1번은 일단 필요한 헤더만 include 했고, 딱 크기에 맞게 n칸짜리 배열을 잡은 후에 해제까지 합니다
// 2번은 코딩테스트에서는 내가 헷갈리지 않는 범위 안에서 어떻게든 타이핑을 아끼는게 최고

// 코딩테스트의 목표는 남이 알아볼 수 있는 클린코드를 작성하는게 아닙니다. 어떻게든 제한된 시간 안에 정답을 받아야한다.

