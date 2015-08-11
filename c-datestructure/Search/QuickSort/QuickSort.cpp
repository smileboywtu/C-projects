#include"stdio.h"

int partition(int a[],int low,int high){
	a[0] = a[low];
	while(low < high){
		while(low<high && a[high] >= a[0]) high--;
			a[low] = a[high];
		while(low<high && a[low] <= a[0]) low++;
			a[high] = a[low];
	}
	a[low] = a[0];
	return low;
}

void QuickSort(int a[],int low,int high){
	if(low < high){
		int divide = partition(a,low,high);
		QuickSort(a,low,divide-1);
		QuickSort(a,divide+1,high);
	}
}

int main(){
	int a[] = {0,45,5,8,7,1,12,4,89,78,52,37,88,26};
	QuickSort(a,1,13);
	for(int i=1; i<=13; i++)
		printf("%d ",a[i]);
	return 1;
}