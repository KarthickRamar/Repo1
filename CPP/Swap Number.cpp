#include <iostream>

using namespace std;

int main()
{
    int num1, num2;
    cin >> num1 >> num2;

    //Swap with a third variable
    int temp = num1;
    num1 = num2;
    num2 = temp;

    //swap withour third variable
    num1 = num1+num2;
    num2 = num1-num2;
    num1 = num1-num2;

    cout << num1 << num2;
}