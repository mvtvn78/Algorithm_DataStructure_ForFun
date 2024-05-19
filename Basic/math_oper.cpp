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
int main()
{
	// Math operator include : + , - , * , / , -- prefix , -- suffixes ,% Modulus
	//int 
	int a = 9;
	int b = 10;
	cout<<"Divides a by b "<< a/b<<endl; // OutPut : 0
	cout<<"Divides a by b "<< 9/10<<endl; // OutPut : 0
	//float
	cout<<"Divides a by b "<< 9.0/10<<endl; // OutPut : 0.9
	
	//Remainder
	cout<<"Remainder : "<<10%3 <<endl; // OutPut : 1
	cout<<"Remainder : "<<10%5 <<endl; // OutPut : 0
//	cout<<"Remainder : "<<10%0 <<endl; // OutPut : error
	cout<<"Remainder : "<<100%100 <<endl; // OutPut : 0
	cout<<"Remainder : "<<103%100 <<endl; // OutPut : 3
	// statement : (a % b) if a is less than b , result will a.
	cout<<"Remainder : "<<10%100 <<endl; // OutPut : 10
	
	// prefix and suffixes
	
	cout << a-- << b++ <<endl; // OutPut : 9 ,10
	cout << a++ << b<<endl; // OutPut : 8, 11
	cout << --a << ++b<<endl; // OutPut : 8 , 12
	cout << a+b <<endl; // OutPut : 20
	cout << a%b <<endl; // OutPut : 8
	cout << a++%b<<endl; // OutPut : 8
	
	
	return 0;
}