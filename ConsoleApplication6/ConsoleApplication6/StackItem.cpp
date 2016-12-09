#include "StackItem.h"
#include "figure.h"
#include <iostream>
template class StackItem<Figure>;
template ostream& operator<<(ostream& os, const StackItem<Figure>& obj);

template <class Rec> StackItem<Rec>::StackItem(const shared_ptr<Rec>& item)
{
	this->item = item;
	this->next = nullptr;
}

template <class Rec> AllocationBlock StackItem<Rec>::stackitem_allocator(sizeof(StackItem<Rec>), 100);

template <class Rec> shared_ptr<StackItem<Rec>> StackItem<Rec>::SetNext(shared_ptr<StackItem<Rec>> &next) {
	shared_ptr<StackItem<Rec>> old = this->next;
	this->next = next;
	return old;
}

template <class Rec> shared_ptr<Rec> StackItem<Rec>::GetFigure() const {
	return this->item;
}

template <class Rec> shared_ptr<StackItem<Rec>> StackItem<Rec>::GetNext() {
	return this->next;
}

template <class Rec> StackItem<Rec>::~StackItem() {
}

template <class A> ostream& operator<<(ostream& os, const StackItem<A>& obj) {
	shared_ptr<Figure> f = obj.item;
	f->Print();
	return os;
}

template <class Rec> void * StackItem<Rec>::operator new (size_t size) {
	return stackitem_allocator.allocate();
}

template <class Rec> void StackItem<Rec>::operator delete(void *p) {
	stackitem_allocator.deallocate(p);
}