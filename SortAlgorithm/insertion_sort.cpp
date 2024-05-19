#include<iostream>
#define loop(i,c) for(int var = i;var<=c;++var) cout<<arr[var]<<" "; cout<<endl;
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
int arr[] ={2,4,12,2325,24,12,1,-2};
int n = sizeof(arr)/sizeof(int);
//Alorithmic ideology

//1.Split two array : one has been sorted and another hasn't been sorted
//2.Insert the element array into sorted array with the correct index.
void InsertionSort(int arr [],int n)
{
	for(int i =1 ;i<n;++i)
	{
		int x = arr[i];
		int j= i-1;
		while(j >=0 && arr[j]> x)
		{
			arr[j+1]= arr[j];
			--j;
		}
		arr[++j]= x;
	}
}
int main()
{
	cout<<"Array "<<endl;
	loop(0,n-1)
	cout<<"Array has been Sorted"<<endl;
	InsertionSort(arr,n);
	loop(0,n-1);
	return 0;
}