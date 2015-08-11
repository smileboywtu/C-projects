#include"iostream"
using namespace std;

typedef struct stack{
	int top;
	int data[50];
}*Stack;


Stack initstack(){
	Stack p = new stack();
	p->top = 0;
	return p;
}

int instack(Stack &p,int e){
	p->data[p->top++] = e;
	return 1;
}
int outstack(Stack p){
	while(p->top > -1)
	cout<<p->data[p->top--];
	cout<<"\n";
	return 1;
}

int storage(Stack &p){
	cout<<"Enter the number(%O):";
	char s[20] = {'\0'};
	cin>>s;
	for(int i = 0;s[i] != '\0';i++)
		instack(p,s[i]-'0'); 
	return 1;
}
int exchange(Stack &p,Stack &q){
	int k;
	if(p->top < 0 )
		return 0;
	for(k = 1;k <= 3;k++){
		if(q->data[p->top+0]+q->data[p->top+1]+q->data[p->top+2] == p->data[p->top]){
			p->top += 3;
			exchange(d,o);
		}
		if(p->data[p->top+1])
	}
	
	return 1;
}
	

int main(){
	Stack d = initstack();
	Stack o = initstack();
	storage(d);
	exchange(d,o);
	
	system("pause");
	return 1;
}