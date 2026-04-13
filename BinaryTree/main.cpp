#include <iostream>
#include<Windows.h>
#include<ctime>
using std::endl;
using std::cin;
using std::cout;

#define tab		"\t"
#define delimeter "\n------------------------------------------\n"

class Tree
{
protected:
	class Element
	{
	
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr)
			:Data(Data), pLeft(pLeft), pRight(pRight)
		{
#ifdef DEBUG
			cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

		}
		~Element()
		{
#ifdef DEBUG
			cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

		}
		friend class Tree;
		friend class UniqueTree;
	}*Root;
public:
	Element* getRoot()
	{
		return Root;
	}
	Tree() :Root(nullptr)
	{
		cout << "TConstructor:\t" << this << endl;
	}
	Tree(const std::initializer_list<int>& il) :Tree()
	{
		for (int const* it = il.begin(); it != il.end(); it++)
			insert(*it);
	}
	~Tree()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	void balance()
	{
		balance(Root);
	}
	void clear()
	{
		clear(Root);
	}
	void insert(int Data)
	{
		insert(Data, Root);
	}
	void erase(int Data)
	{
		erase(Data, Root);
	}
	int minValue()const
	{
		return minValue(Root);
	}
	int maxValue()const
	{
		return maxValue(Root);
	}
	int sum()const
	{
		return sum(Root);
	}
	int count()const
	{
		return count(Root);
	}
	double avg()const
	{
		return (double)sum(Root) / count(Root);
	}
	int depth()const
	{
		return depth(Root);
	}
	void print()const
	{
		print(Root);
		cout << endl;
	}
	void depth_print(int depth, int interval)const
	{
		depth_print(Root, depth, interval);
		cout << endl;
	}
	void tree_print()const
	{
		tree_print(0, depth() * 8);
	}
private:
	void balance(Element* Root)
	{
		if (Root == nullptr)return;
		//Функция abs() абсолютное значение - модкль числа.
		if (abs(count(Root->pLeft) - count(Root->pRight)) > 2)
		{
			if (count(Root->pLeft) > count(Root->pRight))
			{
				if (Root->pRight == nullptr)Root->pRight = new Element(Root->Data);
				else							insert(Root->Data, Root->pRight);
				Root->Data = maxValue(Root->pLeft);
				erase(maxValue(Root->pLeft), Root->pLeft);
			}
			else
			{
				if (Root->pLeft == nullptr)Root->pRight = new Element(Root->Data);
				else							insert(Root->Data, Root->pLeft);

				Root->Data = minValue(Root->pRight);
				erase(minValue(Root->pRight), Root->pRight);
			}
		}
		balance(Root->pLeft);
		balance(Root->pRight);
	}
	void clear(Element*& Root)
	{
		if (Root == nullptr)return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
		Root = nullptr;
	}
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
	void erase(int Data, Element*& Root)
	{
		if (Root == nullptr)return;
		if (Data == Root->Data)
		{
			if (Root->pLeft == Root->pRight) //Проверка на nullptr (проверка на листок)
			{
				delete Root;
				Root = nullptr;
			}
			else
			{
				if (count(Root->pLeft) > count(Root->pRight))
				{
					Root->Data = maxValue(Root->pLeft);
					erase(maxValue(Root->pLeft), Root->pLeft);
				}
				else
				{
					Root->Data = minValue(Root->pRight);
					erase(minValue(Root->pRight), Root->pRight);
				}
			}
		}
		if(Root)
		{
			if (Root->pLeft)erase(Data, Root->pLeft);
			if (Root->pRight)erase(Data, Root->pRight);
		}
	}
	int minValue(Element* Root)const
	{
		if (this->Root == nullptr)return 0;
		return Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
		/*if (Root->pLeft == nullptr)return Root->Data;
		else return minValue(Root->pLeft);*/
	}
	int maxValue(Element* Root)const
	{
		if (this->Root == nullptr)return 0;
		return Root->pRight == nullptr ? Root->Data : maxValue(Root->pRight);
		/*if (Root->pRight == nullptr) return Root->Data;
		else return maxValue(Root->pRight);*/
	}
	int sum(Element* Root)const
	{
		return Root == nullptr ? 0 : sum(Root->pLeft) + sum(Root->pRight) + Root->Data;
		/*if (Root == nullptr)return 0;
		else return sum(Root->pLeft) + sum(Root->pRight) + Root->Data;*/
	}
	int count(Element* Root)const
	{
		return Root == nullptr ? 0 : count(Root->pLeft) + count(Root->pRight) + 1;
	}
	int depth(Element* Root)const
	{
		if (Root == nullptr) return 0;
		int lDepth = depth(Root->pLeft) + 1;
		int rDepth = depth(Root->pRight) + 1;
		return lDepth > rDepth ? lDepth : rDepth;
	}

	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}
	void depth_print(Element* Root, int depth, int interval = 8)const
	{
		cout.width(interval);
		if (Root == nullptr)
		{
			cout << "";
			return;
		}
		if (depth == 0)
		{
			cout << Root->Data;
			cout.width(interval);
			cout << "";
			return;
		}
		depth_print(Root->pLeft, depth - 1, interval);
		depth_print(Root->pRight, depth - 1, interval);
	}
	/*void depth_print(Element* Root, int depth)const
	{
		if (Root == nullptr)return;
		if (depth == 0) cout << Root->Data << "\t\t";
		
		depth_print(Root->pLeft, depth - 1);
		depth_print(Root->pRight, depth - 1);
		return;
	}*/
	/*void tree_print(Element* Root, int depth, int i)const
	{
		if (Root == nullptr)return;
		if (i > depth)return;
		for (int j = i; j < depth; j++)cout << "\t";
		depth_print(i);
		cout << endl;
		tree_print(Root, depth, i + 1);
	}*/
	void tree_print(int depth, int interval = 8)const
	{
		if (depth == this->depth())return;
		//int interval = (this->depth() - depth) * 8 + 1;
		//cout.width(interval / 4);		cout << "";
		depth_print(depth, interval);
		cout << endl;
		cout << endl;
		cout << endl;
		tree_print(depth + 1, interval / 2);
	}
};

