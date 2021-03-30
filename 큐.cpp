#include <string>
#include <iostream>
#include <queue>  // queue가 들어있는 헤더파일

using namespace std;

int main(void)
{
    // queue <int> s;     //int형 큐 선언
    // queue <char>s;     //char형 큐 선언

    queue<int> q;  // int형 큐 선언
    q.push(1);     // queue에 값 1 추가
    q.push(2);     // queue에 값 2 추가
    q.push(3);     // queue에 값 3 추가
    q.pop();       // queue에 값 제거

    queue<int> s;  // int형 스택 선언
    s.push(1);     // queue에 값 1 추가
    s.push(2);     // queue에 값 2 추가
    s.push(3);     // queue에 값 3 추가

    cout << q.size() << '\n'; // queue의 크기 출력
    cout << q.empty() << '\n'; // queue가 비어있는지 check (비어있다면 true)
    cout << q.front() << '\n'; // queue의 가장 첫번째 원소 출력
    cout << q.back() << '\n'; // queue의 가장 마지막 원소 출력
}