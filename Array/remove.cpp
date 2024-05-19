#include<iostream>
#define MAX 100
#define loop(i,c) for(int var = i; var <=c ;++var) cout<< arr[var]<<" "; cout<<endl;
using namespace std;
/*

 .----------------.  .----------------.  .----------------. 
| .--------------. || .--------------. || .--------------. |
| | ____    ____ | || | ____   ____  | || |  _________   | |
| ||_   \  /   _|| || ||_  _| |_  _| | || | |  _   _  |  | |
| |  |   \/   |  | || |  \ \   / /   | || | |_/ | | \_|  | |
| |  | |\  /| |  | || |   \ \ / /    | || |     | |      | |
| | _| |_\/_| |_ | || |    \ ' /     | || |    _| |_     | |
| ||_____||_____|| || |     \_/      | || |   |_____|    | |
| |              | || |              | || |              | |
| '--------------' || '--------------' || '--------------' |
 '----------------'  '----------------'  '----------------' 


*/
int arr[MAX] ={1,2,3,4,5}; 
void RemoveByIndex(int index,int &length)
{
	if(index >= length)
		return;
	for(int i= index; i<length-1;i++)
	{
		arr[i] =arr[i+1];
	}
	length -=1;
}
void RemoveByValue(int value,int &length)
{
	for(int i =0;i<length;i++)
	{
		if(arr[i] == value)
			RemoveByIndex(i,length);
	}
}
int main() {
	
	int length = 5;
	cout<<"Array has been initialized"<<endl;
	loop(0,length-1)

	//remove by Value
	RemoveByValue(3,length);
	cout<<"Array element after deletion"<<endl;
	loop(0,length-1)
	
	//remove by Index
	RemoveByIndex(length-1,length);
	cout<<"Array element after deletion"<<endl;
	loop(0,length-1)
}