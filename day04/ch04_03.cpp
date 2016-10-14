//============================================================================
// Name        : ch04_03.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int checkPrime(int n){

	int i;
	int flag=1;


	for(int i = 2 ; i <= n/2 ; i++)
	{
		if(n%i==0)
		{
			flag=0;
			break;
		}
	}
	return flag;
}

int main() {

	vector<int> numbers;
	int number;



	while(1)
	{
		cin >> number;
		if(number==-1) break;
		else numbers.push_back(number);
	}

	sort(numbers.begin(),numbers.end());

	vector<int>::iterator it;

	it = unique( numbers.begin(), numbers.end());

	numbers.resize( distance(numbers.begin(),it));

	it = remove_if(numbers.begin(),numbers.end(),checkPrime);

	numbers.resize( distance(numbers.begin(),it));



	for(auto a : numbers)
	{
		cout<< a << " ";
	}
}
