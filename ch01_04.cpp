//============================================================================
// Name        : ch01_04.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 * 200개 이하의 정수를 공백으로 구분하여 입력받아서 vector에 순서대로 채운 후, iterator를 이용해 다음과 같이 출력하시오.
• -1이 입력되면 입력을 끝냄 (-1은 vector에 추가하지 않는다)
• 출력:“[앞에서첫번째값과뒤에서첫번째값의합][앞에서두번째값과
뒤에서두번째값의합] ... ”
• 각 출력값들은 공백으로 구분
• 출력 끝에도 공백이 들어감
• 홀수개의 정수를 입력받은 경우, 마지막으로 출력하는 숫자는 입력받은 정수의 중간에 위치한 값
• 짝수개의 정수를 입력받은 경우, 마지막으로 출력하는 숫자는 중간에 위치한 두 정수의 합
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v1;

	int i;

	while(1)
	{
		cin >> i;
		if(i == -1) break;
		v1.push_back(i);
	}

	auto b = v1.begin();
	auto e = --v1.end();

	auto size = v1.size();
	auto hSize = size /2;

	int a = 0;

	for(; a < hSize; a++)
	{
		cout << *b + *e << " ";
		++b;
		--e;
	}
	if(size % 2 !=0)
		cout << *b << " ";
}
