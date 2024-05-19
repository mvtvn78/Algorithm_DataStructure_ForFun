#include<iostream>
#define loop(i,c) for(int var =i ; var <=c ;++var) cout<<arr[var]<<" "; cout<<endl;
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
int arr []= {10,80,30,90,40,50,70};
int n = sizeof(arr)/sizeof(int);
void swap ( int & a ,int &b)
{
	int temp = b;
	b = a;
	a= temp;
}
int partition(int l , int r){
	loop(0,n-1);
	int pivot = r;
	int right = pivot-1;
	int left =l;
	while(true)
	{
	    while(arr[left] < arr[pivot])
	        ++left;
	    while(arr[right] > arr[pivot])
	        --right;
	    if(left < right)
	        {
	            swap(arr[left],arr[right]);
	            ++left;
	            --right;
	        }
	    else break;
	}
	swap(arr[left], arr[pivot]);
	return left;
}
void QuickSort(int left, int right)
{
	if(left<right)
	{
		int x = partition(left,right);
		QuickSort(left,x-1);
		QuickSort(x+1,right);
	}
}
int main()
{
	QuickSort(0,n-1);
	return 0;
}
