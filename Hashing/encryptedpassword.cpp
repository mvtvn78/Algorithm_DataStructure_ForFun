#include<bits/stdc++.h>
#include <sstream>
#define TABLE_SIZE 100
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

// isNumber Method
bool isNumber(char c)
{
	// get by Unicode : 0-9 
	return c >=48 && c<=58;
}
//
char getSecretCharByNum(const int &num)
{
	switch (num) 
	{
		case 10:  return 'M';
		case 11 :  return 'V';
		case 12 :  return 'T';
		case 13 : return 'm';
		case 14 : return 'v';
		case 15 : return 't';
		case 16 : return 'A';
		case 17 : return 'B';
		case 18 : return 'C';
		case 19 : return 'D';
		case 20 : return 'E';
		default : return  num + '0';
	}
}

//
int getSecretCharByChar(char c)
{
	switch(c)
	{
		case 'M' : return 10;
		case 'V' : return 11;
		case 'T': return 12;
		case 'm' : return 13;
		case 'v' : return  14;
		case 't' : return  15;
		case 'A' : return  16;
		case 'B': return  17;
		case 'C' : return  18;
		case 'D' : return  19;
		case 'E' : return  20;
		default : return -1;
	}
}

// 
char getFormatHex(int num)
{
	switch (num) 
	{
		case 10:  return 'a';
		case 11 :  return 'b';
		case 12 :  return 'c';
		case 13 : return 'd';
		case 14 : return 'e';
		case 15 : return 'f';
		default : return  num + '0';
	}
}
//Encryted Method
string encode(const string &password)
{
	ostringstream os;
    for (int i=0; i<password.length() ; i++)
        os << hex  << (int) password[i];
    // get hex
    string hexdat = os.str();
    for(int i =0 ;i< hexdat.length();++i)
    {
    	if(isNumber(hexdat[i]))
    	{
    		int num = hexdat[i] - '0';
    		num+=5;
			hexdat[i] = getSecretCharByNum(num);
		}
	}
	return hexdat;
}

std::string hexToString(const std::string& hex) {
    int len = hex.length();
    std::string newString;
    for (int i = 0; i < len; i += 2) {
        std::string byte = hex.substr(i, 2);
        char chr = static_cast<char>(std::strtol(byte.c_str(), nullptr, 16));
        newString.push_back(chr);
    }
    return newString;
}

//Decryted Method
string decode  (const string & encryted_pass)
{
	string decryted_string = "";
	int num_curr =0;
	for(int i =0 ;i< encryted_pass.length();++i)
    {
    	char current = encryted_pass[i];
    	num_curr = current - '0';
    	int getSpecialChar = getSecretCharByChar(current);
    	if(getSpecialChar != -1)
    	{
    		num_curr = getSpecialChar;
    		num_curr -=5;
    		decryted_string += getFormatHex(num_curr);
    		continue;
		}
		else if (isNumber(current))
		{
			num_curr -=5;
			decryted_string += num_curr + '0';
			continue;
		}
		decryted_string += getFormatHex(num_curr);
	}
	string result = hexToString(decryted_string);
	return result;
}
int main()
{
	string password=  "thangchonguyenthanhlau";
	string encode_pass = encode(password);
	cout << "ENCODE " <<  encode_pass <<endl;
	cout << "DECODE " << decode(encode_pass) <<endl;
	return 0;
}