#include <iostream>
using namespace std;

void Elevator(int floor);
int Factorial(int value, int factorial);
int Factorial(int value);
double Power(double a, int n);
void Fibonacci(int a);
void Fibonacci2(int n, int b, int a);

void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello World!";
	int n;
	int a;
	cout << "Введите значение: "; cin >> a;
	Fibonacci(a);
	//cout << Power(a,n) << endl;
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
	else if(n > 0) return a * Power(a, n - 1);
	else if(n < 0) return 1 / a * Power(a, n + 1);
}

void Fibonacci2(int n, int b, int a)
{
	if (a < n+b) return;
	cout << n + b << endl;
	Fibonacci2(b, n + b, a - 1);
}

void Fibonacci(int a)
{
	Fibonacci2(0, 1, a);
}



