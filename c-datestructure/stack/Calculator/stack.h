#pragma message("This is the result of compiling the stack: ")
#include"memory.h"
#include"math.h"
#include"stdlib.h"
#include"stdio.h"

/*------------------this block used for prior--------------------*/
const prior[9][9] = {
		// '+' '-' '*' '/' '(' ')' '#' '^'  '$' 
    /*'+'*/'<','<','<','<','>','>','>','<','<', 
    /*'-'*/'>','>','<','<','>','>','>','<','<',  
    /*'*'*/'>','>','<','<','>','>','>','<','<',  
    /*'/'*/'>','>','<','<','>','>','>','<','<',  
    /*'('*/'>','>','>','>','>',' ','>','>','>',  
    /*')'*/'<','<','<','<','=','<',' ','<','<',  
    /*'#'*/'<','<','<','<','<',' ','=','<','<',  
    /*'^'*/'>','>','>','>','>','>','>','<','<',
	/*'$'*/'>','>','>','>','>','>','>','<','<'
};

const char offset[] = {'+','-','*','/','(',')','#','^','$'};

int compare(char a,char b){ //buffer first
	int m=0,n=0;

	for(int i=0; i<8; i++)
		if(offset[i] == a)
			m = i;
		else if(offset[i] == b)
			n = i;

	if(prior[m][n] == '>')
		return 1;

	else if(prior[m][n] == '<')
		return -1;

	else
		return 0;
}

/*------------------end the block-------------------*/


//////////////////////////this is the stack block//////////////
//this stack used to sava double
struct stackNode{
	double d;
	stackNode* next;
};

struct stackDouble{
	stackNode* top;
};

void initStack(stackDouble &s){
	s.top = NULL;
}

bool empty(stackDouble s){
	if(s.top == NULL)
		return true;
	return false;
}

double top(stackDouble s){
	if(!empty(s))
		return s.top->d;
	return -1;
}

void pop(stackDouble &s){
	stackNode* temp =  s.top;
	s.top = s.top->next;
	free(temp);
}

void push(stackDouble &s,double d){
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->d = d;
	temp->next = s.top;
	s.top = temp;
}

//this used to save char
struct stackNode_{
	char d;
	stackNode_* next;
};

struct stackChar{
	stackNode_* top;
};

void initStack(stackChar &s_){
	s_.top = NULL;
}

bool empty(stackChar s_){
	if(s_.top == NULL)
		return true;
	return false;
}

char top(stackChar s_){
	if(!empty(s_))
		return s_.top->d;
	return '\0';
}

void pop(stackChar &s_){
	stackNode_* temp =  s_.top;
	s_.top = s_.top->next;
	free(temp);
}

void push(stackChar &s_,char c){
	stackNode_* temp = (stackNode_*)malloc(sizeof(stackNode_));
	temp->d = c;
	temp->next = s_.top;
	s_.top = temp;
}
//////////end the block////////////


#pragma message("Successful")