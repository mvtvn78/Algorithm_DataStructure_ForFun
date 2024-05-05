#include<iostream>
#include<cmath>
using namespace std;
int main() 
{
	// loop in C can be divided into 3 types : for loop, while loop,do_while loop
	// for (intialization ; condition; updatecounter)
	// while(condition)
	// do {} while(condition)
	//Task 1: print 100 time Love
	//=============================================================================
	
//	for (int i =1 ; i<=100;++i)
//	{
//		cout<<i<<" Love"<<endl;
//	}
	
	
	//continue : this instruction can used to skip turn you want
	//Task 2 : print number is odd
	//=============================================================================
	
	
//	for(int i= 100;i<= 200;++i)
//	{
//		if(i%2 ==0)
//		{
//			continue;
//		}
//		cout<<i<<endl;
//	}
	
	//break : this instruction can used to exit the loop
	//Task 3 : Print all number if number is square number you have to exit loop
	//=============================================================================
	
	
//	for(int i= 2;i<= 200;++i)
//	{
//		int square = sqrt(i);
//		if(square*square ==i)
//		{
//			cout<<"Number is square number\nExit Loop\n";
//			break;
//		}
//		cout<<i<<endl;
//	}
	
//	/*OUTPUT : 
//	00 01 02 03 04 05 06 07 08 09
//	10 11 12 13 14 15 16 17 18 19
//	20 21 22 23 24 25 26 27 28 29
//	30 31 32 33 34 35 36 37 38 39
//	40 41 42 43 44 45 46 47 48 49
//	50 51 52 53 54 55 56 57 58 59
//	60 61 62 63 64 65 66 67 68 69
//	70 71 72 73 74 75 76 77 78 79
//	80 81 82 83 84 85 86 87 88 89
//	90 91 92 93 94 95 96 97 98 99
//	Matrix (10x10) : Maxtrix ten by ten
//	*/
//	for(int i =0;i<10;++i)
//	{
//		for(int j = 0 ;j<10;++j)
//		{
//			cout<<i<<j<<" ";
//		}
//		cout<<endl;
//	}
	
	
//	/*OUTPUT : 
//	10,0 10,1 10,2 10,3 10,4 10,5 10,6 10,7 10,8 10,9
//	90 91 92 93 94 95 96 97 98 99
//	80 81 82 83 84 85 86 87 88 89
//	70 71 72 73 74 75 76 77 78 79
//	60 61 62 63 64 65 66 67 68 69
//	50 51 52 53 54 55 56 57 58 59
//	40 41 42 43 44 45 46 47 48 49
//	30 31 32 33 34 35 36 37 38 39
//	20 21 22 23 24 25 26 27 28 29
//	10 11 12 13 14 15 16 17 18 19
//	00 01 02 03 04 05 06 07 08 09
//	=> NM,NM+1
//	=> N-1M,N-1M+1
//	Matrix (10x10) : Maxtrix ten by ten
//	*/
//	
//	for(int i =10;i>=0;--i)
//	{
//		for(int j = 0 ;j<10;++j)
//		{
//			cout<<i<<","<<j<<" ";
//		}
//		cout<<endl;
//	}
//	


	/*OUTPUT : 
	10,0 10,1 10,2 10,3 10,4 10,5 10,6 10,7 10,8 10,9
	90 91 92 93 94 95 96 97 98 99
	80 81 82 83 84 85 86 87 88 89
	70 71 72 73 74 75 76 77 78 79
	60 61 62 63 64 65 66 67 68 69
	50 51 52 53 54 55 56 57 58 59
	40 41 42 43 44 45 46 47 48 49
	30 31 32 33 34 35 36 37 38 39
	20 21 22 23 24 25 26 27 28 29
	10 11 12 13 14 15 16 17 18 19
	00 01 02 03 04 05 06 07 08 09
	=> NM,NM+1
	=> N-1M,N-1M+1
	Matrix (10x10) : Maxtrix ten by ten
	*/
	
	//LOOK INTO AND LOOK OUT
	//empty spaces : 3
	//lines : 13
	//O (N^3)
	
	//Rule :  3+1 + (3^2)
	
//	int count =0;
//	for(int i =0;i<3;++i)
//	{
//		for(int j = 0 ;j<3;++j)
//		{
//			for (int k = 0 ;k <3 ;++k)
//			{
//				cout<<i<<j<<k<<" ";
//				++count;
//			}
//			cout<<endl;
//		}
//		cout<<endl;
//	}
//	cout<<"O("<<count<<")"<<endl;
//	
	
	
	//LOOK INTO AND LOOK OUT
	//empty spaces : 3
	//lines : 41
	
	//Rule :  3+1 +  3* 12
	
//	int count =0;
//	
//	for(int i =0;i<3;++i)
//	{
//		for(int j = 0 ;j<3;++j)
//		{
//			for (int k = 0 ;k <3 ;++k)
//			{
//				for(int l = 0;l<3;++l)
//				{
//					cout<<i<<j<<k<<l<<" ";
//					++count;
//				}
//				cout<<endl;
//			}
//			cout<<endl;
//		}
//		cout<<endl;
//	}
  	//cout<<"O("<<count<<")"<<endl;
	return 0;	
}