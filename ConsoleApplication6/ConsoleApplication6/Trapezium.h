#ifndef	TRAPEZIUM_H
#define TRAPEZIUM_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"
using namespace std;

class Trapezium : public Figure {
public:
	Trapezium(istream &is);
	void Print() override;
	virtual ~Trapezium();
private:
	size_t side_a;
	size_t side_b;
	size_t side_c;
	size_t side_d;
};

#endif /* TRAPEZIUM_H */