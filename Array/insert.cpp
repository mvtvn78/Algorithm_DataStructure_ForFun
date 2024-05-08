#include<iostream>
#define MAX 100
#define loop(i,c) for(int var = i; var <=c ;++var) cout<< arr[var]<<" ";  cout<<endl;
int arr[MAX] ={1,2,3,4,5}; 
using namespace std;
void Insert(int idx,int value , int &length)
{
	if(idx >= length)
		return;
	for(int i = length; i> idx ; --i)
	{
		arr[i] = arr[i-1];
	}
	arr[idx]= value;
	++length;
}
int main() {
	int length = 5;
	cout<<"Array has been initialized"<<endl;
	loop(0,length-1)

	//insert
	Insert(2,69,length);
	Insert(0,0,length);
	loop(0,length-1)
}