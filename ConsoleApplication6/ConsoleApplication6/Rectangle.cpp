#include "Rectangle.h"
#include <iostream>
#include <cmath>
using namespace std;

Rectangle::Rectangle(istream &is) {
	cout << "Create Rectangle" << endl;
	cout << "a = ";
	is >> side_a;
	cout << "b = ";
	is >> side_b;
}

void Rectangle::Print() {
	cout << "Rectangle" << endl
		<< "a = " << side_a << endl
		<< "b = " << side_b << endl;
}

Rectangle::~Rectangle() {
	cout << "Rectangle deleted" << endl;
}
