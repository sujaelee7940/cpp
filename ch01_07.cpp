//============================================================================
// Name        : ch01_07.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <string>
using namespace std;

int main() {
	vector< vector<string> > allMovies; // 0th row -> genre, 1st,2nd,3rd... movie

	string input, command, commandGenre, commandMovie;



	while(1)
	{

		getline(cin,input);

		stringstream a;

		a.str(input);

		a >> command;
		a >> commandGenre;
		a >> commandMovie;

		if(command == "exit") break;

		if(command == "add_genre")
		{
			vector<string> genre;
			genre.push_back(commandGenre);
			allMovies.push_back(vector<string>(1,commandGenre));

		}
		if(command == "add_movie")
		{
			for(int i = 0; i<allMovies.size() ; i ++)
			{
				if(allMovies[i][0] == commandGenre)
				{
					vector<string>* row = &allMovies[i];
					row -> push_back(commandMovie);
				}
			}
		}
		if(command == "remove_genre")
		{
			for(int i = 0 ; i < allMovies.size(); i++)
			{
				if(allMovies[i][0] == commandGenre)
				{
					allMovies.erase(allMovies.begin()+i);
				}
			}
		}

		if(command == "remove_movie")
		{
			for(int i = 0; i<allMovies.size() ; i ++)
			{
				if(allMovies[i][0] == commandGenre)
				{
					for(int j = 0 ; j < allMovies[i].size() ;j++)
					{
						if(allMovies[i][j] == commandMovie){
							allMovies[i].erase(allMovies[i].begin()+j);
						}
					}
				}
			}
		}
		if(command == "print_genre")
		{
			for(int i = 0 ; i < allMovies.size(); i++)
			{
				if(allMovies[i][0] == commandGenre)
				{
					cout << "--" << commandGenre << "--";
					cout << endl;

					for(int j = 1 ; j < allMovies[i].size() ;j++)
					{
						cout << allMovies[i][j];
						cout << endl;
					}
				}
			}
		}
		if(command == "print_all")
		{
			for(int i = 0 ; i < allMovies.size() ; i++)
			{
				for(int j = 0 ; j < allMovies[i].size(); j++)
				{
					if(j==0)
					{cout << "--" << allMovies[i][j] << "--"; cout<<endl;}
					else
					{
						cout << allMovies[i][j];
						cout << endl;
					}
				}
			}
		}

	}
}
