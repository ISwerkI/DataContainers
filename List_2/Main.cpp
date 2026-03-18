#include <iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n-------------------------------------------------"

#define data_type int

////////////////////////////////////////////////////////////////////////////////////////////////////
////////					Class declaration	(Объявления класса)							////////

template<typename T>
class List
{
	class Element
	{
		T Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr);
		~Element();
		friend class List;
		friend class Iterator;
	}
	*Head, * Tail;	//Экземпляры класса можно объявлять непосредственно после описания класса
	//В одном выражении можно объявить несколько переменных одного типа, один раз указав тип и перечислив имена объявляемых переменных через запятую.
	size_t size;//size_t - typedef на "unsigned int".
	class ConstBaseIterator
	{
	protected:
		Element* Temp;
	public:
		ConstBaseIterator(Element* Temp = nullptr);
		~ConstBaseIterator();
		bool operator==(const ConstBaseIterator& other)const;
		bool operator!=(const ConstBaseIterator& other)const;
		T operator*()const;
	};
public:
	class ConstIterator: public ConstBaseIterator
	{
	public:
		ConstIterator(List::Element* Temp = nullptr);
		~ConstIterator();
		ConstIterator& operator++();
		ConstIterator operator++(int);
		ConstIterator& operator--();
		ConstIterator operator--(int);
		friend class List::Element;
	};
	class ConstReverseIterator:public ConstBaseIterator
	{
	public:
		ConstReverseIterator(Element* Temp = nullptr);
		~ConstReverseIterator();
		ConstReverseIterator& operator++();
		ConstReverseIterator operator++(int);
		ConstReverseIterator& operator--();
		ConstReverseIterator operator--(int);

	};
	class Iterator :public ConstIterator
	{
	public:
		Iterator(Element* Temp = nullptr) :ConstIterator(Temp) {}
		~Iterator() {}
		T& operator*()
		{
			return ConstBaseIterator::Temp->Data;
		}
	};
	class ReverseIterator :public ConstReverseIterator
	{
	public:
		ReverseIterator(Element* Temp) :ConstReverseIterator(Temp) {}
		~ReverseIterator() {}
		T& operator*()
		{
			return ConstBaseIterator::Temp->Data;
		}
	};

	ConstIterator cbegin()const;
	ConstIterator cend()const;
	ConstReverseIterator crbegin()const;
	ConstReverseIterator crend()const;
	Iterator begin();
	Iterator end();
	ReverseIterator rbegin();
	ReverseIterator rend();

	List();
	List(const std::initializer_list<T>& il);
	~List();

	//					Adding elements
	void push_front(T Data);
	void push_back(T Data);
	void insert(T Data, int index);
	//				Renoving elements:
	void pop_front();

	void pop_back();
	
	void erase(int index);



	//				Metods:
	void print()const;
	void reverse_print()const;
	friend class Iterator;
};

////////				Class declaration end	(Конец объявления класса)					////////
////////////////////////////////////////////////////////////////////////////////////////////////////

///----------------------------------------------------------------------------------------------///

////////////////////////////////////////////////////////////////////////////////////////////////////
////////					Class definition	(Определение класса)						////////

//---------------------------------------------------------------------------------//
//---------------				Element Metods				--------------------//

template<typename T>List<T>::Element::Element(T Data, Element* pNext, Element* pPrev) :Data(Data), pNext(pNext), pPrev(pPrev)
{
	//cout << "EConstructor:\t" << this << endl;
}
template<typename T>List<T>::Element::~Element()
{
	//cout << "EDestructor:\t" << this << endl;
}

//---------------				Element Metods	end			--------------------//
//-----------------------------------------------------------------------------//



//---------------------------------------------------------------------------------//
//---------------				ConstBaseIterator Metods				----------//

