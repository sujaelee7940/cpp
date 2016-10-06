#include <iostream>
#include <vector>
using namespace std;
class Movie {


public:
	Movie(int sYear, string sTitle, vector<string> sActors)
: year(sYear), title(sTitle), actors(sActors)
{}
	Movie() = default;

	int getYear(){
		return year;
	}

	string getName(){
		return title;
	}

	string getMainActor(){
		return actors[0];
	}
	string getActor(int index){
		return actors[index-1];
	}


private:
	int year = 1900;
	string title = "Unknown";
	vector<string> actors;

};
int main(void) {
Movie unknown;
cout << unknown.getYear() << endl; cout << unknown.getName() << endl;
// 1900
// Unknown
string tactors[] = {"Uma Thurman", "Lucy Liu", "David Carradine"};
vector<string> actors(tactors,tactors + sizeof(tactors) / sizeof(tactors[0]));
Movie killbill(2003, "Kill Bill", actors);
cout << killbill.getYear() << endl; // 2003
cout << killbill.getName() << endl; // Kill Bill
cout << killbill.getMainActor() << endl; // Uma Thurman
cout << killbill.getActor(3) << endl; // David Carradine
}
