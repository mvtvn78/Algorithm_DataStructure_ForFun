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
struct Node{
	int data;
	Node * pNext;
};
//Doubly LinkList
struct Node_Doubly {
	int data;
	Node * pNext;
	Node* pPrev;
};
//Circular LinkList
struct Node_Circular{
	int data;
	Node * pNext;
};
struct S_LinkList{
	Node *pHead;
	Node *pTail;
};
// Linked List Initialization
void Init(S_LinkList &a)
{
	a.pHead= NULL;
	a.pTail= NULL;
}
// isEmpty Method
bool isEmpty(const S_LinkList &b)
{
	return b.pHead == NULL;
}
// Make Node Method Definition
Node* MakeNode (int data)
{
	Node * t = new Node();
	t->data = data;
	t->pNext = NULL;
	return t;
}
// Make Node Method Definition
Node* FindElementNearTail (S_LinkList &r)
{
	Node * t = r.pHead;
	while(t->pNext != r.pTail)
		t= t->pNext;
	return t;

}
// Add to Head Definition
void Add_Head(S_LinkList &r,int data)
{
	Node * t = MakeNode(data);
	if(!t) cout<<"Warning : Memory full"<<endl;
	t->pNext = r.pHead;
	//Move point to real pHead, tail
	r.pHead = t;
	r.pTail = FindElementNearTail(r);
}
// Add to Tail Definition
Node*  Add_Tail(S_LinkList &r,int data)
{
	Node * t = MakeNode(data);
	if(!t) cout<<"Warning : Memory full"<<endl;
	//Move point to real pHead, tail
	if(!r.pHead)
	{
		r.pHead = t;
		r.pTail = t;
		return t;
	}
	r.pTail->pNext = t;
	r.pTail = t;
	return t;
}
// Defines an array traversal method
void Loop_Through_Item( const S_LinkList &l){
	Node *t = l.pHead;
	if(t) cout<<"An element in My Array\n";
	while(t)
	{
		cout<<t->data<<" ";
		t= t->pNext;
	}
	cout<<endl;
}
//Delete Head 

void Delete_Head( S_LinkList &r)
{
	if(!isEmpty(r))
	{
		Node * t = r.pHead;
		if(t == r.pTail)
			r.pTail= NULL;
		r.pHead = t->pNext;
		delete t;
	}
}

//Delete Tail
void Delete_Tail( S_LinkList &r)
{
	if(!isEmpty(r))
	{
		Node * t = r.pTail;
		if(t == r.pHead)
		{
			r.pHead= NULL;
			r.pTail=NULL;
			delete t;
			return;
		}
		r.pTail = FindElementNearTail(r);
		r.pTail->pNext =NULL;
		delete t;
	}
}
//Insert at the tail of node.
void InsertTail_Node (S_LinkList &k , Node *&position , Node *&value)
{
	Node * t = position->pNext;
	position->pNext = value;
	value->pNext = t;
}
//Insert at the head of node.
void InsertHead_Node (S_LinkList &k , Node *&position , Node *&value)
{
	if(position == k.pHead)
	{
		Add_Head(k,value->data);
		return;
	}
	Node * p = k.pHead;
	while(p->pNext != position)
			p= p->pNext;
	p->pNext = value;
	value->pNext = position;
}
void Reverse(S_LinkList &l)
{
	if(isEmpty(l))
		return;
	Node * prev = NULL;
	Node * curr = l.pHead;
	Node * next = l.pHead->pNext;
	l.pTail = l.pHead;
	while(next != NULL) 
	{
		Node * t = curr->pNext;
		curr->pNext = prev;
		prev = curr;
		curr = t;
		next = curr->pNext;
	}
	curr->pNext = prev;
	l.pHead = curr;
}
int main()
{
	S_LinkList ll;
	Init(ll);
	Node * t = Add_Tail(ll,2);
	Add_Tail(ll,3);
	Add_Tail(ll,4);
	Node * t2 = Add_Tail(ll,4);
	Add_Tail(ll,5);
	
//	Node * value = MakeNode(59);
//	InsertHead_Node(ll,t,value);
	Loop_Through_Item(ll);
	Reverse(ll);
	Loop_Through_Item(ll);
	return 0;
}