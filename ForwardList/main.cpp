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
	int get_size()const
	{
		return size;
	}
	ForwardList()
	{
		//Конструктор по умолчанию создает пустой список
		Head = nullptr;
		// Когда список пуст, его голова указывает на 0.
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	explicit ForwardList(int size) :ForwardList()
	{
		while (size--)push_front(0);
		cout << "1argLConstructor:\t" << this << endl;
	}
	ForwardList(const ForwardList& other) :ForwardList()
	{
		//for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			//push_back(Temp->Data);
		*this = other;
		cout << "LCopyConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t" << this << endl;
	}
	//			Operators
	ForwardList& operator=(const ForwardList& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		return *this;
	}
	int& operator[](int index)
	{
		Element* Temp = Head;
		for (int j = 0; j < index; j++)Temp = Temp->pNext;
		return Temp->Data;
	}
	ForwardList& operator+(const ForwardList& other)
	{
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		return *this;
	}
	//			Ading elements
	void push_front(int Data)
	{
		//Element* New = new Element(Data);
		//New->pNext = Head;
		//Head = New;

		Head = new Element(Data, Head);

		size++;
	}
	
	void push_back(int Data)
	{
		if (Head == nullptr) return push_front(Data);
		//Element* New = new Element(Data);
		Element* Temp = Head;
		while (Temp->pNext)Temp = Temp->pNext;
		Temp->pNext = new Element(Data);
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
		//New->pNext = Temp->pNext;
		Temp->pNext = new Element(Data,Temp->pNext);

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
		/*Element* Temp = Head;	//Temp - итератор
		//Итератор - это указатель, с помощью которого можно перемещаться по элементам структуры данных
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;
		}*/
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "Количество элементов: " <<size<< endl;
		cout << "Общее количество элементов: " <<Element::counter<< endl;
	}
	
};

//#define BASE_CHECK
//#define SIZE_CHECK
//#define HOME_WORK_1

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
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	int value = 3333;
	int index = 4;
	//list.print();
	//list.pop_front();
	//list.print();
	//list.pop_back();
	//list.print();
	//list.erase(value,index);
	//list.insert(value, index);
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

#ifdef HOME_WORK_1
	ForwardList list(5);  //Implicit conversion from 'int' to 'ForwardList'
						// Неявное преобразование из 'int' to 'ForwardList'
	list.print();
	for (int i = 0; i < list.get_size(); i++)
	{
		list[i] = rand() % 100;
	}
	for (int i = 0; i < list.get_size(); i++)
	{
		cout << list[i] << tab;
	}
	cout << endl;
#endif // HOME_WORK_1

	ForwardList list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.push_back(21);
	list1.print();

	ForwardList list2;
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(489);

	//ForwardList list2 = list1;
	ForwardList list3(list2);
	list3.print();
	list3 = list1 + list2; //copyAssinment
	list3.print();
}