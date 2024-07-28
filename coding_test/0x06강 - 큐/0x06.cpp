/*
큐에 대한 강의 정리:
1. 큐(Queue)란?
   - 큐는 FIFO(First In First Out) 구조를 가지며, 한쪽 끝에서 원소를 넣고 반대쪽 끝에서 원소를 뺄 수 있는 자료구조.
   - 공항에서 입국수속을 하는 줄과 같은 상황.

2. 큐의 연산
   - 원소의 추가(push)와 제거(pop)는 O(1).
   - 가장 앞(front)과 가장 뒤(rear) 원소 확인도 O(1).

3. 큐의 구현
   - 배열 혹은 연결 리스트로 구현 가능.
   - 배열로 구현 시 head와 tail을 이용하여 큐를 관리.
   - 원소 추가 시 tail 증가, 제거 시 head 증가.
   - 원형 큐(Circular Queue)로 구현하면 삭제 시 생기는 공간 낭비 문제를 해결 가능.
   - 원형 큐에서는 head나 tail이 배열의 끝에 도달하면 0으로 돌아오도록 설정.

4. 큐의 STL 사용
   - 큐는 STL에서도 제공되며, BFS와 같은 알고리즘에서 자주 사용됨.
   - STL queue는 push, pop, front, back 등의 멤버 함수를 제공.

5. 예외 처리
   - 큐가 비어 있을 때 front나 back, pop을 호출하면 런타임 에러 발생 가능.

6. 연습문제
   - BOJ 10845번: 큐
   - STL을 사용한 큐와 직접 구현한 큐로 풀어보기.

다음 강의:
- 다음 단원에서는 덱(Deque)에 대해 다룰 예정. 덱을 배우면 DFS, BFS에서 큐의 활용이 더 많아질 것이다.
*/

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
}