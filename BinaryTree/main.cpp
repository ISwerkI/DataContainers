#include <iostream>
#include<Windows.h>
using std::endl;
using std::cin;
using std::cout;

#define tab		"\t"
#define delimeter "\n------------------------------------------\n"

class Tree
{
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr)
			:Data(Data), pLeft(pLeft), pRight(pRight)
		{
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		friend class Tree;
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
	~Tree()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	int minVal(Element* Root)const
	{
		if (this->Root == nullptr)return 0;
		return Root->pLeft == nullptr ? Root->Data : minVal(Root->pLeft);
		/*if (Root->pLeft == nullptr) return Root->Data;
		minVal(Root->pLeft);*/
	}
	int maxVal(Element* Root)const
	{
		if (this->Root == nullptr)return 0;
		return Root->pRight == nullptr ? Root->Data : maxVal(Root->pRight);
		/*if (Root->pRight == nullptr) return Root->Data;
		maxVal(Root->pRight);*/
	}
	int Sum(Element* Root)const
	{
		return Root==nullptr?0: Sum(Root->pLeft) + Sum(Root->pRight) + Root->Data;
		/*if (Root == nullptr)return 0;
		else return Sum(Root->pLeft) + Sum(Root->pRight) + Root->Data;*/
	}
	int count(Element* Root)const
	{
		return Root==nullptr? 0 : count(Root->pLeft) + count(Root->pRight) + 1;
	}
	double avg(Element* Root)const
	{
		return (double)Sum(Root) / count(Root);
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

	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//system("chcp 866");
	//SetConsoleOutputCP(866);
	int n;
	cout << "Введите размер дерева: ";cin >> n;
	Tree tree;
	for (int i = 0;i < n;i++)
	{
		tree.insert(rand() % 100,tree.getRoot());
	}
	tree.print(tree.getRoot());
	cout << endl;
	cout << "Минимальное значение в дереве: "; cout << tree.minVal(tree.getRoot())<<endl;
	cout << "Максимальное значение в дереве: "; cout << tree.maxVal(tree.getRoot())<<endl;
	cout << "Сумма элементов дерева: "<<tree.Sum(tree.getRoot())<<endl;
	cout << "Количество элементов дерева: " << tree.count(tree.getRoot()) << endl;
	cout << "Среднее-арифметическое элементов дерева: " <<tree.avg(tree.getRoot())<< endl;
}