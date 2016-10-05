// DemoDoublyLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct Node {
	int value;
	struct Node *next;
	struct Node *prev;

	Node(int x) {
		value = x;
		next = prev = NULL;
	}
} *start;

class DoublyLinkedList {
private:
	Node *head;
	Node *tail;
	int length;

public:
	DoublyLinkedList() {
		head = NULL;
		tail = NULL;
		length = 0;
	}
	// insert the value at the rear of the list
	void push_back(int x);
	int pop_back();
	void push_front(int x);
	int pop_front();
	void print_all();
	void print_all_reversely();
	void print_at_position(int position);
	int count();
};

void DoublyLinkedList::push_back(int x) {
	Node *newNode = new Node(x);

	if (length == 0) {
		head = tail = newNode;
	}
	else {
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	length++;
}

int DoublyLinkedList::pop_back() {
	if (length > 0)
	{
		Node* oldTail = tail;
		tail = tail->prev;
		int value = oldTail->value;
		tail->next = NULL;
		free(oldTail);
		length--;
		if (length == 1) head->next = NULL;
		return value;
	};
}

void DoublyLinkedList::push_front(int x) {
	Node* newNode = new Node(x);
	if (length == 0) {
		head = tail = newNode;
	}
	else {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	length++;
}

int DoublyLinkedList::pop_front() {
	if (length > 0) {
		Node* oldHead = head;
		int value = oldHead->value;
		head = (head->next);
		head->prev = NULL;
		free(oldHead);
		length--;
		if (length == 1) tail->prev = NULL;
		return value;
	}
	else {
		throw out_of_range("There is no element on this Doubly Linked List.");
	}
}

int DoublyLinkedList::count() {
	return length;
}

void DoublyLinkedList::print_all() {
	cout << "Print all elements" << endl;
	if (length > 0) {
		Node* cur = head;
		while (cur) {
			cout << cur->value << endl;
			cur = cur->next;
		}
	}
	else {
		cout << "Empty Doubly Linked List" << endl;
	}
	cout << "#######" << endl;
}

void DoublyLinkedList::print_all_reversely() {
	cout << "Print all elements reversely" << endl;
	if (length > 0) {
		Node* cur = tail;
		while (cur != NULL) {
			cout << cur->value << endl;
			cur = cur->prev;
		}
	}
	else {
		cout << "Empty Doubly Linked List";
	}
	cout << "*******" << endl;
}

void DoublyLinkedList::print_at_position(int position) {
	Node* cur = head;
	if (length <= position) {
		throw out_of_range("Position is out of bound of this Doubly Linked List.");
	}
	else {
		for (int i = 0; i < position; i++) {
			cur = cur->next;
		}
		cout << cur->value << endl;
	}
}


int main()
{
	DoublyLinkedList doublyLinkedList;

	doublyLinkedList.push_back(1);
	doublyLinkedList.push_back(2);
	doublyLinkedList.push_back(3);
	doublyLinkedList.push_back(4);
	doublyLinkedList.push_back(5);
	doublyLinkedList.push_back(6);
	doublyLinkedList.push_back(7);

	cout << "Length of DoublyLinkedList: " << doublyLinkedList.count() << endl;

	cout << "Method: print_at_position(int position)" << endl;
	for (int i = 0; i < doublyLinkedList.count(); i++) {
		cout << "Position " << i << ": ";
		doublyLinkedList.print_at_position(i);
	}
	cout << endl;

	cout << "Method: print_all()" << endl;
	doublyLinkedList.print_all();
	cout << endl;
	cout << "Method: print_all_revesely()" << endl;
	doublyLinkedList.print_all_reversely();
	cout << endl;

	cout << "Method: pop_back()" << endl;
	cout << doublyLinkedList.pop_back() << endl;
	doublyLinkedList.print_all();
	cout << endl;

	cout << "Method: push_front(0)" << endl;
	doublyLinkedList.push_front(0);
	doublyLinkedList.print_all();
	cout << endl;

	cout << "Method: pop_front()" << endl;
	cout << doublyLinkedList.pop_front() << endl;
	doublyLinkedList.print_all();
	cout << endl;

	getchar();
	return 0;
}

