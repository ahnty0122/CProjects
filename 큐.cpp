#include <string>
#include <iostream>
#include <queue>  // queue�� ����ִ� �������

using namespace std;

int main(void)
{
    // queue <int> s;     //int�� ť ����
    // queue <char>s;     //char�� ť ����

    queue<int> q;  // int�� ť ����
    q.push(1);     // queue�� �� 1 �߰�
    q.push(2);     // queue�� �� 2 �߰�
    q.push(3);     // queue�� �� 3 �߰�
    q.pop();       // queue�� �� ����

    queue<int> s;  // int�� ���� ����
    s.push(1);     // queue�� �� 1 �߰�
    s.push(2);     // queue�� �� 2 �߰�
    s.push(3);     // queue�� �� 3 �߰�

    cout << q.size() << '\n'; // queue�� ũ�� ���
    cout << q.empty() << '\n'; // queue�� ����ִ��� check (����ִٸ� true)
    cout << q.front() << '\n'; // queue�� ���� ù��° ���� ���
    cout << q.back() << '\n'; // queue�� ���� ������ ���� ���
}