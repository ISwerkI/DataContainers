#include<iostream>
using namespace std;

//#define EXAMPLE_1

#ifdef EXAMPLE_1
void Hello()
{
	cout << "Hello" << endl;
}
#endif // DEBUG

#ifdef EXAMPLE_2
const char* Hello()
{
	return "Hello";
}
#endif // EXAMPLE_2



void main()
{
	setlocale(LC_ALL, "");
	cout << "Function pointers" << endl;
	//cout << Hello();
#ifdef EXAMPLE_1
	void (*pHello)() = &Hello;
	cout << Hello << endl;
	cout << pHello << endl;
	(*pHello)();
#endif // DEBUG

#ifdef EXAMPLE_2
	cout << Hello() << endl;
	const char* (*pHello)() = Hello;
	cout << Hello << endl;
	cout << pHello << endl;
	cout << (*pHello)() << endl;
#endif // EXAMPLE_2

}