#include "Rhomb.h"
#include <iostream>
#include <cmath>
using namespace std;

Rhomb::Rhomb(istream &is) {
	cout << "Create Rhomb" << endl;
	cout << "d1 = ";
	is >> side_d1;
	cout << "d2 = ";
	is >> side_d2;
}

void Rhomb::Print() {
	cout << "Rhomb" << endl
		<< "d1 = " << side_d1 << endl
		<< "d2 = " << side_d2 << endl;
}

Rhomb::~Rhomb() {
	cout << "Rhomb deleted" << endl;
}
