#include<iostream>
#include<cstdlib>
#define MAXSIZE 100
using namespace std;
void addRandomElement(int arr[], int length) {
	for(int i =0;i<length;++i)
	{
		// element get value with range from 10 to 500
		arr[i] = rand() % (500-10+1)+10; 
	}
	cout<<"Initialization Successful\n";
}
void loopThroughArr(int arr[], int length)
{
	for(int i=0;i<length;++i)
	{
		cout<< arr[i]<<" ";
	}
}
int main() 
{
	int b[MAXSIZE] ;
	addRandomElement(b,MAXSIZE);
	loopThroughArr(b,MAXSIZE);
	return 0;	
}