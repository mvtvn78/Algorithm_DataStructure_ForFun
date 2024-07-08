#include<bits/stdc++.h>
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

vector<string> arr(TABLE_SIZE,"");
//
int hashfunc(const string & key, int tableSize) {
	int hashVal = 0; 
	for (int i = 0; i < key.size(); i++) 
		hashVal += key[i]; 
	return hashVal % tableSize; 
}
void Add(const string &key, int tableSize)
{
	int index = hashfunc(key,tableSize);
	if(arr[index] == "")
		arr[index] = key;
}
int find(const string &key, int tableSize)
{
	int index = hashfunc(key,tableSize);
	if(arr[index] == "")
		return -1;
	return index;
}
int main()
{
	string key = "ABC";
	cout<< "Key : is in " <<find(key,TABLE_SIZE)<<endl;
	Add(key,TABLE_SIZE);
	cout<< "Key : is in " <<find(key,TABLE_SIZE)<<endl;
	return 0;
}