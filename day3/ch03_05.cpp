//============================================================================
// Name        : ch03_05.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <string>

using namespace std;



class board{

public:
	board() = default;

	char** arr=nullptr;
	int row=0;
	int col=0;

	void hi(int m, int n)
	{
		arr = new char*[m];
		for(int i = 0 ; i < m ; i ++)
		{
			arr[i] = new char[n];
		}

		row = m ; col = n;
		for(int i = 0 ; i < m ; i++)
		{
			for(int j = 0 ; j < n ; j ++)
			{
				arr[i][j] = 'O';
			}
		}
	}
	void clean()
	{
		for(int i = 0 ; i < row ; i++)
		{
			for(int j = 0 ; j < col ; j ++)
			{
				arr[i][j] = 'O';
			}
		}
	}

	void mark(int r, int c, char color)
	{
		arr[c-1][r-1] = color;
	}

	void vertical(int r, int c1, int c2, char color)
	{
		for(int i = c1-1; i < c2; i++)
		{
			arr[i][r-1] = color;
		}
	}
	void horizon(int r1, int r2, int c, char color){
		for(int i = r1-1 ; i < r2 ; i++)
		{
			arr[c-1][i] = color;
		}
	}

	void fill(int x1,int y1, int x2, int y2, char color){
		for(int i = x1 - 1 ; i < x2 ; i++)
		{
			for(int j = y1 - 1 ; j  < y2 ; j++)
			{
				arr[j][i] = color;
			}
		}
	}

	void rect(int x1,int y1, int x2, int y2, char color){
		for(int i = x1 - 1 ; i < x2 ; i++)
		{
			for(int j = y1 - 1 ; j < y2 ; j++)
			{
				if(j== y1 -1 || j == y2 - 1 || i == x1 -1 || i == x2 -1) arr[j][i] = color;
			}
		}
	}

	void change(int x, int y , char color){
		char oColor = arr[x-1][y-1];
		change(x,y,color,oColor);
	}
	void change(int x, int y , char color, char oColor){

		if(arr[x-1][y-1] == oColor){
				mark(y,x,color);
				if(x+1<=row)change(x+1,y,color,oColor);
				if(y-1 >= 1)change(x,y-1,color,oColor);
				if(x-1>=1)change(x-1,y,color,oColor);
				if(y+1<=col)change(x,y+1,color,oColor);
		}
	}
	void bye()
	{
		for(int i = 0 ; i < row ; i++)
		{
			for(int j = 0 ;j < col ; j++)
			{
				cout<<arr[i][j];
			}
			cout<<endl;
		}
	}
};
int main() {

	board example;
	string input;
	string a1,a2,a3,a4,a5,a6;

	while(1)
	{
		getline(cin,input);
		stringstream a;
		a.str(input);
		a >> a1;
		a >> a2;
		a >> a3;
		a >> a4;
		a >> a5;
		a >> a6;

		if(a1 == "hi")
		{
			example.hi(stoi(a2),stoi(a3));
		}
		if(a1 == "clean")
		{
			example.clean();
		}
		if(a1 == "mark")
		{
			example.mark(stoi(a2),stoi(a3),a4[0]);
		}
		if(a1 == "vertical")
		{
			example.vertical(stoi(a2),stoi(a3),stoi(a4),a5[0]);
		}
		if(a1 == "horizon")
		{
			example.horizon(stoi(a2),stoi(a3),stoi(a4),a5[0]);
		}
		if(a1 == "fill")
		{
			example.fill(stoi(a2),stoi(a3),stoi(a4),stoi(a5),a6[0]);
		}
		if(a1 == "rect")
		{
			example.rect(stoi(a2),stoi(a3),stoi(a4),stoi(a5),a6[0]);
		}
		if(a1 == "change")
		{
			example.change(stoi(a2),stoi(a3),a4[0]);
		}
		if(a1 == "bye")
		{
			example.bye();
			break;
		}
	}
}
