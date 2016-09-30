//============================================================================
// Name        : ch02_05.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <ctype.h>
using namespace std;

int priority(char oper)
{
	switch(oper)
	{
	case '(' : return 1; break;
	case '+' : case('-') : return 2; break;
	default : return 3; break;
	}
}

double calculator(double a, double b, char ope)
{
	double answer;
	switch(ope)
	{
	case '+' : answer = a + b; break;
	case '-' : answer = a - b; break;
	case '*' : answer = a * b; break;
	case '/' : answer = a / b; break;
}
	return answer;
}

void unary(string& input)
{
	for(int i = 0 ; i < input.size(); i++)
	{
		if(input[i]=='-')
		{

			if(i+1 < input.size() && input[i+1] == '(')
			{
				if(i==0){
					input.replace(i,1," -1*");
					i = i+2;
					;
				}
				else{
				input.replace(i,1,"- 1*");
				i = i+2;
				}
			}

			else{

			if(input[i-1]==')') {;}
			else if(i==0 || (input[i-1]!='B'&&input[i-1]!='A'&&!isdigit(input[i-1]))) // 맨 앞에 있거나 앞에가 연산자
			{
			input.insert(i," ");
			i++;
			}

			}
		}
	}


}

void toPost(string &input, vector<string> &stack, vector<string> &postfixExp)
{
	int digitCount = 1;

	for(auto &c : input)
		{
			int index = &c-&input[0];
			int unaryFlag;

			if(c=='(')
			{
				stack.push_back(string(1,c));
				digitCount = 1;
			}

			else if(c==')')
			{
				while(stack.back()!="(")
				{
					postfixExp.push_back(string(1,' '));
					postfixExp.push_back(stack.back());
					stack.pop_back();
				}
				stack.pop_back();
				digitCount = 1;
			}

			else if( ( (c != 'A') && (c!='B')&& !isdigit(c)  ) && c != ' ')
			{
				if(c=='-' && input[index-1]==' ' ) unaryFlag = 1; //meaning unary -

				else
				{
				postfixExp.push_back(string(1,' '));
				while( (!stack.empty())&& ( priority(stack.back()[0])>=priority(c) ))
				{
					postfixExp.push_back(stack.back());
					postfixExp.push_back(string(1,' '));
					stack.pop_back();
				}
				stack.push_back(string(1,c));
				}
				digitCount = 1;
			}

			else if(isdigit(c) || c=='A' || c=='B' )
				{
				if(unaryFlag==1) {
					postfixExp.push_back(string(1,'-'));
				}
				unaryFlag = 0;
				if(digitCount>1){
					postfixExp.back() += c;
				}
				else{
				postfixExp.push_back(string(1,c));
				digitCount++;
				}
				}
		}

		while(!stack.empty())
		{
			postfixExp.push_back(string(1,' '));
			postfixExp.push_back(stack.back());
			stack.pop_back();
		}

}


double calculator2(double a, double b, vector<string> c)
{
	double finalAnswer;

	for(int i = 0 ; i < c.size() ; i++)
	{
		if(c[i] == "A")
			{
			if(a<0){
				c.insert(c.begin()+i,"-");
				c[i+1] = to_string(-a);
				++i;
			}
			else{c[i] = to_string(a);}
			}
		if(c[i] == "B")
			{
			if(b<0){
				c.insert(c.begin()+i,"-");
				c[i+1] = to_string(-b);
				++i;
			}
			else{c[i] = to_string(b);}
			}
	}

	double calLeft, calRight, answer;
	char forOperator;

	//operator 만나면 && unary 아니라면 -> 거기서부터 왼쪽으로 돌아서 공백을 3개 찾아냄 그리고 계산함.
	int j;

	for(int i = 0 ; i < c.size(); i++)
	{
		if(!isdigit(c.at(i)[0]) && c.at(i)!=" ")
		{
			if( (c.at(i)[0]=='-') && (i+1 < c.size()) && (isdigit(c.at(i+1)[0]))) {;}

			else
			{
				forOperator = c.at(i)[0];

				int blankCount = 0;

				for( j = i-1 ; j >= 0 && blankCount<3 ; j--)
				{
					if(c.at(j) == " ")
					{
						++blankCount;

					}
					else
						{
						if(blankCount==1)
					{
						calRight = stod(c.at(j));
						if(j>0 &&c.at(j-1)=="-")
						{
							calRight *= -1;
							--j;
						}
					}
					if(blankCount==2)
					{
						calLeft = stod(c.at(j));
						if(j > 0 && c.at(j-1)=="-")
						{
							calLeft *= -1;
							--j;
						}

					}
						}
				}
				j++;
				if(blankCount==3) j += 1;

				if(forOperator == '+' || forOperator == '-' || forOperator == '*' || forOperator == '/')
				{
					answer = calculator(calLeft,calRight,forOperator);}

				c.insert(c.begin()+j,to_string(answer));
				++i;

				c.erase(c.begin()+j+1,c.begin()+i+1);
				i -= i-j;
			}
		}
	}
	finalAnswer = stod(c[0]);
	return finalAnswer;
}

