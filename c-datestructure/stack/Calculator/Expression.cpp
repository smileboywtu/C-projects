#include"stack.h"

double calculate(double a,char o,double b){
	switch(o){
	case '+': return a+b;
	case '-': return a-b;
	case '*': return a*b;
	case '/': 
				if(b == 0 ){
					printf("It's not allowed when b equals to zero! ");
					return -1;
				}
				else
					return a/b;
	case '^': return pow(a,b);
	case '$': return sqrt(b);
	default: return -1;
	}
	return -1;
}

double Expression(char buffer[]){
	
	stackDouble data;
	initStack(data);
	stackChar operation;
	initStack(operation);
	push(operation,'#');
	
	int i = 0;
	for(i=0; buffer[i]!='\0'; i++);
	buffer[i] = '#';
	i = 0;
	
	while(top(operation) != '#' || buffer[i] != '#' ){

		if((buffer[i] >=48 && buffer[i] <=57) || buffer[i] == 46){
			int start = i,decimal = -1;
			for(; (buffer[i] >=48 && buffer[i] <=57) || buffer[i] == 46; i++)
				if(buffer[i] == 46)
					decimal = i;

			double sum = 0;
			if(decimal != -1){
				int length = decimal - start;
				int j = 1;
				for(length--; length>=0; length--)
					sum += (buffer[start++]-48)*pow(10,length);
				start++;
				for(length=i-decimal; j<length; j++)
					sum += (buffer[start++]-48)*pow(10,-j);
			}
			else{
				int length = i - start;
				for(length--; length>=0; length--)
					sum += (buffer[start++]-48)*pow(10,length);
			}
		
			push(data,sum);
		}

		else{
			if(compare(buffer[i],top(operation)) == 1)
				push(operation,buffer[i++]);
			
			else if(compare(buffer[i],top(operation)) == 0){
				pop(operation);
				i++;										
			}

			else{
				double b= top(data);
				pop(data);
				double a = top(data);
				if(top(operation) != '$')
					pop(data);
				push(data , calculate(a,top(operation),b) );
				pop(operation);				
			}
		}
	}

	return top(data);

}
