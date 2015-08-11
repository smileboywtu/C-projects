#include"stdio.h"
#include"stdlib.h"

typedef int Elem;

typedef struct node{
	Elem data;
	node *Next;
}StackNode,*LinkStack;



LinkStack In_stack(LinkStack top){
	printf("Input the data(end with -1):");
	Elem e;
	scanf("%d",&e);
	while(e != -1){
		StackNode *N = (StackNode*)malloc(sizeof(StackNode));
		if(!N)
			exit(0);
		N->data = e;
		N->Next = top;
		top = N;
		scanf("%d",&e);
	}
	return top;
}

int Out_stack(LinkStack &top){
	if(top == NULL)
		exit(0);
	top = top->Next;
	return 1;
}

int traver_stack(LinkStack top){
	LinkStack temp = top;
	printf("The whole info:");
	while(temp != NULL){
		printf("%d",temp->data);
		temp = temp->Next;
	}
	printf("\n");
	return 1;
}
int main(){

	LinkStack top = NULL;

	top = In_stack(top);

	traver_stack(top);

	Out_stack(top);

	traver_stack(top);
	return 1;
}