#ifndef ITERATOR_H
#define ITERATOR_H
#include <memory>
#include <iostream>
using namespace std;

template <class node, class Rec>
class Iterator
{
public:
	Iterator(shared_ptr<node> n) { //текущий элемент
		node_ptr = n;
	}

	shared_ptr<Rec> operator * () { //возвращает значение 
		return node_ptr->GetFigure();
	}

	shared_ptr<Rec> operator -> () { //возвращает фигуру
		return node_ptr->GetFigure();
	}

	void operator ++ () { //переход к следующему элементу
		node_ptr = node_ptr->GetNext();
	}

	Iterator operator ++ (int) {
		Iterator iter(*this);
		++(*this);
		return iter;
	}

	bool operator == (Iterator const& i) { //сравнение
		return node_ptr == i.node_ptr;
	}

	bool operator != (Iterator const& i) { //сравнение
		return !(*this == i);
	}

private:
	shared_ptr<node> node_ptr;
};

#endif /* ITERATOR_H */