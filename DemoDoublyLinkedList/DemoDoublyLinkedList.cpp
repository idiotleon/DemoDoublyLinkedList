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
} *start;

class DoublyLinkedList {
private:
	Node *head;
	int length;

public:
	DoublyLinkedList() {
		head = new Node;
		head->next = head->prev = head;
		head->value = 0;
		length = 1;
	}
	// insert the value at the rear of the list
	void push_back(int x);
	void push_back_2(int x);
	void pop_back();
	void push_front(int x);
	void pop_front();
	void print();
	void print_reversely();
	int count();
	Node* getTailNode();
	bool isEmpty();
	bool isEmpty_2();
	bool isLastNode(Node* node);
};

void DoublyLinkedList::push_back(int x) {
	Node *newNode = new Node;
	Node* tailNode = getTailNode();
	newNode->value = x;
	newNode->next = NULL;
	if (length == 0) {
		head = newNode;
	}
	else {
		newNode->prev = tailNode;
		tailNode->next = newNode;
		length++;
	}
}

void DoublyLinkedList::pop_back() {
	if (length > 0)
	{
		Node* lastNode = getTailNode();
		lastNode->prev->next = NULL;
		free(lastNode);
	};
}

void DoublyLinkedList::push_back_2(int x)
{
	Node *newNode = new Node;
	newNode->value = x;
	newNode->next = head;
	newNode->prev = head->prev;
	newNode->next->prev = newNode;
	newNode->prev->next = newNode;
	length++;
}

void DoublyLinkedList::push_front(int x) {
	Node* newNode = new Node;
	newNode->value = x;
	newNode->next = head;
	head = newNode;
	length++;
}

void DoublyLinkedList::pop_front() {
	// what happened if head==NULL
	head = (head->next);
	// how to deal with the old head
	length--;
}

bool DoublyLinkedList::isEmpty() {
	if (head == NULL)
	{
		cout << "The DoublyLinked List is empty" << endl;
		return true;
	}
	else {
		cout << "The Doubly Linked List is not empty" << endl;
		return false;
	}
}

bool DoublyLinkedList::isEmpty_2() {
	return head->next == head;
}

int DoublyLinkedList::count() {
	return length;
}

Node* DoublyLinkedList::getTailNode() {
	Node* temp = head;
	if (length == 0)  return NULL;
	while (!isLastNode(temp))
		temp = temp->next;
	return temp;
}

bool DoublyLinkedList::isLastNode(Node* node) {
	if (node->next == NULL) return true;
	else return false;
}

void DoublyLinkedList::print() {
	if (length > 0) {
		Node* cur = head;
		if (!isLastNode(cur)) {
			cout << cur->value << endl;
			cur->next = cur->next->next;
		}
		else {
			cout << cur->value << endl;
		}
	}
	else {
		cout << "Empty Doubly Linked List";
	}
}

void DoublyLinkedList::print_reversely() {
	if (length > 0) {
		Node* cur = getTailNode();
		while (cur->prev != NULL) {
			cout << cur->value << endl;
		}
	}
	else {
		cout << "Empty Doubly Linked List";
	}
}


int main()
{
	DoublyLinkedList doublyLinkedList;

	doublyLinkedList.push_back_2(7);
	doublyLinkedList.print();


	getchar();
	return 0;
}

