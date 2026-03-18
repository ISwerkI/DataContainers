#include "List.h"
#include "List.cpp"
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
