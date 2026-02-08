#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimeter "\n------------------------------------------------------\n"

class Element
{
	int Data;		//значение элемента
	Element* pNext;	//следующий метод
	static int counter;
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		counter++;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		counter--;
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};
int Element::counter = 0;
class ForwardList
{
	Element* Head; // Голова списка - является точкой входа в список
	int size;
public:
	ForwardList()
	{
		//Конструктор по умолчанию создает пустой список
		Head = nullptr;
		// Когда список пуст, его голова указывает на 0.
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	//			Ading elements
	void push_front(int Data)
	{
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;

		size++;
	}
	
	void push_back(int Data)
	{
		Element* New = new Element(Data);
		Element* Temp = Head;
		while (Temp->pNext)Temp = Temp->pNext;
		Temp->pNext = New;
		New->pNext = nullptr;
		size++;
	}
	//			Removing elements
	void pop_front()
	{
		Element* Erased = Head;

		Head = Head->pNext;

		delete Erased;

		size--;
	}

	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext)Temp = Temp->pNext;
		delete Temp->pNext;
		Temp->pNext = nullptr;

		size--;
	}

	void insert(int Data, int index)
	{
		if (index == 0)return push_front(Data);
		Element* New = new Element(Data);

		Element* Temp = Head;
		for (int i = 0; i < index-1; i++)
		{
			if (Temp->pNext == nullptr)break;
			Temp = Temp->pNext;
		}
		New->pNext = Temp->pNext;
		Temp->pNext = New;

		size++;
	}

	void erase(int Data, int index)
	{
		if (index == 0)return pop_front();
		Element* buffer;
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)Temp = Temp->pNext;
		buffer = Temp->pNext->pNext;
		delete Temp->pNext;
		Temp->pNext = buffer;
		size--;

	}
	//			Metods
	void print()const
	{
		Element* Temp = Head;	//Temp - итератор
		//Итератор - это указатель, с помощью которого можно перемещаться по элементам структуры данных
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;
		}
		cout << "Количество элементов: " <<size<< endl;
		cout << "Общее количество элементов: " <<Element::counter<< endl;
	}
};

#define BASE_CHECK
//#define SIZE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	cout << "Hello ForwardList!" << endl;

	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	//list.print();
	//list.pop_front();
	//list.print();
	//list.pop_back();
	int value = 3333;
	int index = 4;
	list.print();
	list.erase(value,index);
	list.print();
#endif // BASE_CHECK

#ifdef SIZE_CHECK
	ForwardList list1;
	list1.push_front(3);
	list1.push_front(5);
	list1.push_front(8);
	list1.push_front(13);
	list1.push_front(21);

	ForwardList list2;
	list2.push_front(34);
	list2.push_front(55);
	list2.push_front(489);

	list1.print();
	list2.print();
#endif // SIZE_CHECK


}