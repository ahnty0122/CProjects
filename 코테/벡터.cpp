#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<string> vecName; // vector 선언

    vecName.push_back("태");
	vecName.push_back("영");
	vecName.push_back("이");

    cout << "** 벡터의 원소 ** " << endl;

	vector<string>::iterator pos = vecName.begin();

	for (; pos != vecName.end(); pos++)
    {
		cout << (*pos) << ' ';
	}

    cout << endl;

    // vector 다른 예시
    vector<int> v;
	// push_back
	// 1-2-3-4-5
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	// pop_back
	v.pop_back();

	// back and front
	cout << "vector front value: " << v.front() << '\n';
	cout << "vector end value: " << v.back() << '\n';

	// [i] and at(i)
	cout << "vector opeartor[]: " << v[2] << '\n';
	cout << "vector at: " << v.at(3) << '\n';

	// size
	cout << "vector size: " << v.size() << '\n';

	// empty
	cout << "Is it empty?: " << (v.empty() ? "Yes" : "No") << '\n';

	// iterator
	vector<int>::iterator begin_iter = v.begin(); // auto begin_iter = v.begin()도 가능
	vector<int>::iterator end_iter = v.end(); // auto end_iter = v.end()도 가능

	// get value by iterator
	cout << "vector begin value: " << *begin_iter << '\n';

	// for statement iteration using iterator
	for(vector<int>::iterator iter = v.begin(); iter != v.end(); iter++){
		cout << *iter << ' ';
	}
	cout << endl;
}