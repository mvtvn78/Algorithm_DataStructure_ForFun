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
/*preprocessor include : 
	#define	: used to define a marco or constant
	#undef: used to undefined a marco
	#include : used to include a file in the source code program
	#ifdef : check define
	#ifndef : check define is not
	#if : check condition 
	#else :  excute when if fails
	#endif : used to mark the end of #if , #ifdef and #ifndef
*/
#define LIMIT 5;
#define MULT(a, b) (a * b)
#define loop(i,c) for(int var = i; var<=c ;++var)
int main()
{
	//Using marco
	int l1 = 10, l2 = 5, area;
    area = MULT(l1, l2);
    cout<<area;
    
	// using forloop by marco
    loop(2,4)
    cout<<"Hello"<<endl;
    
    
	return 0;
}