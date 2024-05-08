#include<iostream>
#define MAX 100
#define loop(i,c) for(int var = i; var <=c ;++var) cout<< arr[var]<<" ";
using namespace std;
int main() {
	int arr[MAX] ={1,2,3,4,5}; 
	int length = 5;
	cout<<"Array has been initialized"<<endl;
	loop(0,length-1)
	cout<<endl;
	
	//add tail
	cout<<"put element at the end of Array"<<endl;
	arr[length++] = 6;
	loop(0,length -1)
	cout<<endl;

	//add head
	cout<<"put element at the begin of Array"<<endl;
	for(int d = length -1 ; d>0;--d)
		arr[d] = arr[d-1];
	arr[0] = 7;
	
	loop(0,length-1)
}