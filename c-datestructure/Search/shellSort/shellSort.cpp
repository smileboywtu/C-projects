#include"stdio.h"

void shellSort(int a[], int n){
	int dk[] = {5,3,1};
	for(int k=0; k<3; k++){
		for(int i=1+dk[k]; i<=n; i++){
			a[0] = a[i];
			for(int j=i-dk[k]; j>0 && a[0]<a[j]; j-=dk[k])
				a[j+dk[k]] = a[j];
			a[j+dk[k]] = a[0];
		}
	}
}

int main(){
	int a[] = {0,12,35,62,58,93,23,16,17,45,11,5,6};
	
	shellSort(a,12);

	for(int i=1; i<=12; i++)
		printf("%d ",a[i]);
	return 1;
}