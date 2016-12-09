#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"
using namespace std;

class Rectangle : public Figure {
public:
	Rectangle(istream &is);
	void Print() override;
	virtual ~Rectangle();
private:
	size_t side_a;
	size_t side_b;
};

#endif /* RECTANGLE_H */