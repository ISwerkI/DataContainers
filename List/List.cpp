#include <iostream>
using std::cout;
using std::cin;
using std::endl;


/////////////////////////////////////////////////////////////////////////////////////
///////////				Class declaration (Объявление класса)		////////////////

template<typename T>class Element;
template<typename T>class DoublyLinkedList;

template<typename T>class Element
{
	T Data;		
	Element<T>* pNext;	
	Element<T>* pPrev;	
	static int counter;
public:
	Element(T Data, Element<T>* pNext = nullptr);
	~Element();
	friend class DoublyLinkedList<T>;
};

template<typename T>class DoublyLinkedList
{
	Element<T>* Head;
	Element<T>* Tail;
	int size;
public:
	Element<T>* get_head()const;
	int get_size()const;
	Element<T>* get_tail()const;
};
/////////////////////////////////////////////////////////////////////////////////////
///////					Class declaration end (Конец объявление класса)		/////////

///------------------------------------------------------------------------------///

/////////////////////////////////////////////////////////////////////////////////////

///////////				Class definition (Определение класса)		////////////////

//---------------------------------------------------------------------------------//
//---------------				Element Metods				--------------------//

template <typename T>Element<T>::Element(T Data, Element<T>* pNext) :Data(Data), pNext(pNext)
{
	counter++;
#ifdef DEBUG
	cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

}
template <typename T>Element<T>::~Element()
{
	counter--;
#ifdef DEBUG
	cout << "EDestructor:\t" << this << endl;
#endif // DEBUG
}

//---------------				Element Metods	end			--------------------//
//---------------------------------------------------------------------------------//

//---------------------------------------------------------------------------------//
//---------------				DoublyLinkedList Metods				--------------------//

template <typename T>Element<T>* DoublyLinkedList<T>::get_head()const
{
	return Head;
}
template <typename T>int DoublyLinkedList<T>::get_size()const
{
	return size;
}
template <typename T>Element<T>* DoublyLinkedList<T>::get_tail()const
{
	return Tail;
}

//---------------				DoublyLinkedList Metods	end			--------------------//
//---------------------------------------------------------------------------------//

///////////				Class definition end(Конец определения класса)		///////

/////////////////////////////////////////////////////////////////////////////////////
void main()
{
	setlocale(LC_ALL, " ");

}

