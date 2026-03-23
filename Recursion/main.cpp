#include <iostream>
using namespace std;

void Elevator(int floor);
int Factorial(int value, int factorial);
int Factorial(int value);
double Power(double a, int n);

void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello World!";
	int n;
	int a;
	cout << "Введите значение: "; cin >> a; cin >> n;
	cout << Power(a,n) << endl;
	//cout<<Factorial(n)<<endl;
	//Elevator(n);
	//main();
}

void Elevator(int floor)
{
	if (floor == 0)
	{
		cout << "Вы в подвале" << endl;
		return;
	}
	cout << "Вы на " << floor << " этаже" << endl;
	Elevator(floor-1);
	cout << "Вы на " << floor << " этаже" << endl;
}

int Factorial(int value,int factorial)
{
	if (value == 0)
	{
		return factorial;
	}
	factorial *= value;
	Factorial(value-1,factorial);
}

int Factorial(int value)
{
	/*if (value == 0)return 1;
	else return value*Factorial(value - 1);*/
	return value==0 ? 1:value * Factorial(value - 1);
}

double Power(double a, int n)
{
	if (n == 0)return 1;
	else return a * Power(a, n - 1);
}

