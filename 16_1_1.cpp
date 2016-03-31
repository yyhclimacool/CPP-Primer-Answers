#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <list>

using namespace std;

template<typename T, typename V>
T myfind(T lhs, T rhs, const V &val) {
	while (lhs != rhs) {
		if (*lhs == val)
			return lhs;
		++lhs;
	}
	return rhs;
}

template<typename T,unsigned N>
void print(const T(&cp)[N]) {
	for (const auto &elem : cp)
		cout << elem;
}

template<typename T, unsigned N>
T *mybegin(T(&tp)[N]){
	return &tp;
}

template<typename T, unsigned N>
T *myend(T(&tp)[N]) {
	return (tp+N);
}

template<typename T, size_t N>
constexpr size_t array_size(T(&tp)[N]) {
	return N;
}

int main()
{
	vector<int> ivec = { 1,2,3,4,5,6,7,8,9,0 };
	list<string> slst = { "I", "wanna", "fuck", "you" };
	auto iter = myfind(ivec.begin(), ivec.end(), 10);
	if (iter != ivec.end())
		*iter = 999;
	else
		cout << "not found" << endl;
	for (const auto &elem : ivec) {
		cout << elem << " ";
	}
	cout << endl;

	auto it = myfind(slst.cbegin(), slst.cend(), "fuck");
	if (it != slst.cend())
		cout << "fuck found" << endl;
	else
		cout << "fuck not found" << endl;

	cout << "calling print() template function:" << endl;
	print("do it for youself");
	cout << endl;

	//int ia[] = { 1,2,3,4,5,6,7,8,9 };
	char ia[] = "we";
	print(ia);
	cout << endl;
	*(myend(ia)-1) = 'A';
	print(ia);
	cout << endl;

	cout << array_size(ia) << endl;
}
