#include<bits/stdc++.h>
using namespace std;

int main()
{
	string x = "2457892";
	string y = "12356789";
	string result ;
	int size_x = x.size() -1;
	int size_y = y.size() -1;
	bool flag = false;
	while(size_x!= -1 && size_y !=-1)
	{
		char c1 = x.at(size_x);
		char c2 = y.at(size_y);
		int num1 = c1 - '0';
		int num2 =c2 - '0';
		int sum = num1+ num2;
		if(flag)
			sum+=1;
		if(sum>=10)
			{
				flag= true;
				sum %=10;
			}
		else
			flag = false;
		
		result +=to_string(sum);
		size_x --;
		size_y--;
	}
	
	while(size_x != -1)
	{
		char c1 = x.at(size_x);
		int num1 =c1 - '0';
		int sum = num1 + 0;
		if(flag)
			sum+=1;
		if(sum>=10)
			{
				flag= true;
				sum %=10;
			}
		else
			flag = false;
		result +=to_string(sum);
		size_x--;
	}
	
	while(size_y != -1)
	{
		char c2 = y.at(size_y);
		int num2 =c2 - '0';
		int sum = 0 + num2;
		if(flag)
			sum+=1;
		if(sum>=10)
			{
				flag= true;
				sum %=10;
			}
		else
			flag = false;
		result +=to_string(sum);
		size_y--;
	}
	reverse(result.begin(), result.end()); 
	
	cout<<"Result : "<<result<<endl;
	return 0;
}