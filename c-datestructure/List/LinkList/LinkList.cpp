#include"stdio.h"
#include"stdlib.h"

typedef int Elem;					//datatype

typedef struct node{				//data definition
	Elem data;
	struct node *next;
} LNode,*LinkList;


LinkList Creat_list(){				//creat a linklist
	LinkList L = NULL;
	L = (LinkList)malloc(sizeof(LNode));
	if(!L)
		exit(0);
	L->next = NULL;
	return L;
}

bool Insert_list(LinkList L){								//insert a node
	LinkList pcur = L;
	while(pcur->next != NULL)
		pcur = pcur->next;									//move the present point to the end
	Elem e;
	scanf("%d",&e);
	while(e != -1){													
	LinkList N = (LinkList)malloc(sizeof(LNode));			//alloc a new node
	if(!N)
		return false;
	pcur->next = N;											//link the new node
	N->data = e;
	N->next = NULL;
	scanf("%d",&e);
	pcur = N;
	}
	return true;
}

bool Delet_list(LinkList L,Elem i){					//delet a member of the linklist
	LinkList pcur = L;
	if(pcur->next == NULL && i > 1 || i < 1)
		return false;
	Elem k = 1 ;
	while(pcur->next != NULL && k != i){
		pcur = pcur->next;
		k++;
	}
	if(pcur->next == NULL)
		return false;
	printf("The deleted data:%d\n",pcur->next->data);
	pcur->next = pcur->next->next;
	return true;
}

bool Sort_list(LinkList L){								//use bubble method
	LinkList ptem = L;
	int k = 0;
	Elem tem;
	while(ptem->next != NULL){							//get the length of the linklist
		ptem = ptem->next;
		k++;
	}
	for(int i = 0; i < k-1;i++ ){
		ptem = L;
		for(int j = 0; j < k-i;j++){
			if(ptem->data > ptem->next->data){
				tem = ptem->next->data;
				ptem->next->data = ptem->data;
				ptem->data = tem;
			}
			ptem = ptem->next;	
		}

	}
	return true;
}
bool Traver_list(LinkList L){							//show all information 
	LinkList ptemp = L->next;
	while(ptemp != NULL){								//the present point(inserted)
		printf("%d",ptemp->data);
		ptemp = ptemp->next;
	}
	printf("\n");
	return true;
}

int main(){

	LinkList L = Creat_list();

	printf("Input the date(end with -1):\n");
	Insert_list(L);
	printf("The original data structure:");
	Traver_list(L);

	printf("The data in order:");
	Sort_list(L);
	Traver_list(L);

	Delet_list(L,2);
	printf("After deleting:");
	Traver_list(L);
	
	return 1;
}
