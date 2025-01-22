#include <bits/stdc++.h>
using namespace std;

/*
int main(void) {
    vector<int> v1(3, 5); // {5,5,5};
    cout << v1.size() << '\n'; // 3
    v1.push_back(7); // {5,5,5,7};

    vector<int> v2(2); // {0,0};
    v2.insert(v2.begin()+1, 3); // {0,3,0};

    vector<int> v3 = {1,2,3,4}; // {1,2,3,4}
    v3.erase(v3.begin()+2); // {1,2,4};

    vector<int> v4; // {}
    v4 = v3; // {1,2,4}
    cout << v4[0] << v4[1] << v4[2] << '\n';
    v4.pop_back(); // {1,2}
    v4.clear(); // {}
}
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Part 1: 벡터 반복

    vector<int> v = {1, 2, 3, 4, 5, 6};

     // 1. range-based for loop (since C++11)
    for (int c : v)
        cout << c << ' ';
    cout << endl;

    // 2. not bad
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;

    // Part 2: 다양한 벡터 연산

    // 크기 3이고 모든 요소가 5인 벡터 초기화
    vector<int> v1(3, 5); // {5,5,5}
    cout << "\nv1 초기화 후: ";
    for (int i : v1) cout << i << ' ';
    cout << "\nv1의 크기: " << v1.size() << '\n'; // 3

    // v1의 끝에 요소 추가
    v1.push_back(7); // {5,5,5,7}
    cout << "v1에 7 추가 후: ";
    for (int i : v1) cout << i << ' ';
    cout << '\n';

    // 크기 2이고 기본 요소가 0인 벡터 초기화
    vector<int> v2(2); // {0,0}
    cout << "\nv2 초기화 후: ";
    for (int i : v2) cout << i << ' ';
    
    // 두 번째 위치에 요소 삽입
    v2.insert(v2.begin() + 1, 3); // {0,3,0}
    cout << "\nv2의 1번째 위치에 3 삽입 후: ";
    for (int i : v2) cout << i << ' ';
    cout << '\n';

    // 특정 요소들로 초기화된 벡터
    vector<int> v3 = {1, 2, 3, 4}; // {1,2,3,4}
    cout << "\nv3 초기화 후: ";
    for (int i : v3) cout << i << ' ';

    // 세 번째 요소 제거
    v3.erase(v3.begin() + 2); // {1,2,4}
    cout << "\nv3의 2번째 요소 제거 후: ";
    for (int i : v3) cout << i << ' ';
    cout << '\n';

    // 벡터를 다른 벡터에 할당
    vector<int> v4; // {}
    v4 = v3; // {1,2,4}
    cout << "\nv3에서 v4로 할당 후: ";
    for (int i : v4) cout << i << ' ';
    cout << '\n';

    // 요소 접근
    cout << "v4의 첫 세 요소: ";
    cout << v4[0] << ' ' << v4[1] << ' ' << v4[2] << '\n';

    // 마지막 요소 제거
    v4.pop_back(); // {1,2}
    cout << "v4의 마지막 요소 제거 후: ";
    for (int i : v4) cout << i << ' ';
    cout << '\n';

    // 벡터 비우기
    v4.clear(); // {}
    cout << "v4 비운 후: ";
    for (int i : v4) cout << i << ' '; // 출력 없음
    cout << "(비어 있음)\n";

    return 0;
}

