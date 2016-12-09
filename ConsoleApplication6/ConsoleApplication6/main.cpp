#include <cstdlib>
#include <iostream>
#include <memory>

#include "Rectangle.h"
#include "Trapezium.h"
#include "Rhomb.h"
#include "figure.h"

#include "StackItem.h"
#include "Stack.h"

#include "AllocationBlock.h"
using namespace std;

void TestStack()
{
	Stack<Figure> stack;

	stack.push(shared_ptr<Figure>(new Rectangle(cin)));
	stack.push(shared_ptr<Figure>(new Trapezium(cin)));
	stack.push(shared_ptr<Figure>(new Rhomb(cin)));

	for (auto i : stack)	i->Print();

	while (!stack.empty())	cout << stack.pop() << endl;
}

void TestAllocationBlock() 
{
	AllocationBlock allocator(sizeof(int), 10);

	int *a1 = nullptr;
	int *a2 = nullptr;
	int *a3 = nullptr;
	int *a4 = nullptr;
	int *a5 = nullptr;

	a1 = (int*)allocator.allocate(); *a1 = 1; cout << "a1 pointer value:" << *a1 << endl;
	a2 = (int*)allocator.allocate(); *a2 = 2; cout << "a2 pointer value:" << *a2 << endl;
	a3 = (int*)allocator.allocate(); *a3 = 3; cout << "a3 pointer value:" << *a3 << endl;

	allocator.deallocate(a1);
	allocator.deallocate(a3);

	a4 = (int*)allocator.allocate(); *a4 = 4; cout << "a4 pointer value:" << *a4 << endl;
	a5 = (int*)allocator.allocate(); *a5 = 5; cout << "a5 pointer value:" << *a5 << endl;

	cout << "a1 pointer value:" << *a1 << endl;
	cout << "a2 pointer value:" << *a2 << endl;
	cout << "a3 pointer value:" << *a3 << endl;

	allocator.deallocate(a2);
	allocator.deallocate(a4);
	allocator.deallocate(a5);
}

// templates stack on shared pointer with iterator and allocator on array

int main()
{
	TestAllocationBlock();
	TestStack();

	system("pause");
	return 0;
}