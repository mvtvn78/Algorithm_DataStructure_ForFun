#include<bits/stdc++.h>
using namespace std;
int arr2d[3][3];
// initArray2d Method
void initArray2d()
{
	for(int i = 0 ; i< 3;++i)
	{
		for(int j= 0 ;j<3;++j)
		{
			arr2d[i][j] = 0;
			if(j==0)	
				arr2d[i][j]=i+1;
		}
	}
}
// printArr2d Method
void printArr2d()
{
	for(int i = 0 ; i< 3;++i)
	{
		for(int j = 0 ;j<3;++j)
			cout<<"\t"<<arr2d[i][j] <<" ";
		cout<<endl;
	}
	cout<<endl;
}
// getIndexValid Method
int getIndexValid(int id_col)
{
	// return index row of array 2d
	for(int i =0 ;i<3;++i)
		if(arr2d[i][id_col]!=0)
			return i;
	return -1;
}
// getLastIndexValid Method
int getLastIndexValid(int id_col)
{
	// return index row of array 2d
	int idxlast =0;
	for(int i =0 ;i<3;++i)
		if(arr2d[i][id_col]==0)
			idxlast = i;
	return idxlast;
}
void hanoiTower(int amount,int id_col_origin,int id_col_aux,int id_col_des)
{
	if(amount ==0)
		return;
	//origin to intermediary
	hanoiTower(amount-1,id_col_origin,id_col_des,id_col_aux);
	//handle one disk case
	int indexOrigin = getIndexValid(id_col_origin);
	int indexDestination = getLastIndexValid(id_col_des);
	if(indexOrigin!= -1)
	{
		cout<<"\t\tMOVE 1 DISK from "<< id_col_origin <<" to "<< id_col_des<<endl;
		arr2d[indexDestination][id_col_des] = arr2d[indexOrigin][id_col_origin];
		arr2d[indexOrigin][id_col_origin] =0;
		printArr2d();
	}
	//intermediary to destination
	hanoiTower(amount-1,id_col_aux,id_col_origin,id_col_des);
}
void easyMethod(int amount , char origin,char aux,char des)
{
	if(amount==0)
		return;
	//origin to intermediary
	easyMethod(amount-1,origin,des,aux);
	//handle one disk case
	cout<<"\t\tMOVE 1 DISK from "<< origin <<" to "<< des<<endl;
	//intermediary to destination
	easyMethod(amount-1,aux,origin,des);
}
int main()
{
	initArray2d();
	hanoiTower(3,0,1,2);
	easyMethod(3,'A','B','C');
	return 0;	
}