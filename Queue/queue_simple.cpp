#include<bits/stdc++.h>
#define MAX 100
using namespace std;
int arr[MAX];
int i_current=0;
int getTop()
{
	return arr[0];
}
bool isEmpty()
{
	return i_current==0;
}
void pop()
{
	for(int i =1 ; i< i_current;++i)
		arr[i-1]= arr[i];
	i_current--;
	if(isEmpty())
		arr[i_current]=-1;
}
void push(int value)
{
	arr[i_current++]=value;
}

int main()
{
	memset(arr,-1,MAX);
	push(1);
	push(2);
	push(3);
	pop();
	pop();
	pop();
	cout<<getTop();
	return 0;
}