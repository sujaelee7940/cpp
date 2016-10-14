//============================================================================
// Name        : ch04_05.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

int main() {

	int n;
	int numbers[10001] = {0};
	int number;

	scanf("%d",&n);

	while(n>0)
	{
		scanf("%d",&number);
		numbers[number] = numbers[number]+1;
		--n;
	}

	for(int i = 0 ; i < 10001; i++)
	{
		for(int j = 0; j < numbers[i] ; j++)
		{
			printf("%d\n",i);
		}
	}
}
