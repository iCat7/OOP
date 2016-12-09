#include "Trapezium.h"
#include <iostream>
#include <cmath>
using namespace std;

Trapezium::Trapezium(istream &is) {
	cout << "Create Trapezium" << endl;
	cout << "a = ";
	is >> side_a;
	cout << "b = ";
	is >> side_b;
	cout << "c = ";
	is >> side_c;
	cout << "d = ";
	is >> side_d;
}

void Trapezium::Print() {
	cout << "Trapezium" << endl
		<< "a = " << side_a << endl
		<< "b = " << side_b << endl
		<< "c = " << side_c << endl
		<< "d = " << side_d << endl;
}

Trapezium::~Trapezium() {
	cout << "Trapezium deleted" << endl;
}
