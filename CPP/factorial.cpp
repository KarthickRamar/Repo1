#include <iostream>
using namespace std;

int factorial(int n) {
	if(n == 0 || n == 1) { // base case
		return 1;
	} else { // recursive case
		return n * factorial(n-1);
	}
}

int main() {	
	int num;
	cout << "Enter a number: ";
	cin >> num;
	cout << "Factorial of " << num << " is " << factorial(num) << endl;
	return 0;
}