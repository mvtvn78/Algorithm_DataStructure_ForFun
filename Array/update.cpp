#include<iostream>
#define MAX 100
#define loop(i,c) for(int var = i; var <=c ;++var) cout<< arr[var]<<" ";  cout<<endl;
int arr[MAX] ={1,2,3,4,5}; 
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
void Update(int idx,int value , int length)
{
	if(idx >= length)
		return;
	arr[idx]= value;
}
int main() {
	int length = 5;
	cout<<"Array has been initialized"<<endl;
	loop(0,length-1)

	//insert
	Update(1,69,length);
	Update(2,76,length);
	loop(0,length-1)
}