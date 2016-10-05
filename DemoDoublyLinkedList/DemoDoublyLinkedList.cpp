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
	void pop_back();
	void push_front(int x);
	void pop_front();
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

void DoublyLinkedList::pop_back() {
	if (length > 0)
	{
		Node* pLastNode = tail;
		tail = tail->prev;
		pLastNode->prev->next = NULL;
		free(pLastNode);
	};
}

void DoublyLinkedList::push_front(int x) {
	Node* newNode = new Node(x);
	newNode->value = x;
	newNode->next = head;
	head = newNode;
	length++;
}

void DoublyLinkedList::pop_front() {
	if (length > 0) {
		Node* oldHead = head;
		head = (head->next);
		free(oldHead);
		length--;
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
	if (length < position) {
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

	for (int i = 0; i < doublyLinkedList.count(); i++) {
		cout << "Position " << i << ": ";
		doublyLinkedList.print_at_position(i);
	}

	doublyLinkedList.print_all();
	doublyLinkedList.print_all_reversely();

	doublyLinkedList.pop_back();
	doublyLinkedList.print_all();

	doublyLinkedList.push_front(0);
	doublyLinkedList.print_all();

	doublyLinkedList.pop_front();
	doublyLinkedList.print_all();


	getchar();
	return 0;
}

