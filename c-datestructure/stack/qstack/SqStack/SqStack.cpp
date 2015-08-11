#include"stdio.h"
#include"stdlib.h"
#include"memory.h"

#define MAX 20
typedef int Elem;

struct Stack{
	Elem data[MAX];
	int top;
};

Stack* Creat_stack(){
	Stack *S = (Stack*)malloc(sizeof(Stack));
	if(!S)
		exit(0);
	memset(S->data,0,MAX);
	S->top = -1;
	return S;
}

bool In_stack(Stack *S){
	if(S->top == MAX-1){
		printf("The stack is full!\n");
		exit(0);
	}
	Elem e;
	printf("Input the number(end with -1):");
	scanf("%d",&e);
	while(e != -1){
		S->data[++S->top] = e;
		scanf("%d",&e);
	}
	return true;
}

bool Out_stack(Stack *S){
	if(S->top == -1){
		printf("The stack is empty!\n");
		exit(0);
	}
	printf("The data outed:\n",S->data[S->top--]);
	return true;
}
bool traver_stack(Stack *S){
	if(S->top == -1){
		printf("The stack is empty!\n");
		exit(0);
	}
	printf("The whole info:");
	while(S->top != -1)
		printf("%d",S->data[S->top--]);
	printf("\n");
	return true;
}

int main(){

	Stack *S = Creat_stack();

	In_stack(S);

	traver_stack(S);

	Out_stack(S);

	traver_stack(S);

	
	return 1;
}