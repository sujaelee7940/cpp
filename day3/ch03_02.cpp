//============================================================================
// Name        : ch03_03.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	string ifile = "text.txt";
	string line, word, combined;

	ifstream ifs(ifile);
	ofstream ofs(ifile+".copy");

	if(ifs && ofs)
	{
		string line;
		while(getline(ifs,line)) {
			ofs << line << endl;
		}
	}
	ifs.close();
	ofs.close();

	vector<string> wordList;

	while(getline(cin,line)) {
		istringstream iss(line);
		while(iss >> word) {
			wordList.push_back(word);
		}
	}

	ostringstream oss;
	while(getline(cin,line)) {
		oss << line;
	}
	combined = oss. str();
}
