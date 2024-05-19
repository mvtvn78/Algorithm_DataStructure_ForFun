#include<iostream>
#define MAX 100
#define loop(i,c) for(int var = i; var <=c ;++var) cout<< arr[var]<<" ";  cout<<endl;
int arr[MAX] ={1,2,3,4,5,6,7};
int length = 7;
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
int Bin_Search(int value,int length)
{
	int left = 0;
	int right = length -1;
	// '=' equal sign meaning : occur when mid element is right pointer. 
	while(left <= right)
	{
		int mid = (left+ right)/2;
		if(arr[mid]> value)
		{
			right = mid-1;
		}
		else if( arr[mid]<value)
		{
			left = mid +1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
int main() {
	//Condition is Array have to sort by Ascending
	cout<<"Array"<<endl;
	loop(0,length-1)
	cout<<"Find"<<Bin_Search(4,length);
}