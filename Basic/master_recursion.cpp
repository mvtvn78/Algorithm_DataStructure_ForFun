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
#define loop (i,c) for(int var = i ; var <=c ; ++var)
//Level 1
void Recursive(int arr[],int lid)
{
	cout<<arr[lid];
	if(lid!=0)
	{
		Recursive(arr,--lid);
	}
}
//Level 2 : BackTracking Pseudo Code
int X[100];
void BackTracking ( int i, int condition , int maxsize )
{
	//Loop through possibility
	for(int j = 0 ; j<=maxsize;j++)
	{
		// Accept possibility
		if(j==condition)
		{
			// Place j possibility into i
			X[i]= j;
			// Check completed condition
			if(i == maxsize) 
			{
				cout<<"Result "<<endl;
			}
			// Expand possibility
			else BackTracking(++i,condition,maxsize);
		}
	}
}
int main()
{
	int arr[]={1,2,3,4,5};
	Recursive(arr,4);
	
	return 0;
}