// No.2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


struct LinkNode
{
	int num;
	int den;
	LinkNode *link;
};

class List
{
private:
	int n;
	int num;
	LinkNode *first;
	LinkNode *last;
public:
	List(int x);
	void farey();
	void makeEmpty();
	int getNum();
	~List();
};

List::List(int x)
{
	n = x;
	num = 0;
	first = new LinkNode;
	last = new LinkNode;
}

void List::farey()
{
	int count = 0;
	first->num = 0;
	first->den = 1;
	first->link = last;
	last->num = 1;
	last->den = 1;
	last->link = NULL;
	LinkNode *p = first;
	while (p->link != NULL)
	{
		if (p->den + p->link->den <= n){
			LinkNode *q = new LinkNode;
			q->num = p->num + p->link->num;
			q->den = p->den + p->link->den;
			q->link = p->link;
			p->link = q;
		}
		else{
			cout << p->num << "/" << p->den << " ";
			count++;
			if (count == 4){
				cout << endl;
				count = 0;
			}
			p = p->link;
		}
	}
	cout << last->num << "/" << last->den;
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

int List::getNum()
{
	LinkNode *temp = first;
	while (temp != NULL)
	{
		num++;
		temp = temp ->link;
	}
	delete temp;

	return num;
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
	cout << "Please enter n:";
	int n;
	cin >> n;
	List Test(n);
	Test.farey();
	cout << "The number of node is:" << Test.getNum() << endl;
	system("pause");

	return 0;
}