class UniqueTree:public Tree
{
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else if (Data > Root->Data)
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
public:
	void insert(int Data)
	{
		insert(Data, Root);
	}
};
template<typename T>
void measure(const char message[], T(Tree::*function)()const, const Tree& tree)
{
	clock_t start = clock();
	T result = (tree.*function)();
	clock_t end = clock();
	cout.width(48);
	cout << std::left;
	cout << message << result << "\t вычислено за " << double(end - start) / CLOCKS_PER_SEC << " секунд" << endl;
}

//#define BASE_CHECK
//#define ERASE_CHECK
//#define PERFORMANCE_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef BASE_CHECK



	//system("chcp 866");
	//SetConsoleOutputCP(866);
	int n;
	cout << "Введите размер дерева: ";cin >> n;
	Tree tree;
	for (int i = 0;i < n;i++)
	{
		tree.insert(rand() % 100);
	}
	tree.print();
	cout << endl;
	cout << "Минимальное значение в дереве: "; cout << tree.minValue()<<endl;
	cout << "Максимальное значение в дереве: "; cout << tree.maxValue()<<endl;
	cout << "Сумма элементов дерева: "<<tree.sum()<<endl;
	cout << "Количество элементов дерева: " << tree.count() << endl;
	cout << "Среднее-арифметическое элементов дерева: " <<tree.avg()<< endl;

	UniqueTree u_tree;
	for (int i = 0; i < n; i++)
	{
		u_tree.insert(rand() % 100);
	}
	u_tree.print();
	cout << endl;
	cout << "Минимальное значение в дереве: "<<				u_tree.minValue() << endl;
	cout << "Максимальное значение в дереве: "<<			u_tree.maxValue() << endl;
	cout << "Сумма элементов дерева: " <<					u_tree.sum() << endl;
	cout << "Количество элементов дерева: " <<				u_tree.count() << endl;
	cout << "Среднее-арифметическое элементов дерева: " <<	u_tree.avg() << endl;
#endif

#ifdef ERASE_CHECK
	Tree tree = { 50,25,75,16,32,64,85 };
	tree.print();
	//tree.clear();
	int value;
	cout << "Введите удаляемое значение: "; cin >> value;
	tree.erase(value);
	tree.print();
#endif // ERASE_CHECK

#ifdef PERFORMANCE_CHECK
	clock_t start;
	clock_t end;
	int n;
	//cout << "Введите размер дерева: "; cin >> n;
	start = clock();
	Tree tree =
	{
					50,

			25,				75,

		16,		32,		64,		85,91
	};
	/*for (int i = 0; i < n; i++)
	{
		tree.insert(rand()%1000);
	}*/
	end = clock();
	cout << "Дерево заполнено за " << double(end - start) / CLOCKS_PER_SEC << " секунд\n";
	//tree.print();
	measure("Минимальное значение в древе: ", &(Tree::minValue), tree);
	measure("Максимальное значение в древе: ", &(Tree::maxValue), tree);
	measure("Сумма элементов дерева: ", &(Tree::sum), tree);
	measure("Количество элементов дерева: ", &(Tree::count), tree);
	measure("Среднее-арифметическое элементов дерева: ", &(Tree::avg), tree);
	measure("Глубина дерева: ", &(Tree::depth), tree);
	//cout << "Введите глубину, которую желаете вывести: "; cin >> n;
	tree.tree_print();
	
	
	/*start = clock();
	cout << "Минимальное значение в дереве: "; cout << tree.minValue() << "\t";
	end = clock();
	cout << "Вычислино за " << double(end - start) / CLOCKS_PER_SEC << " секунд\n";

	
	cout << "Максимальное значение в дереве: "; cout << tree.maxValue() << "\t";
	end = clock();
	cout << "Вычислино за " << double(end - start) / CLOCKS_PER_SEC << " секунд\n";

	start = clock();
	cout << "Сумма элементов дерева: " << tree.sum() << "\t";
	end = clock();
	cout << "Вычислино за " << double(end - start) / CLOCKS_PER_SEC << " секунд\n";

	start = clock();
	cout << "Количество элементов дерева: " << tree.count() << "\t";
	end = clock();
	cout << "Вычислино за " << double(end - start) / CLOCKS_PER_SEC << " секунд\n";

	start = clock();
	cout << "Среднее-арифметическое элементов дерева: " << tree.avg() << "\t";
	end = clock();
	cout << "Вычислино за " << double(end - start) / CLOCKS_PER_SEC << " секунд\n";

	start = clock();
	cout << "Глубина дерева: " << tree.depth() << "\t";
	end = clock();
	cout << "Вычислино за " << double(end - start) / CLOCKS_PER_SEC << " секунд\n";

	int value;
	cout << "Введите удаляемое значение: "; cin >> value;
	tree.erase(value);*/
	//tree.print();
#endif // PERFORMANCE_CHECK

	Tree tree = { 55,34,21,13,8,5,3,2,1,1,0 };
	tree.tree_print();
	tree.balance();
	tree.tree_print();
}