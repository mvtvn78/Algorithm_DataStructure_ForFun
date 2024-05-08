#include<iostream>
#define loop(i,c) for(int var = i;var<=c;++var) cout<<arr[var]<<" "; cout<<endl;
using namespace std;
int arr[] ={2,4,12,2325,24,12,1,-2};
int n = sizeof(arr)/sizeof(int);

void SelectionSort(int arr [],int n)
{
	for(int i =0 ;i<n;++i)
	{
		int min_idx = i;
		for(int j =i+1; j<n;++j)
		{
			if(arr[j] < arr[min_idx])
				min_idx = j;
		}
		if(min_idx!= i)
		{
			int temp = arr[min_idx];
			arr[min_idx]= arr[i];
			arr[i]= temp;
		}
	}
}
int main()
{
	cout<<"Array "<<endl;
	loop(0,n-1)
	cout<<"Array has been Sorted"<<endl;
	SelectionSort(arr,n);
	loop(0,n-1);
	return 0;
}