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
	if( x == '(')
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
// isOperator Method
bool isOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}
// checkNumber Method
bool isValidNumber (string input)
{
	if(input.size() == 0)
		return false;
	for(int i = input.size() -1 ; i>= 0 ; --i)
	{
		char c = input[i];
		if(!isOperand(c))
			return false;
	}
	return true;
}
// getIndexToGetOperand Method
int getIndexToGetOperand (string input , int begin_pos)
{
	int nextOperand = input.find("$",begin_pos);
	if(nextOperand != std::string::npos)
	{
		return nextOperand;
	}
	else
		return -1;
}
// getFormatOperandRecent Method
int getFormatOperandRecent (string input ,int idx_curr)
{
	int i = 0;
	int temp =-1;
	while(i != idx_curr)
	{
		if(input[i] == '$')  
			temp = i;
		i +=1;
	}
	return temp;
}
// Convert char to string Method
string convertChar(char c)
{
	string s(1,c);
	return s;
}
// getPostFix Method
string getPostFix(string infix)
{
	string result = "";
	stack<char> stack;
	queue<string> queue;
	//
	int i_got = 0;
	int size = infix.size();
	
	for(int i = 0 ; i < size;++i)
	{
		char e_cur = infix[i];
		int idx_l_operand = size;
		
		//cout<<"CURRRENT ELEEMNET "<< i << " UNICODE :"<<int(e_cur) <<" VALUE : "<<e_cur <<" IGOT : "<<i_got<<endl;
		
		// try get last operand
		if( idx_l_operand !=0  && infix[size-1] == ')' )
			idx_l_operand -=1;
		string last_operand = infix.substr(i_got,idx_l_operand- i_got);
		
		//cout<<"GET "<<idx_l_operand - i_got<<" VALUE"<<endl;
		
		if(isValidNumber(last_operand))
		{
			//cout<<last_operand<<"LAST OPERAND"<<endl;
			i =  i_got + (idx_l_operand- i_got);
			i_got = i--;
			// push last_operand if it appear
			queue.push("$"+last_operand);
		}
		if(isOperator(e_cur))
		{
			// Operand handle
			int size_len = i - i_got;
			string operand = infix.substr(i_got,size_len);
			
			//cout<<operand << " INDX : "<<i_got << "GET "<<size_len <<"Position"<<endl;
			
			i_got = i +1;
			// push operand into queue if can get it
			if(operand != "")
				queue.push("$"+operand);
			// Operator Handle
			if(stack.empty()) 
				stack.push(e_cur); // empty push it into stack
			else
			{
				char e_top = stack.top();
				if( precedence(e_cur) > precedence(e_top))
				{
					//cout << e_cur <<" ON TOP " << e_top<<endl;
					stack.push(e_cur);
				}
				else
				{
					// current element priority less than  top elmenet in stack
					// move top element in stack to queue and add current element to stack
					//cout << e_top <<" MOVE IT TO QUEUE "<<endl;
					//cout<<e_cur<<"STACK :"<<endl;
					queue.push(convertChar(e_top));
					stack.pop();
					stack.push(e_cur); 
				}
			}
		}
		else
		{
			if (e_cur == ')')
			{
				// Operand handle
				int size_len = i - i_got;
				string operand = infix.substr(i_got,size_len);
				//cout<<operand << " INDX : "<<i_got << "GET "<<size_len <<"Position"<<endl;
				i_got = i +1;
				// handle it for ')' last string
				if(operand != "")
					queue.push("$"+operand);
				
				// Operator Handle
				// get top element in stack
				char e_top = stack.top();
				// loop until top element is '('
				while(stack.top() != '(')
				{	
					queue.push(convertChar(stack.top()));
					//cout << stack.top() <<" MOVE IT TO QUEUE "<<endl;
					stack.pop();
				}
				// remove '('
				stack.pop();
			}
			else if ( e_cur=='(')
			{
				stack.push(e_cur);
				i_got +=1;
			}
		}
	}
	
//	//Loop while queue
	while(!queue.empty())
	{
		string t = queue.front();
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

//stringCalculation Method
int stringCalculation(string postfix)
{
	stack<int> stack;
	int size = postfix.size();
	for(int i = 0 ;i<size;++i)
	{
		char curr_element = postfix[i];
		//cout<<"INDEX "<<i<< "VALUE "<<curr_element<<endl;
		if(isOperator(curr_element))
		{
			// Operand Handle
			int indx_valid = getFormatOperandRecent(postfix,i);
			if(indx_valid!=-1)
			{
				string operand = postfix.substr(indx_valid+1,i - indx_valid -1);
				if(isValidNumber(operand))
				{
					int num = stoi(operand);
					stack.push(num);
				}
			}
			
			// Operator Handle
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
		else if(curr_element == '$')
		{
			int nextOperand = getIndexToGetOperand(postfix,i+1);
			string operand = postfix.substr(i+1,nextOperand - i-1);
			if(isValidNumber(operand))
			{
				int num = stoi(operand);
				stack.push(num);
				i +=nextOperand - i-1;
			}
		}
	}
	return stack.top(); // result is top elmenet in stack
}
int main()
{
	string infix; //Number have to be natural number not floating number
	cout << "Type your infix: ";
	cin >> infix;
	string postfix =getPostFix(infix);
	cout<< "Your Postfix : "<< postfix<<endl;
	cout<< "Your Result : "<<stringCalculation(postfix);
	return 0;
}