#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char str[100];
	cout << "Enter a string: ";
	cin.getline(str, 100);

	int len = strlen(str);
	for(int i = 0; i < len/2; i++)
	{
		char temp = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = temp;
	}

	cout << "Reversed string is: " << str << endl;
	return 0;
}