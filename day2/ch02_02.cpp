//============================================================================
// Name        : ch02_02.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int n;

	cin >> n;

	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < n + i; j++ )
		{
			if( i == n-1) cout << "*";
			else
				{
				if(j == n+i-1 || j == n+i-1-2*i) cout << "*";
				else cout << " ";
				}
		}
		cout << endl;
	}
}
