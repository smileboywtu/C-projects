// SearchTree.cpp : Defines the entry point for the console application.
//

//============================================================================
// Name        : SearchTree.cpp
// Author      : SmithBob
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include"stdafx.h"
#include <iostream>
using namespace std;
//The tree node;
typedef struct BitNode {
	int data;
	BitNode * lch;
	BitNode * rch;
}*BiTree;
//The search Tree;
BiTree Search(BiTree T, int key, BiTree f, BiTree &p) {
	if(!T){
		return f;
	}
	if (key == T->data) {
		p = T;
		return NULL;
	} else if (key > T->data) {
		f = T; //record the headNode(previous);
		return Search(T->rch, key, f, p); 
	} else {
		f = T; //record the headNode(previous);
		return Search(T->lch, key, f, p);
	}
}

void insert(BiTree &T, int key) {
	BiTree f = NULL, p = NULL, temp;
	if(!T){
		temp = new BitNode;
		temp->data = key;
		temp->lch = NULL;
		temp->rch = NULL;
		T = temp;
	}
	f = Search(T, key, f, p); //
	//out the search result;
	if (p)
		cout << p->data << endl;
	else {
		temp = new BitNode;
		temp->data = key;
		temp->lch = NULL;
		temp->rch = NULL;
		if (key > f->data)
			f->rch = temp;
		else
			f->lch = temp;
	}
}

void traverse(BiTree T){
	if(T){
		traverse(T->lch);
		cout<<T->data<<" ";
		traverse(T->rch);
	}
}
int main() {
	int a[] = { 12, 56, 45, 8, 6, 35, 79, 52, 46, 85, 29, 37, 39, 49 }; //count  = 14
	BiTree T = NULL;
	int i = 0;
	for (i = 0; i < 14; i++)
		insert(T, a[i]);
	traverse(T);
	return 0;
}

