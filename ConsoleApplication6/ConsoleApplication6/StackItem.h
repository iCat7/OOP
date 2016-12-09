#ifndef STACKITEM_H
#define STACKITEM_H
#include "AllocationBlock.h"
#include <memory>
using namespace std;

template<class Rec> class StackItem
{
public:
	StackItem(const shared_ptr<Rec>&);
	template<class A> friend ostream& operator<<(ostream& os, const StackItem<A>& obj);

	shared_ptr<StackItem<Rec>> SetNext(shared_ptr<StackItem> &next);
	shared_ptr<StackItem<Rec>> GetNext();
	shared_ptr<Rec> GetFigure() const;
	void * operator new (size_t size);
	void operator delete(void *p);

	virtual ~StackItem();
private:
	shared_ptr<Rec> item;
	shared_ptr<StackItem<Rec>> next;

	static AllocationBlock stackitem_allocator;
};

#endif /* STACKITEM_H */