int main() {

	int i;
	cin >> i;

	vector<char> cards;
	vector< vector<string> > cardLine;


	while(i > 0){
	char cardSign;
	cin >> cardSign;
	cards.push_back(cardSign);

	string cardL;
	cin >> cardL;

	unary(cardL);

	vector<string> tempStack;
	vector<string> tempPostfixExp;

	toPost(cardL,tempStack,tempPostfixExp);

	//process(tempPostfixExp,cards,cardLine);


	cardLine.push_back(tempPostfixExp);

	--i;
	}
		string input;
		cin >> input;

	vector<string> stack;
	vector<string> postfixExp;

	unary(input);

	// 중위연산 -> 후위연산 바꾸는 로직

	toPost(input,stack,postfixExp);

	// 후위연산 돌아다니면서 계산

	double calLeft, calRight, answer;
	char forOperator;

	int j;

	for(int k = 0 ; k < postfixExp.size() -1 ; k++)
	{
		if(postfixExp[k] == "-")
		{
			if(isdigit(postfixExp[k+1][0]))
			{
				postfixExp.erase(postfixExp.begin()+k,postfixExp.begin()+k+1);
				--k;
				double tempValue = stod(postfixExp[k+1]);
				tempValue *= -1;
				postfixExp[k+1] = to_string(tempValue);
			}
		}
	}


	for(int i = 0 ; i < postfixExp.size(); i++)
	{

		if(postfixExp.at(i).length()==1 && !isdigit(postfixExp.at(i)[0]) && postfixExp.at(i)!=" ")
		{
			if( (postfixExp.at(i)[0]=='-') && (i+1 < postfixExp.size()) && (isdigit(postfixExp.at(i+1)[0]))) {;}

			else
			{
				forOperator = postfixExp.at(i)[0];

				int blankCount = 0;

				for( j = i-1 ; j >= 0 && blankCount<3 ; j--)
				{
					if(postfixExp.at(j) == " ")
					{
						++blankCount;

					}
					else
						{
						if(blankCount==1)
					{
						calRight = stod(postfixExp.at(j));
						if(j>0 &&postfixExp.at(j-1)=="-")
						{
							calRight *= -1;
							--j;
						}
					}
					if(blankCount==2)
					{
						calLeft = stod(postfixExp.at(j));
						if(j > 0 && postfixExp.at(j-1)=="-")
						{
							calLeft *= -1;
							--j;
						}
					}
						}
				}
				j++;
				if(blankCount==3) j += 1;

				if(forOperator == '+' || forOperator == '-' || forOperator == '*' || forOperator == '/')
				{answer = calculator(calLeft,calRight,forOperator);

				postfixExp.insert(postfixExp.begin()+j,to_string(answer));
				++i;

				postfixExp.erase(postfixExp.begin()+j+1,postfixExp.begin()+i+1);
				i -= i-j;


				}
				else
				{
					auto signLoc = find(cards.begin(), cards.end(), forOperator);
					int where = signLoc - cards.begin();

					postfixExp.insert(postfixExp.begin()+j,begin(cardLine[where]),end(cardLine[where]));

					i += cardLine[where].size();

					postfixExp.erase(postfixExp.begin()+j+cardLine[where].size(),postfixExp.begin()+i+1);
					i -= i+1-j-cardLine[where].size();




					for(int k = 0 ; k < cardLine[where].size() ; k++)
					{
						if(postfixExp[j+k] == "A")
							{
									postfixExp[j+k] = to_string(calLeft);

							}
						if(postfixExp[j+k] == "B")
							{
									postfixExp[j+k] = to_string(calRight);
							}
					}

					i=0;
				}
				for(int k = 0 ; k < postfixExp.size() -1 ; k++)
				{
					if(postfixExp[k] == "-")
					{
						if(isdigit(postfixExp[k+1][0]))
						{
							postfixExp.erase(postfixExp.begin()+k,postfixExp.begin()+k+1);
							--k;
							double tempValue = stod(postfixExp[k+1]);
							tempValue *= -1;
							postfixExp[k+1] = to_string(tempValue);
						}
					}
				}
			}
		}

	}

	double finalAnswer = stod(postfixExp[0]);
	cout.precision(3);
	cout<<fixed<<finalAnswer<<endl;
}

