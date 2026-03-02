#include <iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n-------------------------------------------------"



class List
{
	class Element
	{
		int Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr) :
			Data(Data), pNext(pNext), pPrev(pPrev)
		{
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		friend class List;
		friend class Iterator;
	}
	*Head, * Tail;	//Ёкземпл€ры класса можно объ€вл€ть непосредственно после описани€ класса
	//¬ одном выражении можно объ€вить несколько переменных одного типа, один раз указав тип и перечислив имена объ€вл€емых переменных через зап€тую.
	size_t size;//size_t - typedef на "unsigned int".
public:
	class Iterator
	{
		List::Element* Temp;
	public:
		Iterator(List::Element* Temp = nullptr) :Temp(Temp)
		{
			cout << "ItConstructor:\t" << this << endl;
		}
		~Iterator()
		{
			cout << "ItDestructor:\t" << this << endl;
		}
		Iterator& operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}
		bool operator==(const Iterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const Iterator& other)const
		{
			return this->Temp != other.Temp;
		}
		int operator*()
		{
			return Temp->Data;
		}
		Iterator& operator--()
		{
			Temp = Temp->pPrev;
			return *this;
		}
		friend class List::Element;
	};
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	List(const std::initializer_list<int>& il) :List()
	{
		for (int const* it = il.begin(); it != il.end(); ++it)
			push_back(*it);
	}
	~List()
	{
		while (Head)pop_back();
		cout << "LDestructor:\t" << this << endl;
	}

	Iterator begin()
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}

	//					Adding elements
	void push_front(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
			Head = Tail = new Element(Data);
		else
			Head = Head->pPrev = new Element(Data, Head);
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
			Head = Tail = new Element(Data);
		else
			Tail = Tail->pNext = new Element(Data, nullptr, Tail);
		size++;
	}
	//				Renoving elements:
	void pop_front()
	{
		if (Head == nullptr && Tail == nullptr)return;
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
		}
		else
		{
			Head = Head->pNext;
			delete Head -> pPrev;
			Head->pPrev = nullptr;
		}
		size--;
	}

	void pop_back()
	{
		if (Head == nullptr && Tail == nullptr)return;
		if (Head == Tail)
		{
			delete Tail;
			Head = Tail = nullptr;
		}
		else
		{
			Tail = Tail->pPrev;
			delete Tail->pNext;
			Tail->pNext = nullptr;
		}
		size--;
	}
	void insert(int Data, int index)
	{
		if (index >= size)return;
		if (index == size - 1)return push_back(Data);
		if (index == 0)return push_front(Data);
		Element* Temp;
		if (index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (int i = 0; i < size - index - 1; i++)Temp = Temp->pPrev;
		}
		Temp->pPrev->pNext = Temp->pNext->pPrev =
			new Element(Data, Temp->pNext, Temp->pPrev);
		size++;
	}
	void erase(int index)
	{
		if (index >= size)return;
		if (index == size - 1)return pop_back();
		if (index == 0)return pop_front();
		//1) ƒоходим до нужного элемента:
		Element* Temp;
		if (index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (int i = 0; i < size - index - 1; i++)Temp = Temp->pPrev;
		}
		//2) »сключаем элемент из списка:
		Temp->pPrev->pNext = Temp->pNext;
		Temp->pNext->pPrev = Temp->pPrev;
		//3) ”дал€ем элемент из пам€ти:
		delete Temp;

		//4)Decrement
		size--;
	}



	//				Metods:
	void print()const
	{
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "Tail:\t" << Tail << endl;
		cout << " оличество элементов в списке: " << size << endl;
	}
	void reverse_print()const
	{
		cout << "Tail:\t" << Tail << endl;
		for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "Head:\t" << Head << endl;

	}
	friend class Iterator;
};





//#define BASE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout << "¬ведите размер списка: "; cin >> n;
	List list1;
	for (int i = 0; i < n; i++)
	{
		list1.push_back(rand() % 100);
	}
	list1.print();
	//list1.reverse_print();

	int index;
	int value;
	//cout << "¬ведите индекс доб элемента:\t"; cin >> index;
	//cout << "¬ведите значение доб элемента:\t"; cin >> value;
	cout << "¬ведите индекс удал€емого элемента:\t"; cin >> index;
	list1.erase(index);
	list1.print();
#endif // BASE_CHECK

	List list = { 3, 5, 8, 13, 21 };
	for (int i : list)cout << i << tab; cout << endl;


}