//============================================================================
// Name        : ch01_06.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <string>
using namespace std;

int main() {

	string input;
	getline(cin, input);
	input.append(" e"); // marking the end of the sentence

	vector<int> nums; // only numbers
	vector<char> ops; // only operators

	int num;
	char op;

	stringstream stream1;

	stream1.str(input);
	while(1)
	{
	stream1 >> num;

	nums.push_back(num);

	stream1 >> op;

	if(op=='e') break;

	ops.push_back(op);
	}
	int d = 0;
	for(int i = 0 ; i < ops.size(); i++)
	{
		if(ops[i] == '*')
		{
			nums[i-d] = nums[i-d] * nums[i+1-d] ;
			nums.erase(nums.begin()+i+1-d);
			d++;
		}
	}

	int result = 0;

	for(int i = 0 ; i < nums.size(); ++i)
	{
		result = result + nums[i];
	}
	cout << result;
}
