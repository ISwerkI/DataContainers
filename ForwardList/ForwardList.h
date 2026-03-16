#pragma once
#include <iostream>
#include<ctime>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n------------------------------------------------------\n"

/////////////////////////////////////////////////////////////////////////////////////
///////////				Class declaration (Объявление класса)		////////////////

template<typename T>class ForwardList;
template<typename T>class Iterator;
template<typename T>ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right);

template <typename T>
class Element
{
	T Data;		//значение элемента
	Element<T>* pNext;	//следующий метод
	static int counter;
public:
	Element(T Data, Element<T>* pNext = nullptr);
	~Element();
	friend class ForwardList<T>;
	friend class Iterator<T>;
	friend ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right);
};

template <typename T>class Iterator
{
	Element<T>* Temp;
public:
	Iterator(Element<T>* Temp = nullptr);
	~Iterator();
	Iterator& operator++();
	bool operator==(const Iterator<T>& other)const;
	bool operator!=(const Iterator<T>& other)const;
	T& operator*();
};

template <typename T>class ForwardList
{
	Element<T>* Head; // Голова списка - является точкой входа в список
	int size;
public:
	Element<T>* get_head()const;
	int get_size()const;
	Iterator<T> begin();
	Iterator<T> end();
	ForwardList();
	explicit ForwardList(int size);
	ForwardList(const std::initializer_list<T>& il);
	ForwardList(const ForwardList<T>& other);
	ForwardList(ForwardList<T>&& other);
	~ForwardList();
	//			Operators
	ForwardList<T>& operator=(const ForwardList<T>& other);
	ForwardList<T>& operator=(ForwardList<T>&& other);
	T& operator[](int index);
	ForwardList<T>& operator+=(const ForwardList<T>& other);
	//			Ading elements
	void push_front(T Data);
	void push_back(T Data);
	//			Removing elements
	void pop_front();
	void pop_back();

	void insert(T Data, int index);
	void erase(int Data, int index);
	//			Metods
	void reverse();
	void print()const;
};
/////////////////////////////////////////////////////////////////////////////////////
///////					Class declaration end (Конец объявление класса)		/////////