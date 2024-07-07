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
// isOperand Method
bool isOperand(char c)
{
	// get by Unicode : 0-9 
	return c >=48 && c<=58;
}
// getPostFix Method
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
				stack.push(e_cur); // empty push it into stack
			else
			{
				// get top element in stack
				char e_top = stack.top();
				if (e_cur == ')')
				{
					// loop until top element is '('
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
					//  current element priority less than  top elmenet in stack
					// move top element in stack to queue and add current element to stack
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
// stringCalculation Method
int stringCalculation(string postfix)
{
	stack<int> stack;
	for(int i = 0 ;i<postfix.size();++i)
	{
		char curr_element = postfix[i];
		if(isOperand(curr_element))
		{
			int num = curr_element - '0'; // convert char to int 
			stack.push(num);
		}
		else 
		{
			int b= stack.top(); // get top element
			stack.pop();
			int a= stack.top(); // get top element 
			stack.pop();
			int temp = 0;
			// switch to correct perform operation
			switch(curr_element)
			{
				case '+': 
					temp = a +b; 
				break;
				case '-': 
					temp = a -b;
				break;
				case '*': 
					temp = a *b;
				break;
				case '/': 
					temp = a /b;
				break;
			}
			stack.push(temp); // push result to top element in stack		
		}
	}
	return stack.top(); // result is top elmenet in stack
}
int main()
{
	///5*(7-4)+4*(5-3) : operand <10 and natural number
	string infix;
	cout << "Type your infix: ";
	cin >> infix;
	string postfix =getPostFix(infix);
	cout<< "Your Postfix : "<< postfix<<endl;
	cout<< "Your Result : "<<stringCalculation(postfix);
	return 0;
}