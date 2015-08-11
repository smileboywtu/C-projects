#include"stdio.h"

void insertSort(int a[], int n){
	for(int i=2; i<=n; i++){
		a[0] = a[i];
		for(int j=i-1; a[0]<a[j]; j--)
			a[j+1] = a[j];
		a[j+1] = a[0];
	}
}

int main(){
	int a[] = {0,12,35,62,58,93,23,16,17,45,11,5,6};
	
	insertSort(a,12);

	for(int i=1; i<=12; i++)
		printf("%d ",a[i]);
	return 1;
}