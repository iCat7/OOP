#ifndef ALLOCATIONBLOCK_H
#define ALLOCATIONBLOCK_H
#include <cstdlib>

class AllocationBlock
{
public:
	AllocationBlock(size_t size, size_t count); //конструктор аллокатора памяти, заполнение блоков памяти
	void *allocate(); //выделение памяти, уменьшение количества свободных блоков памяти
	void deallocate(void *pointer); //освобождение памяти, увеличение количества блоков памяти
	bool has_free_blocks(); //количество свободных блоков памяти

	virtual ~AllocationBlock();//деструктор аллокатора
private:
	size_t _size;
	size_t _count;

	char *_used_blocks;
	void **_free_blocks;

	size_t _free_count;
};

#endif /* ALLOCATIONBLOCK_H */