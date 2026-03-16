#include"ForwardList.h"
///------------------------------------------------------------------------------///

/////////////////////////////////////////////////////////////////////////////////////
///////////				Class definition (Определение класса)		////////////////



//---------------------------------------------------------------------------------//
//---------------				Element Metods				--------------------//

template <typename T>int Element<T>::counter = 0;

template<typename T>Element<T>::Element(T Data, Element<T>* pNext) :Data(Data), pNext(pNext)
{
	counter++;
#ifdef DEBUG
	cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T>Element<T>::~Element()
{
	counter--;
#ifdef DEBUG
	cout << "EDestructor:\t" << this << endl;
#endif // DEBUG
}

//---------------				Element Metods end				--------------------//
//---------------------------------------------------------------------------------//



//---------------------------------------------------------------------------------//
//---------------				Iterator Metods				--------------------//

template <typename T>Iterator<T>::Iterator(Element<T>* Temp) :Temp(Temp)
{
	cout << "ItConstructor:\t" << this << endl;
}
template <typename T>Iterator<T>::~Iterator()
{
	cout << "ItDestructor:\t" << this << endl;
}
template <typename T> Iterator<T>& Iterator<T>::operator++()
{
	Temp = Temp->pNext;
	return *this;
}
template <typename T>bool Iterator<T>::operator==(const Iterator<T>& other)const
{
	return this->Temp == other.Temp;
}
template <typename T> bool Iterator<T>::operator!=(const Iterator<T>& other)const
{
	return this->Temp != other.Temp;
}
template <typename T> T& Iterator<T>::operator*()
{
	return Temp->Data;
}

//---------------				Iterator Metods end			--------------------//
//---------------------------------------------------------------------------------//

//---------------------------------------------------------------------------------//
//---------------				ForwardList Metods				--------------------/
template <typename T>
Element<T>* ForwardList<T>::get_head()const
{
	return Head;
}
template <typename T>
int ForwardList<T>::get_size()const
{
	return size;
}
template <typename T>
Iterator<T> ForwardList<T>::begin()
{
	return Head;
}
template <typename T>
Iterator<T> ForwardList<T>::end()
{
	return nullptr;
}
template<typename T>ForwardList<T>::ForwardList()
{
	//Конструктор по умолчанию создает пустой список
	Head = nullptr;
	// Когда список пуст, его голова указывает на 0.
	size = 0;
	cout << "LConstructor:\t" << this << endl;
}
template<typename T>ForwardList<T>::ForwardList(int size) :ForwardList()
{
	while (size--)push_front(0);
	cout << "1argLConstructor:\t" << this << endl;
}
template <typename T>
ForwardList<T>::ForwardList(const std::initializer_list<T>& il) :ForwardList()
{
	cout << typeid(il.begin()).name() << endl;
	for (T const* it = il.begin(); it != il.end(); it++)
	{
		push_back(*it);
	}
}

template <typename T>
ForwardList<T>::ForwardList(const ForwardList<T>& other) :ForwardList()
{
	//for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
		//push_back(Temp->Data);
	*this = other;
	cout << "LCopyConstructor:\t" << this << endl;
}
template <typename T>
ForwardList<T>::ForwardList(ForwardList<T>&& other) : ForwardList()
{
	/*this->Head = other.Head;
	this->size = other.size;
	other.Head = nullptr;
	other.size = 0;*/
	*this = std::move(other);
	cout << "LMoveConstructor:\t" << this << endl;
}
template <typename T>
ForwardList<T>::~ForwardList()
{
	while (Head)pop_front();
	cout << "LDestructor:\t" << this << endl;
}

//-------------------			ForwardList Metods	end		------------------------/
//---------------------------------------------------------------------------------//

//			Operators
template <typename T>
ForwardList<T>& ForwardList<T>::operator=(const ForwardList<T>& other)
{
	if (this == &other)return *this;
	while (Head)pop_front();
	for (Element<T>* Temp = other.Head; Temp; Temp = Temp->pNext)
		push_front(Temp->Data);
	cout << "LCopyAssignment:\t" << this << endl;
	return *this;
}
template <typename T>
ForwardList<T>& ForwardList<T>::operator=(ForwardList<T>&& other)
{
	if (this == &other)return *this;
	while (Head)pop_front();
	this->Head = other.Head;
	this->size = other.size;
	other.Head = nullptr;
	other.size = 0;
	cout << "MoveAssignment:\t" << this << endl;
	return *this;

}
template <typename T>
T& ForwardList<T>::operator[](int index)
{
	Element<T>* Temp = Head;
	for (int j = 0; j < index; j++)Temp = Temp->pNext;
	return Temp->Data;
}
template <typename T>
ForwardList<T>& ForwardList<T>::operator+=(const ForwardList<T>& other)
{
	for (Element<T>* Temp = other.Head; Temp; Temp = Temp->pNext)
		push_back(Temp->Data);
	return *this;
}
//			Ading elements
template <typename T>
void ForwardList<T>::push_front(T Data)
{
	//Element* New = new Element(Data);
	//New->pNext = Head;
	//Head = New;

	Head = new Element<T>(Data, Head);

	size++;
}
template <typename T>
void ForwardList<T>::push_back(T Data)
{
	if (Head == nullptr) return push_front(Data);
	//Element* New = new Element(Data);
	Element<T>* Temp = Head;
	while (Temp->pNext)Temp = Temp->pNext;
	Temp->pNext = new Element<T>(Data);
	size++;
}
//			Removing elements
template <typename T>
void ForwardList<T>::pop_front()
{
	Element<T>* Erased = Head;

	Head = Head->pNext;

	delete Erased;

	size--;
}
template <typename T>
void ForwardList<T>::pop_back()
{
	Element<T>* Temp = Head;
	while (Temp->pNext->pNext)Temp = Temp->pNext;
	delete Temp->pNext;
	Temp->pNext = nullptr;

	size--;
}
template <typename T>
void ForwardList<T>::insert(T Data, int index)
{
	if (index == 0)return push_front(Data);
	Element<T>* New = new Element<T>(Data);

	Element<T>* Temp = Head;
	for (int i = 0; i < index - 1; i++)
	{
		if (Temp->pNext == nullptr)break;
		Temp = Temp->pNext;
	}
	//New->pNext = Temp->pNext;
	Temp->pNext = new Element<T>(Data, Temp->pNext);

	size++;
}
template <typename T>
void ForwardList<T>::erase(int Data, int index)
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
template <typename T>
void ForwardList<T>::reverse()
{
	ForwardList<T> reverse;
	while (Head)
	{
		reverse.push_front(Head->Data);
		pop_front();
	}
	this->Head = reverse.Head;
	reverse.Head = nullptr;
}
template <typename T>
void ForwardList<T>::print()const
{
	/*Element* Temp = Head;	//Temp - итератор
	//Итератор - это указатель, с помощью которого можно перемещаться по элементам структуры данных
	while (Temp)
	{
		cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		Temp = Temp->pNext;
	}*/
	for (Element<T>* Temp = Head; Temp; Temp = Temp->pNext)
		cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	cout << "Количество элементов: " << size << endl;
	cout << "Общее количество элементов: " << Element<T>::counter << endl;
}
template <typename T>
ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right)
{
	ForwardList<T> result = left;
	for (Element<T>* Temp = right.get_head(); Temp; Temp = Temp->pNext)
		result.push_back(Temp->Data);
	return result;
}

/////////////////////////////////////////////////////////////////////////////////////
///////////				Class definition end(Конец определения класса)		////////////////