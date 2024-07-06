#include<bits/stdc++.h>
#include <stack>
#include <queue>
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

//Precendence Method
int precedence(char x)
{
	if (x == '(')
		return 0;
	if (x == '+' || x == '-')
		return 1 ;
	if (x == '*' || x =='/' || x == '%')
		return 2;
	return 3;
}
bool isOperand(char c)
{
	return c >=48 && c<=58;
}
string getPostFix(string infix)
{
	string result = "";
	stack<char> stack;
	queue<char> queue;
	for(int i = 0 ; i < infix.size();++i)
	{
		if(isOperand(infix[i]))
			queue.push(infix[i]);
		else
		{
			char e_cur = infix[i];
			if(stack.empty()) 
				stack.push(e_cur);
			else
			{
				char e_top = stack.top();
				if (e_cur == ')')
				{
					while(stack.top() != '(')
					{
						queue.push(stack.top());
						stack.pop();
					}
					// remove '('
					stack.pop();
				}
				else if ( e_cur=='(')
					stack.push(e_cur);
				else if( precedence(e_cur) >= precedence(e_top))
				{
					stack.push(e_cur);
				}
				else
				{
					queue.push(e_top);
					stack.pop();
					stack.push(e_cur);
				}
			}
		}
	}
	//Loop while queue
	while(!queue.empty())
	{
		char t = queue.front();
		result+=t;
		queue.pop();
	}
	//loop while stack
	while(!stack.empty())
	{
		char t = stack.top();
		result+=t;
		stack.pop();
	}
	return result;
}
void getUnicode(char c)
{
	cout<< int(c)<<endl;
}
int main()
{
	///5*(7-4)+4*(5-3) : operand <10
	string infix;
	cout << "Type your infix: ";
	cin >> infix;
	cout<< "Your Postfix :"<<getPostFix(infix);
	return 0;
}