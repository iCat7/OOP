#include "Stack.h"
#include "figure.h"
template class Stack<Figure>;
template ostream& operator<<(ostream& os, const Stack<Figure>& stack);

template <class Rec> Stack<Rec>::Stack() : head(nullptr) {
}

template <class Rec> ostream& operator<<(ostream& os, const Stack<Rec>& stack) {
	shared_ptr<StackItem<Rec>> item = stack.head;
	while (item != nullptr)
	{
		os << *item;
		item = item->GetNext();
	}
	return os;
}

template <class Rec> void Stack<Rec>::push(shared_ptr<Rec> &&item) {
	shared_ptr<StackItem<Rec>> other(new StackItem<Rec>(item));
	other->SetNext(head);
	head = other;
}

template <class Rec> bool Stack<Rec>::empty() {
	return head == nullptr;
}

template <class Rec> shared_ptr<Rec> Stack<Rec>::pop() {
	shared_ptr<Rec> result;
	if (head != nullptr)
	{
		result = head->GetFigure();
		head = head->GetNext();
	}
	return result;
}

template <class Rec> Iterator<StackItem<Rec>, Rec> Stack<Rec>::begin() {
	return Iterator<StackItem<Rec>, Rec>(head);
}

template <class Rec> Iterator<StackItem<Rec>, Rec> Stack<Rec>::end() {
	return Iterator<StackItem<Rec>, Rec>(nullptr);
}

template <class Rec> Stack<Rec>::~Stack()
{
}
