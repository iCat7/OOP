#ifndef	RHOMB_H
#define RHOMB_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"
using namespace std;

class Rhomb : public Figure {
public:
	Rhomb(istream &is);
	void Print() override;
	virtual ~Rhomb();
private:
	size_t side_d1;
	size_t side_d2;
};

#endif /* RHOMB_H */