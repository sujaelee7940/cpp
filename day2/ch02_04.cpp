//============================================================================
// Name        : ch02_04.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void hTower(int a, int b, int c)
{
	int d = 1;

	if(d == b || d == c) d = 2;
	if(d == b || d == c) d = 3;

	if(a == 1) cout << 1 << " : " << b << " -> " << c << endl;
	else
	{ hTower(a-1,b,d);
	cout << a << " : " << b << " -> " << c << endl ;
	hTower(a-1,d,c);
	}
}

int main() {

	int a, b, c;
	cin >> a >> b >> c;
	hTower(a,b,c);
}
