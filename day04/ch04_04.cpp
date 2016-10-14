//============================================================================
// Name        : ch04_04.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

struct Soccer{
	string nation;
	int howMany = 0;
	int point = 0;
	int win = 0;
	int draw = 0;
	int lose = 0;
	int getGoal = 0;
	int loseGoal = 0;
	int totalGoal = 0;

	int rank;
};

bool compareRule(const Soccer &a, const Soccer &b)
{
	if(a.point==b.point)
		{
		if(a.win == b.win )
		{
			if(a.totalGoal == b.totalGoal)
			{
				if(a.getGoal == b.getGoal)
				{
					if(a.howMany==b.howMany)
					{
						return a.nation < b.nation;
					}
					return a.howMany < b.howMany;
				}
				return a.getGoal > b.getGoal;
			}
			return a.totalGoal > b.totalGoal;
		}
		return a.win > b.win;
		}
    return a.point > b.point;
}
int main() {
	vector<Soccer> nations;


	while(1)
	{
		stringstream a;
		string input;
		getline(cin,input);

		a.str(input);

		string nation1;
		string nation2;

		string forPoint1;
		string forPoint2;

		int point1;
		int point2;
		a >> nation1;
		a >> forPoint1;
		a >> forPoint2;
		a >> nation2;
		if(nation1=="end") break;
		else
		{
			point1 = stoi(forPoint1); point2 = stoi(forPoint2);
			int find1 = -1, find2 = -1;

			for(int i = 0 ; i < nations.size(); i++)
			{
				if(nations[i].nation==nation1) find1 = i;
				if(nations[i].nation==nation2) find2 = i;
			}

			if(find1 == -1)
			{
				nations.push_back(Soccer());
				nations.back().nation=nation1;
				if(point1>point2)
				{
					nations.back().point += 3;
					nations.back().win += 1;
				}
				if(point1==point2)
				{
					nations.back().point += 1;
					nations.back().draw += 1;
				}
				if(point1<point2)
				{
					nations.back().point += 0;
					nations.back().lose += 1;
				}

				nations.back().howMany ++;
				nations.back().getGoal += point1;
				nations.back().loseGoal += point2;
				nations.back().totalGoal = nations.back().getGoal - nations.back().loseGoal;
			}
			if(find2 == -1)
			{
				nations.push_back(Soccer());
				nations.back().nation=nation2;
				if(point1<point2)
				{
					nations.back().point += 3;
					nations.back().win += 1;
				}
				if(point1==point2)
				{
					nations.back().point += 1;
					nations.back().draw += 1;
				}
				if(point1>point2)
				{
					nations.back().point += 0;
					nations.back().lose += 1;
				}

				nations.back().howMany ++;
				nations.back().getGoal += point2;
				nations.back().loseGoal += point1;
				nations.back().totalGoal = nations.back().getGoal - nations.back().loseGoal;
			}
			if(find1 != -1)
			{
				if(point1>point2)
				{
					nations[find1].point += 3;
					nations[find1].win += 1;
				}
				if(point1==point2)
				{
					nations[find1].point += 1;
					nations[find1].draw += 1;
				}
				if(point1<point2)
				{
					nations[find1].point += 0;
					nations[find1].lose += 1;
				}

				nations[find1].howMany ++;
				nations[find1].getGoal += point1;
				nations[find1].loseGoal += point2;
				nations[find1].totalGoal = nations[find1].getGoal - nations[find1].loseGoal;
			}
			if(find2 != -1)
			{
				if(point1<point2)
				{
					nations[find2].point += 3;
					nations[find2].win += 1;
				}
				if(point1==point2)
				{
					nations[find2].point += 1;
					nations[find2].draw += 1;
				}
				if(point1>point2)
				{
					nations[find2].point += 0;
					nations[find2].lose += 1;
				}

				nations[find2].howMany ++;
				nations[find2].getGoal += point2;
				nations[find2].loseGoal += point1;
				nations[find2].totalGoal = nations[find2].getGoal - nations[find2].loseGoal;
			}
		}
	}

if(nations.size()>=1){
std::sort(nations.begin(), nations.end(), compareRule);

nations[0].rank = 1;
for(int i = 0, j = 1 ; i < nations.size(); i++)
{
	if(i > 0)
	{
		if(nations[i].howMany == nations[i-1].howMany && nations[i].point == nations[i-1].point && nations[i].getGoal == nations[i-1].getGoal && nations[i].totalGoal == nations[i-1].totalGoal)
		{
			nations[i].rank = nations[i-1].rank;
		}
		else
		{
			++j;
			nations[i].rank = j;
		}
	}
}

	for(auto a : nations)
	{
		cout <<a.rank<<") " << a.nation << " " << a.howMany << "G " << a.point << "P " << a.win << "-" << a.draw << "-" << a.lose << " " << a.getGoal <<"/" << a.loseGoal <<"/" << a.totalGoal << endl;
	}
}
}
