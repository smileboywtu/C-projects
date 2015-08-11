#include"stdlib.h"
#include"stdio.h"
//////you can use stack to storage different type of data/////
#define  ElemType int

struct stackNode{
	ElemType data;
	stackNode* next;
};

struct stack{
	stackNode* top;
};


/////do the initialization//////
void initStack(stack &s){
	s.top = NULL;
}

bool empty(stack s){
	if(s.top)
		return false;
	return true;
}

ElemType top(stack s){
	return s.top->data;
}

void push(stack &s, ElemType data_){
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	newNode->data = data_;
	newNode->next = s.top;
	s.top = newNode;
}

void pop(stack &s){
	stackNode* temp = s.top;
	s.top = s.top->next;
	free(temp);
}

void destroy(stack &s){
	stackNode* temp;
	while(s.top){
		temp = s.top;
		s.top = s.top->next;
		free(temp);
	}
}

/////now this is the test/////
int main(){
//	#undef ElemType
//	#define ElemType char
	stack s;
	initStack(s);
	push(s,3);
	printf("%d \n",top(s));
//	pop(s);
	if(empty(s))
		printf("The stack is empty! \n");
	else
		printf("The stack is not empty! \n");
	return 1;
}