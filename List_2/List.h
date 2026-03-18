#pragma once
#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;;

#define tab "\t"
#define delimiter "\n-------------------------------------------------"

#define data_type int

////////////////////////////////////////////////////////////////////////////////////////////////////
////////					Class declaration	(ќбъ€влени€ класса)							////////

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
	*Head, * Tail;	//Ёкземпл€ры класса можно объ€вл€ть непосредственно после описани€ класса
	//¬ одном выражении можно объ€вить несколько переменных одного типа, один раз указав тип и перечислив имена объ€вл€емых переменных через зап€тую.
	size_t size;//size_t - typedef на "unsigned int".
	class ConstBaseIterator
	{
	protected:
		Element* Temp;
	public:
		ConstBaseIterator(Element* Temp = nullptr) :Temp(Temp) {}
		~ConstBaseIterator() {}
		bool operator==(const ConstBaseIterator& other)const;
		bool operator!=(const ConstBaseIterator& other)const;
		T operator*()const;
	};
public:
	class ConstIterator : public ConstBaseIterator
	{
	public:
		ConstIterator(List::Element* Temp = nullptr) :ConstBaseIterator(Temp) {}
		~ConstIterator() {}
		ConstIterator& operator++();
		ConstIterator operator++(int);
		ConstIterator& operator--();
		ConstIterator operator--(int);
		friend class List::Element;
	};
	class ConstReverseIterator :public ConstBaseIterator
	{
	public:
		ConstReverseIterator(Element* Temp = nullptr) :ConstBaseIterator(Temp) {}
		~ConstReverseIterator() {}
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
		T& operator*();
	};
	class ReverseIterator :public ConstReverseIterator
	{
	public:
		ReverseIterator(Element* Temp) :ConstReverseIterator(Temp) {}
		~ReverseIterator() {}
		T& operator*();
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

////////				Class declaration end	( онец объ€влени€ класса)					////////
////////////////////////////////////////////////////////////////////////////////////////////////////
