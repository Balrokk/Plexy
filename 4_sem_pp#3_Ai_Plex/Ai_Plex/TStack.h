#pragma once


template <class T>
class TStack
{
private:
	T *mem;
	unsigned int size_mem;
	int top;
	void Repack()
	{
		T *temp = mem;
		mem = new T[size_mem + 10];
		for (int i = 0; i < size_mem; i++)
			mem[i] = temp[i];
		size_mem += 10;
		delete temp;
	}
public:

	TStack(unsigned int _size_mem = 10)
	{
		size_mem = _size_mem;
		top = -1;
		mem = new T[size_mem];
		for (unsigned int i = 0; i < size_mem; i++)
			mem[i] = T();
	}

	~TStack()
	{
		delete[] mem;
	}

	bool isEmpty()
	{
		if (top == -1)
			return true;
		else
			return false;
	}

	bool isFull()
	{
		return (top == size_mem - 1);
	}

	void Put(T temp)
	{
		if (isFull())
			Repack();
		mem[++top] = temp;
	}

	T Get()
	{
		if (!(isEmpty()))
			return mem[top--];
	}

	T Show()
	{
		if (!(isEmpty()))
			return mem[top];
	}
};
