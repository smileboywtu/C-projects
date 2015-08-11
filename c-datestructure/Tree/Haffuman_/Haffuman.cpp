/*
 * Haffuman.cpp
 *
 *  Created on: 5 Dec 2013
 *      Author: SmithBob
 */
// Yeah I can do if myself
#include <iostream>
using namespace std;

//This is used for the Haffman Tree
#define MAXVALUE 1000
#define MAXLEAF 30
#define MAXNODE 2*MAXLEAF -1

//Haffman Node Struct
typedef struct {
	int weight;
	int parent;
	int lch;
	int rch;
} HaffmanNode;

void Haffman(HaffmanNode *haffmanNode) {
	int n = 0;
	int child1, child2, weight1, weight2;
	//This is used to get the number of the code;
	cout << "please enter the number of the code: " << endl;
	cin >> n;
	//initial all the tree Node;
	cout << "please enter the weight : " << endl;
	for (int i = 0; i < n; i++) {
		cin >> haffmanNode[i].weight;
		haffmanNode[i].parent = -1;
		haffmanNode[i].lch = -1;
		haffmanNode[i].rch = -1;
	}
	for (i = 0; i < n - 1; i++) {
		//do the initialization
		child1 = child2 = 0;
		weight1 = weight2 = MAXVALUE;
		//search the node;
		for (int j = 0; j < n + i; j++) {
			if (haffmanNode[j].weight < weight1
					&& haffmanNode[j].parent == -1) {
				weight2 = weight1;
				child2 = child1;
				weight1 = haffmanNode[j].weight;
				child1 = j;
			}
			else {
				weight2 = haffmanNode[j].weight;
				child2 = j;
			}
		}
		//creat haffmanTree
		haffmanNode[child1].parent = n+i;
		haffmanNode[child2].parent = n+i;
		haffmanNode[n+i].weight = weight1 + weight2;
		haffmanNode[n+i].lch = child1;
		haffmanNode[n+i].rch = child2;
	}
	for(int k=n; k<n*2-1; k++)
		cout<<haffmanNode[k].weight<<" ";
}
int main(){

	HaffmanNode haffmanNode[MAXLEAF];
	Haffman(haffmanNode);
	return 1;
}
