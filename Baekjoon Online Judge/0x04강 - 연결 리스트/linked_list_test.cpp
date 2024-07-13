#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num) {
    dat[unused] = num;  // 우선 값만 있는 원소만 생성
    pre[unused] = addr; // 생성한 원소의 이전을 추가할 위치의 주소로 설정
    nxt[unused] = nxt[addr];    // 생성한 원소의 다음을 추가할 위치의 다음 주소로 설정
    if (nxt[addr] != -1) pre[nxt[addr]] = unused; // 이전/다음 원소의 포인터 변경
    nxt[addr] = unused;
    unused++;   //unused 값을 증가시켜 다음 insert에 사용
}
// 7. insert 함수
// - addr: 원소를 추가할 위치의 주소
// - insert(1, 30): 1번지 뒤에 30을 추가
// - 새 원소의 pre, nxt 값을 설정하고, 이전/다음 원소의 포인터 변경
// - unused 값을 증가시켜 다음 insert에 사용

// 8. erase 함수
// - addr: 제거할 원소의 주소
// - erase(1): 1번지의 원소를 제거
// - 이전 원소의 nxt를 변경하고, 다음 원소의 pre를 변경
// - 제거된 원소의 dat, pre, nxt 값은 변경하지 않아도 됨
void erase(int addr) {
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

void traverse() {
    int cur = nxt[0];
    while (cur != -1) {
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    cout << "\n\n";
}

void insert_test() {
    cout << "****** insert_test *****\n";
    insert(0, 10); // 10(address=1)
    traverse();
    insert(0, 30); // 30(address=2) 10
    traverse();
    insert(2, 40); // 30 40(address=3) 10
    traverse();
    insert(1, 20); // 30 40 10 20(address=4)
    traverse();
    insert(4, 70); // 30 40 10 20 70(address=5)
    traverse();
}

void erase_test() {
    cout << "****** erase_test *****\n";
    erase(1); // 30 40 20 70
    traverse();
    erase(2); // 40 20 70
    traverse();
    erase(4); // 40 70
    traverse();
    erase(5); // 40
    traverse();
}

int main(void) {
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);
    insert_test();
    erase_test();
}
