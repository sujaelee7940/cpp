//============================================================================
// Name        : ch02_03.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


int max(int,int);
int max(int,int,int);
int max(int* arr, int size)
{
	static int max = *arr;

	for(int i = 0; i < size ; i++)
	{
		if(max < *(arr+i) ) max = *(arr+i);
	}
	return max;
}

int max(int a, int b)
{
	static int max = a;
	if(a < b) max = b;
	return max;
}

int max(int a, int b, int c)
{
	static int max = a;
	if(a < b) max = b;
	if(b < c) max = c;
	return max;
}


int main() {
	int a = 0;
	int b = 2;
	int c = 3;
	int arr[8] = {2,0,1,6,0,9,2,3};

	cout << max(a,b)<<endl;
	cout << max(a,b,c) << endl;
	cout << max(arr,8)<< endl;

}