template<typename T>List<T>::ConstBaseIterator::ConstBaseIterator(Element* Temp) :Temp(Temp) {}
template<typename T>List<T>::ConstBaseIterator::~ConstBaseIterator() {}
template<typename T>bool List<T>::ConstBaseIterator::operator==(const ConstBaseIterator& other)const
{
	return this->Temp == other.Temp;
}
template<typename T>bool List<T>::ConstBaseIterator::operator!=(const ConstBaseIterator& other)const
{
	return this->Temp != other.Temp;
}
template<typename T>T List<T>::ConstBaseIterator::operator*()const
{
	return Temp->Data;
}

//---------------				ConstBaseIterator Metods	end			------------//
//---------------------------------------------------------------------------------//



//---------------------------------------------------------------------------------//
//---------------				ConstIterator Metods				----------//

template<typename T>List<T>::ConstIterator::ConstIterator(List::Element* Temp) :ConstBaseIterator(Temp) {}
template<typename T>List<T>::ConstIterator::~ConstIterator()
{
	cout << "ItDestructor:\t" << this << endl;
}
template<typename T>List<T>::ConstIterator& List<T>::ConstIterator::operator++()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return *this;
}
template<typename T>List<T>::ConstIterator List<T>::ConstIterator::operator++(int)
{
	ConstIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return old;
}
template<typename T>List<T>::ConstIterator& List<T>::ConstIterator::operator--()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return *this;
}
template<typename T>List<T>::ConstIterator List<T>::ConstIterator::operator--(int)
{
	ConstIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return old;
}

//---------------				ConstIterator Metods	end			------------//
//---------------------------------------------------------------------------------//



//---------------------------------------------------------------------------------//
//---------------				ConstReverseIterator Metods				----------//

template<typename T>List<T>::ConstReverseIterator::ConstReverseIterator(Element* Temp) :ConstBaseIterator(Temp) {}
template<typename T>List<T>::ConstReverseIterator::~ConstReverseIterator() {}
template<typename T>List<T>::ConstReverseIterator& List<T>::ConstReverseIterator::operator++()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return *this;
}
template<typename T>List<T>::ConstReverseIterator List<T>::ConstReverseIterator::operator++(int)
{
	ConstReverseIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return old;
}
template<typename T>List<T>::ConstReverseIterator& List<T>::ConstReverseIterator::operator--()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return *this;
}
template<typename T>List<T>::ConstReverseIterator List<T>::ConstReverseIterator::operator--(int)
{
	ConstReverseIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return old;
}

//---------------				ConstReverseIterator	end			----------------//
//---------------------------------------------------------------------------------//





//---------------------------------------------------------------------------------//
//---------------				List Metods				--------------------//
template<typename T>typename List<T>::ConstIterator List<T>::cbegin()const
{
	return Head;
}
template<typename T>typename List<T>::ConstIterator List<T>::cend()const
{
	return nullptr;
}
template<typename T>typename List<T>::ConstReverseIterator List<T>::crbegin()const
{
	return Tail;
}
template<typename T>typename List<T>::ConstReverseIterator List<T>::crend()const
{
	return nullptr;
}
template<typename T>typename List<T>::Iterator List<T>::begin()
{
	return Head;
}
template<typename T>typename List<T>::Iterator List<T>::end()
{
	return nullptr;
}
template<typename T>typename List<T>::ReverseIterator List<T>::rbegin()
{
	return Tail;
}
template<typename T>typename List<T>::ReverseIterator List<T>::rend()
{
	return nullptr;
}

template<typename T>List<T>::List()
{
	Head = Tail = nullptr;
	size = 0;
	cout << "LConstructor:\t" << this << endl;
}
template<typename T>List<T>::List(const std::initializer_list<T>& il) :List()
{
	for (T const* it = il.begin(); it != il.end(); ++it)
		push_back(*it);
}
template<typename T>List<T>::~List()
{
	while (Head)pop_back();
	cout << "LDestructor:\t" << this << endl;
}

