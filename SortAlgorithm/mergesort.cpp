#include<iostream>
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
#define loop(arrs,i,c) for(int var =i;var<=c;++var) cout<<arrs[var]<<" "; cout<<endl;
int arr1[]= {6,8,40,50};
int size1 = sizeof(arr1)/sizeof(int);
int arr2[]={2,9,10,12,66};
int size2 = sizeof(arr2)/sizeof(int);
//
int arr[] = {3,2,5,-2,3,399,8,10,55,20};
int n = sizeof(arr)/sizeof(int);
void Merge(int left ,int mid,int right){
	int sum = right - left + 1;
	int * narr = new int [sum];
	int d =0;
	int i = left;
	int j = mid+1;
	
	while(i<=mid && j<=right)
	{
		if(arr[i] > arr[j])
			narr[d++]= arr[j++];
		else 
			narr[d++]= arr[i++];
	}
	while(i<=mid)
	{
		narr[d++]= arr[i++];
	}
	while(j<=right)
	{
		narr[d++]= arr[j++];
	}
 	for(int idx = 0;idx<sum ;++idx)
	{
		arr[idx+left]= narr[idx];
	}
	
}
void MergeSort(int left,int right)
{
	if(left<right)
	{
		int mid = (left+right)/2;
		MergeSort(left,mid);
		MergeSort(mid+1,right);
		Merge(left,mid,right);
	}
}
int main() 
{
	MergeSort(0,n-1);
	loop(arr,0,n-1);
	return 0;
}