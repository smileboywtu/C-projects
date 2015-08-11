#include"stdlib.h"
#include"stdio.h"

#define ElemType int 
////this is special for queue
struct queueNode{
	ElemType data;
	queueNode* next;
};

struct queue{
	queueNode* head;
	queueNode* tail;
};

void initQueue(queue &q){
	q.head = q.tail = NULL;
}

void push(queue &q, ElemType data_){
	queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
	newNode->data = data_;
	newNode->next = q.tail;
	q.tail = newNode;
	if(!q.head)
		q.head = newNode;
}

ElemType front(queue q){
	if(q.head)
		return q.head->data;
	return -1;
}

void pop(queue &q){
	if(q.head){
		queueNode* temp = q.head;
		q.head = q.head->next;
		free(temp);
	}
}

bool empty(queue q){	
	if(q.head == q.tail)
		return false;
	return true;
}

int main(){

	queue q;

	initQueue(q);
	push(q,3);
	printf("%d \n",front(q));
	if(empty(q))
		printf("The queue is empty! ");

	return 1;
}
