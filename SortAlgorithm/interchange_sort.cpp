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
int arr[] ={2,4,2325,24,12,1,-2};
int n = sizeof(arr)/sizeof(int);
void Interchange_Sort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j = i+1;j<n;j++)
		{
			if(arr[j]< arr[i])
			{
				int temp = arr[i];
				arr[i]= arr[j];
				arr[j]= temp;
			}
		}
	}
}
int main()
{
	cout<<"Array "<<endl;
	loop(0,n-1)
	cout<<"Array has been Sorted"<<endl;
	Interchange_Sort(arr,n);
	loop(0,n-1);
	return 0;
}