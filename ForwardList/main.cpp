#include "ForwardList.h"
#include "ForwardList.cpp"

//#define BASE_CHECK
//#define SIZE_CHECK
//#define HOME_WORK_1
//#define COPY_SEMANTIC_CHECK
//#define PERFORMANCE_CHECK
//#define MOVE_SEMANTIC_CHECK
//#define RANGE_BASED_FOR_ARRAY
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

#ifdef COPY_SEMANTIC_CHECK
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
	list3 += list1; //copyAssinment
	list3.print();
#endif // COPY_SEMANTIC_CHECK

#ifdef PERFORMANCE_CHECK
	int n;
	cout << "Введите размер списка:"; cin >> n;
	ForwardList list1;
	clock_t start = clock();
	for (int i = 0; i < n; i++)
	{
		list1.push_front(rand() % 100);
	}
	clock_t end = clock();
	//list1.print();
	cout << delimiter << endl;
	cout << "list1 заполнен за "<< double(end-start) / CLOCKS_PER_SEC << endl;
	cout << delimiter << endl;
	start = clock();
	ForwardList list2 = list1;
	end = clock();
	cout << delimiter << endl;
	cout << "list2 ready " << double(end - start) / CLOCKS_PER_SEC << endl;
	cout << delimiter << endl;
	//list2.print();
#endif // PERFORMANCE_CHECK

#ifdef MOVE_SEMANTIC_CHECK
	ForwardList list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.push_back(21);

	ForwardList list2;
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(89);

	ForwardList list3 = list1 + list2;

	list3.print();

	ForwardList list = { 3, 5, 8, 13, 21 };
	list.print();
#endif // MOVE_SEMANTIC_CHECK

#ifdef RANGE_BASED_FOR_ARRAY
	int arr[] = { 3, 5, 8, 13, 21 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;

	//Range-based for (for для контейнеров)
	for (int i : arr)
	{
		cout << i << tab;
	}
	cout << endl;
#endif // RANGE_BASED_FOR_ARRAY
	ForwardList<std::string> list = { "Hello World!"};
	ForwardList<std::string> list1 = { "saDASD!"};
	//list.print();
	for (std::string i : list)
	{
		cout << i << tab;
	}
	cout << endl;


}