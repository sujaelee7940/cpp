//============================================================================
// Name        : ch03_06.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

class BigInteger {
public :
	BigInteger()  = default	;

	BigInteger(string _value): value(_value) {}


	BigInteger &operator=(const BigInteger &bi){
		value = bi.value;
		return *this;
	}
	BigInteger &operator+(const BigInteger &bi){

		int o = this->value.length();
		int o2 = bi.value.length();

		BigInteger temp = bi;

		char up[300];
		for(int i = 0 ; i < 300 ; i++)
		{
			up[i] = '0';
		}

		if( o < o2)
		{
			for(int i = 0 ;i < o2 - o; i++)
			{
			this->value.insert(0,"0");
			}
		}
		if( o > o2)
		{
			for(int i = 0 ;i < o-o2; i++)
			{
			temp.value.insert(0,"0");
			}
		}
		o = this->value.length();
		o2 = bi.value.length();
		for(int i = o - 1  ; i > 0 ; i--)
		{

			int val = this->value[i] - '0' + temp.value[i] -'0' + up[i] -'0';

			if(val >= 10 )
				{
				up[i-1] = '1' ;
				val -= 10;
				}

				this->value[i] = val +'0';
		}

		int val = this->value[0] - '0' + temp.value[0] - '0' + up[0] - '0';
		if(val<10){

			this->value[0] = val +'0';
		}
		else
		{
				this->value.insert(0,to_string(val));
				this->value.erase(2,1);

		}
			return *this;
	}

	BigInteger &operator*(const BigInteger &bi){


		char up[300];
		int o = this->value.length();
		int o2 = bi.value.length();

		string temp = bi.value;
		BigInteger answer("0");

		int times = 0;

		while(o2>0){
			string temp2 = "";

			for(int i = 0 ; i < 300 ; i++)
			{
				up[i] = '0';
			}

		for(int i = o - 1  ; i > 0 ; i--)
		{


			int val = ((this->value[i] - '0') * (temp[o2-1] -'0')) + up[i] -'0';

			if(val >= 10 )
				{
				up[i-1] = (int)val/10 + '0';
				val %= 10;
				}
				temp2.insert(0,to_string(val));
		}

		int val = ((this->value[0] - '0') * (temp[o2-1] -'0')) + up[0] -'0';
		if(val<10){
			temp2.insert(0,to_string(val));
		}
		else
		{
			string str = to_string(val);
				temp2.insert(0,str);
		}
		for(int k = 0; k < times ; k++)
		{
			temp2.append("0");
		}

		BigInteger x(temp2);

		answer = answer + x;


		++times;
		--o2;

		}

		this->value = answer.value;

		return *this;
	}

	string value;

private:
};


int main() {

	string input;
	getline(cin, input);
	input.append("e"); // marking the end of the sentence

	vector<BigInteger> nums; // only numbers
	vector<char> ops; // only operators

	char op;
	string a ="";

	for(int i = 0 ; i>=0 ;i++)
	{
	if(input[i] == '*' || input[i] == '+')
	{
		BigInteger num(a);
		nums.push_back(num);
		a="";
		ops.push_back(input[i]);
	}
	else{ if( input[i]=='e')
	{
		BigInteger num(a);
		nums.push_back(num);
		break;
	}
	else
	{
		a+= input[i];
	}
	}
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

	BigInteger result("0");
	for(int i = 0 ; i < nums.size(); ++i)
	{
		result = result + nums[i];
	}
	cout << result.value;


}
//100000000+200000000*3000000+4000000
