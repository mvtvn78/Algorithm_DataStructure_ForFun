#include<bits/stdc++.h>
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
//Node Structure
struct Node
{
	int data;
	Node *pLeft;
	Node *pRight;
};
//Change the name from Node* to TREE
typedef Node* TREE;
Node* MakeNode(int data);
void Init(TREE & t);
void AddElement(TREE & t,int data);
bool isEmpty(TREE & t);
void NLR(const TREE &t);
void NRL(const TREE &t);
void LNR(const TREE &t);
void LRN(const TREE &t);
void RNL(const TREE &t);
void RLN(const TREE &t);
bool Contain(const TREE &t,int value);
int main(){
	TREE tt;
	Init(tt);
	AddElement(tt,3);
	AddElement(tt,1);
	AddElement(tt,5);
	AddElement(tt,4);
	AddElement(tt,2);
	AddElement(tt,2);
	AddElement(tt,-2);
	AddElement(tt,6);
	cout<<"NLR "<<endl;
	NLR(tt);
	cout<<endl<<"NRL "<<endl;
	NRL(tt);
	cout<<endl<<"LNR "<<endl;
	LNR(tt);
	cout<<endl<<"LRN "<<endl;
	LRN(tt);
	cout<<endl<<"RNL "<<endl;
	RNL(tt);
	cout<<endl<<"RLN "<<endl;
	RLN(tt);
	if(Contain(tt,-1))
	{
		cout<<endl<<"Element has value -1 is contained"<<endl;	
	}
	else 
	{
		cout<<endl<<"Element has value -1 is not contained"<<endl;	
	}
	if(Contain(tt,-2))
	{
		cout<<endl<<"Element has value -2 is contained"<<endl;	
	}
	else 
	{
		cout<<endl<<"Element has value -2 is not contained"<<endl;	
	}
	if(Contain(tt,4))
	{
		cout<<endl<<"Element has value 4 is contained"<<endl;	
	}
	else 
	{
		cout<<endl<<"Element has value 4 is not contained"<<endl;	
	}
	return 0;
}
void Init(TREE & t)
{
	t = NULL;
}
Node* MakeNode(int data) {
	Node * t = new Node;
	if(!t) return NULL;
	t->data = data;
	t->pLeft = NULL;
	t->pRight = NULL;
	return t;
}
void AddElement(TREE & t,int data)
{
	if(t)
	{
		if(t->data > data)
			AddElement(t->pLeft,data);
		else 
			AddElement(t->pRight,data);
		return;
	}
	t = MakeNode(data);
}
bool isEmpty(TREE & t)
{
	return t==NULL;
}
void NLR(const TREE &t)
{
	if(t)
	{
		cout<<t->data<<" ";
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}
void NRL(const TREE &t)
{
	if(t)
	{
		cout<<t->data<<" ";
		NRL(t->pRight);
		NRL(t->pLeft);
	}
}
void LNR(const TREE &t)
{
	if(t)
	{
		LNR(t->pLeft);
		cout<<t->data<<" ";
		LNR(t->pRight);
	}
}
void LRN(const TREE &t)
{
	if(t)
	{
		LRN(t->pLeft);
		LRN(t->pRight);
		cout<<t->data<<" ";
	}
}
void RNL(const TREE &t)
{
	if(t)
	{
		RNL(t->pRight);
		cout<<t->data<<" ";
		RNL(t->pLeft);
	}
}
void RLN(const TREE &t)
{
	if(t)
	{
		RLN(t->pRight);
		RLN(t->pLeft);
		cout<<t->data<<" ";
	}
}
bool Contain(const TREE &t,int value)
{
	if(t)
	{
		if(t->data > value)
		{
			return Contain(t->pLeft,value);	
		}
		else if(t->data< value)
		{
			return Contain(t->pRight,value);
		}
		else
		{
			return true;
		}
	}
	return false;
}