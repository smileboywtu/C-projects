#include"iostream"
using namespace std;
int search(int n, int aim,int s[]){
	s[0] = aim;
	for(int i=n; 1; i--)
		if(s[i] == aim)
			return i;
}
void bubble(int n, int s[]){
	for(int i=0; i<n; i++)
		for(int j=0; j<n-i-1; j++){
			if(s[j] > s[j+1]){
				s[j] = s[j]^s[j+1];
				s[j+1] = s[j]^s[j+1];
				s[j] = s[j]^s[j+1];
			}
		}
}
int midsearch(int low,int high,int aim,int s[]){
	int mid = (low+high)/2;
	if(low > high)
		return 0;
	if(s[mid] > aim)
		return midsearch(low,(mid-1),aim,s);
	if(s[mid] < aim)
		return midsearch((mid+1),high,aim,s);
	return mid;
}

int main(){
	int s[] = {0,9,8,5,6,2,7,4,1,3,10};
	int aim = 0;
	cout<<"please input the aim: ";
	cin>>aim;
	bubble(11,s);
	cout<<"The result of midsearch: "<<midsearch(1,10,aim,s)<<endl;
	cout<<"The result of primery: "<<search(10,aim,s)<<endl;
	return 1;
}