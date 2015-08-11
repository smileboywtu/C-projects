#include"stdio.h"
#include"stdlib.h"
#include"memory.h"

#define MAX 100
typedef int Elem;

//定义结构体
struct sqlist{
	Elem base[MAX];
	int size;
	int length;
};
//初始化操作
sqlist* init_list(){
	sqlist *L;
	L = (sqlist*)malloc(sizeof(sqlist));
	memset(L->base,0,MAX);
	if(!L)
		exit(0);
	L->length = MAX;
	L->size = 0;
	return L;
}
//插入操作
int insert_list(sqlist *L,Elem i,Elem e){
	if(i<1||i>L->length-1){
		printf("Can't find the location!");
		exit(0);
	}
	if(L->size >= L->length-1){
		printf("The list is FULL!");
		exit(0);
	}
	for(int j = L->size;j > i-1;j--)
		L->base[j] = L->base[j-1];

	L->base[i-1] = e;
	L->size++;

	return 1;
}
//删除操作
int delet_list(sqlist *L,Elem i,Elem &e){
	if(i<1||i>L->length){
		printf("Can't find the location!");
		exit(0);
	}
	if(L->size == 0){
		printf("The list is Empty!");
		exit(0);
	}
	e = L->base[i-1];

	for(int j = i;j < L->size;j++){
		L->base[j-1] = L->base[j];
	}
	L->size--;
	return 1;
}

//排序
int order_B_list(sqlist *L){
	Elem temp;
	for(int i = 0;i < L->size-1;i++)
		for(int j = 0;j < L->size-1;j++)
			if(L->base[j] > L->base[j+1]){
					temp = L->base[j+1];
					L->base[j+1] = L->base[j];
					L->base[j] = temp;
			}
	return 1;
}
int order_C_list(sqlist *L){
	Elem temp, k;
	for(int i =0;i < L->size-1;i++){
		k = i;
		for(int j = i+1;j < L->size;j++)
			if(L->base[k] > L->base[j])
				k = j;
	if(k != i){
		temp = L->base[i];
		L->base[i] = L->base[k];
		L->base[k] = temp;
	}
	}
	return 1;
}

//遍历
int traver_list(sqlist *L){
	for(int i = 0; i < L->size;i++)
		printf("%d  ",L->base[i]);
	printf("\n");
	return 1;
}

int main(){
	sqlist *L = init_list();
	int e = 0;
	printf("please input the Elem(int type):\n");
	scanf("%d",&e);
	while(e != -1){
		insert_list(L,1,e);
		scanf("%d",&e);
	}
	printf("Before deleting:");
	traver_list(L);
	printf("After ordered:");
	order_C_list(L);
	traver_list(L);
	delet_list(L,2,e);
	printf("The delet data(Second) is:%d\n",e);
	printf("After the data deleted:");
	traver_list(L);
	return 1;
}
