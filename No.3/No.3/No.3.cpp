// No.3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


struct LinkNode
{
	int data;
	LinkNode *link;
};

class List
{
private:
	LinkNode *first;
	int n;
public:
	List(int tn);
	void factorial();
	void inverse();
	void show();
	void makeEmpty();
	~List();
};

List::List(int tn)
{
	n = tn;
	first = new LinkNode;
	first->data = 1;
	first->link = NULL;
}

void List::factorial()
{
	int i = 1;
	if (n > 1){
		LinkNode *temp1, *temp2;
		temp1 = first;
		temp2 = temp1;
		for (; i <= n; i++)
		{
			temp1 = first;
			while (temp1 != NULL)
			{
				temp1->data *= i;
				temp1 = temp1->link;
			}
			temp1 = first;
			while (temp1 != NULL)
			{
				if (temp1->data >= 1000){
					if (temp1->link == NULL){
						temp1->link = new LinkNode;
						temp1->link->link = NULL;
					}
					temp2 = temp1;
					temp1 = temp1->link;
					if (temp1->data < 0){
						temp1->data = 0;
					}
					temp1->data = temp1->data + temp2->data / 1000;
					temp2->data = temp2->data % 1000;			
					if (temp2->data >= 1000){
						temp1 = temp2;
					}
				}
				else if (temp1->data < 1000){
					temp1 = temp1->link;
				}
			}
		}
	}
	else{
		return;
	}
}

void List::inverse()//逆置
{
	LinkNode *next, *current, *previous;
	previous = first;
	current = first->link;
	previous->link = NULL;
	while (current != NULL && current->link != NULL)
	{
		next = current->link;
		current->link = previous;
		previous = current;
		current = next;
	}
	if (current != NULL){
		current->link = previous;
		first = current;
	}
}

void List::show()
{
	if (n > 1){
		inverse();
		cout << first->data;
		first = first->link;
		while (first != NULL)
		{
			if (first->data < 10){
				cout << "00" << first->data;
			}
			else if (first->data >= 10 && first->data < 100){
				cout << "0" << first->data;
			}
			else{
				cout << first->data;
			}
			if (first->link == NULL){
				break;
			}
			first = first->link;
		}
		cout << endl;
	}
	else{
		cout << 1 << endl;
	}
}

void List::makeEmpty()
{
	LinkNode *q;
	while (first != NULL&&first->link != NULL)
	{
		q = first->link;
		first->link = q->link;
		delete q;
	}
}

List::~List()
{
	if (first != NULL&&first->link == NULL){
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
	List test(n);
	test.factorial();
	test.show();
	system("pause");

	return 0;
}

