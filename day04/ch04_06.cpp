//============================================================================
// Name        : ch04_06.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<long long, long long> lookUp;

long long fib(long long n , int mod)
{

	if(n==1)
		return 1;
	if(n==2)
		return 1;
	if(lookUp.find(n)!=lookUp.end())
	{
		if(lookUp.find(n)->second < 0){
			return (lookUp.find(n)->second) + mod;
		}
		return lookUp.find(n)->second;
	}

	if(n%2==0)
	{
		lookUp[n] = (fib(n/2,mod) % mod * ( 2 * fib(n/2+1,mod) % mod - fib(n/2,mod) % mod)) % mod;
		if(lookUp.find(n)->second < 0){
			return (lookUp.find(n)->second) + mod;
		}
		return lookUp.find(n)->second;
	}
	if(n%2==1)
	{
		lookUp[n] = (fib(n/2,mod) % mod * fib(n/2,mod) % mod  + fib(n/2+1,mod) % mod  * fib(n/2+1,mod)) % mod ;

		if(lookUp.find(n)->second < 0){
		return (lookUp.find(n)->second) + mod;
		}

		return lookUp.find(n)->second;
	}
}

int main() {

	int mod;
	cin >> mod;
	int n1;
	cin >> n1;

	vector<long long> n1s;
	n1s.reserve(n1);

	while(n1>0)
	{
		unsigned long long number1;
		cin >> number1;
		n1s.push_back(fib(number1,mod)%mod);
		--n1;
	}

	int n2;
	cin >> n2;

	vector<long long> n2s;
	n2s.reserve(n2);

	while(n2>0)
	{
		unsigned long long number2;
		cin >> number2;
		n2s.push_back(fib(number2,mod)%mod);
		if(find(n1s.begin(),n1s.end(),n2s.back())!=n1s.end())
		{
			cout << n2s.back() << " : 1\n";
		}
		else
		{
			cout << n2s.back() << " : 0\n";
		}
		--n2;
	}
}
