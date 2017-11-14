// No.1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct LinkNode
{
	int data;
	LinkNode *link;
	LinkNode(){};
	LinkNode(int &x)
	{
		data = x;
	}
};

class List
{
private:
	LinkNode *first;
	int n;
	int Data;
public:
	List(int tn);
	void Merge(LinkNode *ha,LinkNode *hb);
	bool Insert(int i, int &x);//插入
	void inverse();//逆置
	void sort();//排序
	void show();//顺序输出
	void InShow(LinkNode *p);//逆序输出
	void makeEmpty();
	~List();
	LinkNode *GetList();
};

List::List(int tn)
{
	for (int i = 0; i < tn; i++)
	{
		cin >> Data;
		Insert(i, Data);
	}
}

void List::Merge(LinkNode *ha,LinkNode *hb)
{
	LinkNode *tempNode = new LinkNode;
	LinkNode *tempNode2 = new LinkNode;
	tempNode = ha;
	tempNode2 = hb;
	if (ha == NULL){
		ha = hb;
	}
	else{
		while (ha->link != NULL)
		{
			ha = ha->link;
		}
		ha->link = hb;
	}
	 
	ha = tempNode;
	first = ha;
	sort();
}

void List::sort()//递增排序
{
	LinkNode *p, *ta;
	ta = first;
	int temp;
	while (ta)
	{
		ta = ta->link;
		n++;
	}
	p = first;
	for (int i = 1; i < n; ++i)
	{
		p = first;
		for (int j = 0; j < n - i; ++j)
		{
			if (p->data > p->link->data)
			{
				temp = p->data;
				p->data = p->link->data;
				p->link->data = temp;
			}
			p = p->link;
		}
	}
}

bool List::Insert(int i,int &x)
{
	if (first == NULL || i == 0){
		LinkNode *newNode = new LinkNode(x);
		if (newNode == NULL){
			cerr << "储存分配错误！\n"; exit(i);
		}
		newNode->link = first;
		first = newNode;
	}
	else{
		LinkNode *current = first;
		for (int k = 1; k < i; k++)
		{
			if (current == NULL)break;
			else current = current->link;
		}
		if (current == NULL){
			cerr << "无效的插入位置！\n"; return false;
		}
		else{
			LinkNode *newNode = new LinkNode(x);
			if (newNode == NULL){
				cerr << "储存分配错误！\n"; exit(i);
			}
			newNode->link = current->link;
			current->link = newNode;
		}
	}
	return true;
}

void List::show()//递归输出
{
	LinkNode *temp;
	temp = first;
	if (first == NULL){
		first = temp;
		cout << endl;
		return;
	}
	else{
		cout << first->data << " ";
		first = first->link;
		show();
	}
}

LinkNode *List::GetList()
{
	return first;
}

void List::inverse()//逆置
{
	LinkNode *next, *current, *previous;
	previous = first;
	current = first->link;
	previous->link = NULL;
	while (current->link != NULL)
	{
		next = current->link;
		current->link = previous;
		previous = current;
		current = next;
	}
	current->link = previous;
	first = current;
}

void List::InShow(LinkNode *p)//递归逆序输出
{
	if (p != NULL){
		InShow(p->link);
		cout << p->data << " ";
	}
}

void List::makeEmpty()
{
	LinkNode *q;
	while (first->link != NULL)
	{
		q = first->link;
		first->link = q->link;
		delete q;
	}
}

List::~List()
{
	if (first->link == NULL){
		delete first;
	}
	else{
		makeEmpty();
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int na, nb;
	cout << "Please enter the length of ha:";
	cin >> na;
	cout << "Please enter the data of ha(Enter the next number after enter):";
	List la(na);
	cout << "Please enter the length of hb:";
	cin >> nb;
	cout << "Please enter the data of hb(Enter the next number after enter):";
	List lb(nb);
	LinkNode *ha = la.GetList();
	LinkNode *hb = lb.GetList();
	la.Merge(ha, hb);
	ha = la.GetList();
	/*la.inverse();
	la.show();*/
	la.InShow(ha);
	system("pause");

	return 0;
}

