#include<iostream>
#define MAXSIZE 100
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
int main() 
{
	//Syntax : <data_type> name_arr [SIZE];
	//Syntax : <data_type> name_arr [SIZE] = {element1 , element2,...}
	//This way doesn't initializes elements. All element will be get garbage value
	int a[MAXSIZE];
	//This way initializes 5 elements in b array.Rest of them is zero
	int b[MAXSIZE] = {1,2,3,4,5};
	
	return 0;	
}