//					Adding elements
template<typename T>void List<T>::push_front(T Data)
{
	if (Head == nullptr && Tail == nullptr)
		Head = Tail = new Element(Data);
	else
		Head = Head->pPrev = new Element(Data, Head);
	size++;
}
template<typename T>void List<T>::push_back(T Data)
{
	if (Head == nullptr && Tail == nullptr)
		Head = Tail = new Element(Data);
	else
		Tail = Tail->pNext = new Element(Data, nullptr, Tail);
	size++;
}
template<typename T>void List<T>::insert(T Data, int index)
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
//				Renoving elements:
template<typename T>void List<T>::pop_front()
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
		delete Head->pPrev;
		Head->pPrev = nullptr;
	}
	size--;
}

template<typename T>void List<T>::pop_back()
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

template<typename T>void List<T>::erase(int index)
{
	if (index >= size)return;
	if (index == size - 1)return pop_back();
	if (index == 0)return pop_front();
	//1) Доходим до нужного элемента:
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
	//2) Исключаем элемент из списка:
	Temp->pPrev->pNext = Temp->pNext;
	Temp->pNext->pPrev = Temp->pPrev;
	//3) Удаляем элемент из памяти:
	delete Temp;

	//4)Decrement
	size--;
}



//				Metods:
template<typename T>void List<T>::print()const
{
	for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	cout << "Tail:\t" << Tail << endl;
	cout << "Количество элементов в списке: " << size << endl;
}
template<typename T>void List<T>::reverse_print()const
{
	cout << "Tail:\t" << Tail << endl;
	for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
		cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	cout << "Head:\t" << Head << endl;

}
//---------------				List Metods	end			--------------------//
//---------------------------------------------------------------------------------//

////////				Class definition end	(Конец определения класса)					////////
////////////////////////////////////////////////////////////////////////////////////////////////////

//#define BASE_CHECK
//#define ITERATORS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	List list1;
	for (int i = 0; i < n; i++)
	{
		list1.push_back(rand() % 100);
	}
	list1.print();
	//list1.reverse_print();

	int index;
	int value;
	//cout << "Введите индекс доб элемента:\t"; cin >> index;
	//cout << "Введите значение доб элемента:\t"; cin >> value;
	cout << "Введите индекс удаляемого элемента:\t"; cin >> index;
	list1.erase(index);
	list1.print();
#endif // BASE_CHECK

#ifdef  ITERATORS_CHECK



	List<data_type> list = { 1,2,4};
	for (data_type i : list)cout << i << tab; cout << endl;

	for (List<data_type>::Iterator it = list.begin(); it != list.end(); it++)
	{
		cout << *it << tab;
	}

	for (List<data_type>::ConstReverseIterator it = list.rbegin(); it != list.rend(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
#endif //  ITERATORS_CHECKndl;

	List<int> i_list = { 3,5,8,13,21 };
	for (int i : i_list)cout << i << tab; cout << endl;
	for (List<int>::ReverseIterator it = i_list.rbegin(); it != i_list.rend(); ++it)
		cout << *it << tab;
	cout << endl;

	List<double> d_list = {2.7,3.14,5.8,9.11};
	for (double i : d_list)cout << i << tab; cout << endl;
	for (List<double>::ReverseIterator it = d_list.rbegin(); it != d_list.rend(); ++it)
		cout << *it << tab;
	cout << endl;

	List<char> c_list = { 's','w','e','r','k' };
	for (char i : c_list)cout << i << tab; cout << endl;
	for (List<char>::ReverseIterator it = c_list.rbegin(); it != c_list.rend(); ++it)
		cout << *it << tab;
	cout << endl;

	List<std::string> s_list = { "Hello","World","!" };
	for (std::string i : s_list)cout << i << tab; cout << endl;
	for (List<std::string>::ReverseIterator it = s_list.rbegin(); it != s_list.rend(); ++it)
		cout << *it << tab;
	cout << endl;
}
