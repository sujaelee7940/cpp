//============================================================================
// Name        : ch03_04.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

using namespace std;

class board{

public:
	board() = default;

	board(int r, int c) :
		row(r), col(c)
	{
		arr = new char*[r];
		for(int i = 0 ; i < r ; i ++)
		{
			arr[i] = new char[c];
		}
	}
	char** arr;

	void setElement(int a, int b, char c)
	{
		arr[a][b] = c;
	}

	string checkLeft(int r, int c, string ch)
	{
		int count = 0 ;
		int i;
		int k = ch.length();

		for(i = c ; i >=0 && k>0 ; i--, k--)
		{
			if(arr[r][i] == ch[count]) ++count;
		}

		if(count != ch.length()) return "false";
		else return to_string(r+1)+" "+to_string(c+1);
	}
	string checkRight(int r, int c, string ch)
	{
		int count = 0 ;
		int i;
		int k = ch.length();

		for(i = c ; i < col && k >0  ; i++, k--)
		{
			if(arr[r][i] == ch[count]) ++count;
		}

		if(count != ch.length()) return "false";
		else return to_string(r+1)+" "+to_string(c+1);
	}
	string checkDown(int r, int c, string ch)
	{
		int count = 0 ;
		int i;
		int k = ch.length();

		for(i = r ; i < row && k > 0 ; i++, k--)
		{
			if(arr[i][c] == ch[count]) ++count;
		}

		if(count != ch.length()) return "false";
		else return to_string(r+1)+" "+to_string(c+1);
	}
	string checkUp(int r, int c, string ch)
	{
		int count = 0 ;
		int i;
		int k = ch.length();

		for(i = r ; i >= 0 && k>0 ;  i--,k--)
		{
			if(arr[i][c] == ch[count]) ++count;
		}

		if(count != ch.length()) return "false";
		else return to_string(r+1)+" "+to_string(c+1);
	}
	string checkD1(int r, int c, string ch)
	{
		int count = 0 ;
		int i,j;
		int k = ch.length();

		for(i = r, j = c ; i >=0 && j >=0 && k>0 ; i--, j--,k--)
		{
			if(arr[i][j] == ch[count]) ++count;
		}

		if(count != ch.length()) return "false";
		else return to_string(r+1)+" "+to_string(c+1);
	}
	string checkD2(int r, int c, string ch)
	{
		int count = 0 ;
		int i,j;
		int k = ch.length();

		for(i = r, j = c ; i >=0 && j < col && k > 0  ; i--, j++, k--)
		{
			if(arr[i][j] == ch[count]) ++count;
		}

		if(count != ch.length()) return "false";
		else return to_string(r+1)+" "+to_string(c+1);
	}
	string checkD3(int r, int c, string ch)
	{
		int count = 0 ;
		int i,j;
		int k = ch.length();

		for(i = r, j = c ; i < row && j >=0 && k > 0 ; i++, j--,k--)
		{
			if(arr[i][j] == ch[count]) ++count;
		}

		if(count != ch.length()) return "false";
		else return to_string(r+1)+" "+to_string(c+1);
	}
	string checkD4(int r, int c, string ch)
	{
		int count = 0 ;
		int i,j;
		int k = ch.length();

		for(i = r, j = c ; i < row && j < col && k > 0 ; i++, j++,k--)
		{
			if(arr[i][j] == ch[count]) ++count;
		}

		if(count != ch.length()) return "false";
		else return to_string(r+1)+" "+to_string(c+1);
	}

	string check(int r, int c, string ch)
	{
		string answer = "false";

		answer = checkLeft(r,c,ch);
		if(answer != "false") return answer;
		answer = checkRight(r,c,ch);
		if(answer != "false") return answer;
		answer = checkUp(r,c,ch);
		if(answer != "false") return answer;
		answer = checkDown(r,c,ch);
		if(answer != "false") return answer;
		answer = checkD1(r,c,ch);
		if(answer != "false") return answer;
		answer = checkD2(r,c,ch);
		if(answer != "false") return answer;
		answer = checkD3(r,c,ch);
		if(answer != "false") return answer;
		answer = checkD4(r,c,ch);
		if(answer != "false") return answer;
		return answer;

	}

	int col = 0;
	int row = 0;
private:

};

int main() {

	int a,b,c;
	char ch;
	string line;
	string answer;
	string finalAnswer;

	string forTest;

	cin >> a >> b >> c;
	cin.ignore(); // it ignores \n

	board test(b,c);

	int rowCount = 0;

	while(b>0)
	{
		getline(cin,line);

		for(int i = 0 ; i < c; i++)
		{
			test.setElement(rowCount,i,tolower(line[i]));
		}
		--b;
		++rowCount;
	}

	while(a>0){

		answer = "false";

	getline(cin,forTest);

	for(auto &cha : forTest){
	cha = tolower(cha);
	}

	for(int ii = 0 ; ii < test.row && answer == "false" ; ii++)
	{
		for(int jj = 0 ; jj < test.col && answer == "false" ; jj++)
		{
			answer = test.check(ii,jj,forTest);
		}
	}
	finalAnswer += answer + '\n' ;
	--a;
	}
	finalAnswer.erase ( finalAnswer.end()-1);
	cout << finalAnswer;
}
