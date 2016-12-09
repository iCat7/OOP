#ifndef STACK_H
#define STACK_H

#include "figure.h"
#include "StackItem.h"
#include "Iterator.h"
#include <memory>
using namespace std;

template <class Rec> class Stack
{
public:
	Stack();
	void push(shared_ptr<Rec> &&item);
	bool empty();
	shared_ptr<Rec> pop();
	Iterator<StackItem<Rec>, Rec> begin();
	Iterator<StackItem<Rec>, Rec> end();
	template <class A> friend ostream& operator<<(ostream& os, const Stack<A>& stack);
	virtual ~Stack();
private:
	shared_ptr<StackItem<Rec>> head;
};

#endif /* STACK_H */