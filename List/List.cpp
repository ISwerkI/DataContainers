#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Element
{
	int Data;		
	Element* pNext;	
	static int counter;
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		counter++;
#ifdef DEBUG
		cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Element()
	{
		counter--;
#ifdef DEBUG
		cout << "EDestructor:\t" << this << endl;
#endif // DEBUG
	}
	friend class DoublyLinkedList;
};

class DoublyLinkedList
{
	Element* Head;
	Element* Tail;
	int size;
public:
	Element* get_head()const
	{
		return Head;
	}
	int get_size()const
	{
		return size;
	}
	Element* get_tail()const
	{
		return Tail;
	}
};

void main()
{
	setlocale(LC_ALL, " ");

}

