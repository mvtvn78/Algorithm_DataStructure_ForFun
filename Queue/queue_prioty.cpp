#include<bits/stdc++.h>
#define MAX 100
using namespace std;
int arr[MAX];
int i_current=0;

//getTop Method
int getTop()
{
	return arr[0];
}
//isEmpty Method
bool isEmpty()
{
	return i_current==0;
}
//swap Method
void swap(int &a,int&b)
{
	int temp = b;
	b= a;
	a= temp;
}
//Partition Method
int Partition (int left,int right)
{
	int pivot = right;
	int r = pivot -1;
	int l = left;
	while(true)
	{
		while(arr[l]> arr[pivot])
			l++;
		while( arr[r] < arr[pivot])
			r--;
		if(l<r)
		{
			swap(arr[l],arr[r]);
			l++;
			r--;
		}
		else
			break;
	}
	swap(arr[l],arr[pivot]);
	return l;
}
//QuickSort Method
void QuickSort(int left,int right)
{
	if(left<right)
	{
		int par = Partition(left,right);
		QuickSort(left,par-1);
		QuickSort(par+1,right);
	}
}
//pop Method
void pop()
{
	for(int i =1 ; i< i_current;++i)
		arr[i-1]= arr[i];
	i_current--;
	if(isEmpty())
		arr[i_current]=-1;
}
//push Method
void push(int value)
{
	arr[i_current++]=value;
	QuickSort(0,i_current-1);
}

int main()
{
	memset(arr,-1,MAX);
	push(3);
	push(2);
	push(5);
	push(1);
	push(4);
	cout<<getTop()<<endl;
	pop();
	cout<<getTop()<<endl;
	return 0;
}