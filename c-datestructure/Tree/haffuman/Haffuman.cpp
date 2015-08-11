// Haffman.cpp : Defines the entry point for the console application.
//


//============================================================================
// Name        : Haffman.cpp
// Author      : SmithBob
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include"iostream"
using namespace std;

typedef struct BitNode {
	int data;
	BitNode * lch;
	BitNode * rch;
}*BiTree;

void bubbleSort(int a[], int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1]) {
				a[j] = a[j] ^ a[j + 1];
				a[j + 1] = a[j] ^ a[j + 1];
				a[j] = a[j] ^ a[j + 1];
			}
}
//The Haffman tree is a bite tree;
void Haffman(BiTree &T, int code[], int n) {
	BiTree temp1, temp2, temp3 = NULL;
	int counter = n-2, pur = 0, data = -1;
	//initial the tree
	temp1 = new BitNode;
	temp2 = new BitNode;
	temp1->data = code[pur+1];
	temp2->data = code[pur];
	temp1->lch = temp1->rch = NULL;
	temp2->lch = temp2->rch = NULL;
	T = new BitNode;
	T->lch = temp1;
	T->rch = temp2;
	T->data = temp1->data + temp2->data;
	pur++;
	while(counter){
		code[pur] = T->data;
		bubbleSort(code + pur, --counter);
		if (T->data == code[pur] || T->data == code[pur+1]) {
			temp1 = T;
			temp2 = new BitNode;
			if (code[pur] == T->data)
				temp2->data = code[pur+1];
			else
				temp2->data = code[pur];
			temp2->lch = temp2->rch = NULL;
			T = new BitNode;
			T->lch = temp1;
			T->rch = temp2;
			T->data = temp1->data + temp2->data;
		} 
		else {
			//the previous root is  include;
			if (code[pur] == data || code[pur+1] == data) {
				temp1 = temp3;
				temp2 = new BitNode;
				if (code[pur] == data)
					temp2->data = code[pur+1];
				else
					temp2->data = code[pur];
				temp2->lch = temp2->rch = NULL;
				T = new BitNode;
				T->lch = temp1;
				T->rch = temp2;
				T->data = temp1->data + temp2->data;
			}
			//the current root is not include;
			//this used to record the data used;
			else{
				temp3 = T;
				data = T->data;
				//do the current root
				temp1 = new BitNode;
				temp2 = new BitNode;
				temp1->data = code[pur+1];
				temp2->data = code[pur];
				temp1->lch = temp1->rch = NULL;
				temp2->lch = temp2->rch = NULL;
				T = new BitNode;
				T->lch = temp1;
				T->rch = temp2;
				T->data = temp1->data + temp2->data;
			}
		}
		pur++;
	}
}
void traverse(BiTree T) {
	if (T) {
		cout << T->data << " ";
		traverse(T->lch);
		traverse(T->rch);
	}
}
int main() {
	int code[] = { 1, 6 ,9,17};
	bubbleSort(code, sizeof(code) / 4);
	BiTree T = NULL;
	Haffman(T, code, sizeof(code) / 4);
	traverse(T);
	return 0;
}
