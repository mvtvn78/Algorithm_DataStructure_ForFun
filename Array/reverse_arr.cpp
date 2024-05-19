#include<iostream>
#define loop(i,c) for(int var =i ;var<=c;++var) cout<<arr[var]<<" "; cout<<endl;
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
void Reverse_Fill(int arr[],int n)
{
	int d =0;
	int b[n];
	for(int i =n-1 ;i >=0; --i)
		b[d++]= arr[i];
	for(int i =0;i<n;++i)
		arr[i] = b[i];
}
void swap(int &a,int &b)
{
	int temp = a;
	a= b;
	b= temp;
}
void Reverse_TwoPointer(int arr[],int n)
{
	int left = 0;
	int right = n-1;
	while(left<right)
	{
		swap(arr[left],arr[right]);
		++left;
		--right;
	}
}
int main()
{
	int arr[] ={1,2,3,4,5};
	int n = sizeof(arr)/ sizeof(int);
	loop(0,n-1);
	Reverse_Fill(arr,n);
	loop(0,n-1);
	Reverse_TwoPointer(arr,n);
	loop(0,n-1);
	return 0;
}