//============================================================================
// Name        : ch03_01.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Market
{
public:
	Market(unsigned a) : apple(a) { }
	Market(unsigned a, unsigned b) : apple(a) , applePrice(b) { }
	Market &appleSold() {
		apple--;
		return *this;
	}
	Market() = default;

	Market &sales() {
		cout << apple << endl;
		return *this;
	}
	unsigned getPrice() const;
	unsigned getPrice(unsigned a) const;

private:
	unsigned apple = 0;
	unsigned applePrice = 39;
};

unsigned Market::getPrice() const {
	return applePrice * 1;
}

unsigned Market::getPrice(unsigned a) const {
	return a * applePrice * 1;
}

int main() {

	Market eMart(99);
	Market gs25;
	Market homePlus(107,35);

	cout << eMart.getPrice() << endl;
	cout << eMart.getPrice(12) << endl;
	homePlus.sales().appleSold();
	homePlus.sales();
}
