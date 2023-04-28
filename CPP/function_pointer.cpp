#include <iostream>

using namespace std;

typedef int (*MathFuncPtr)(int, int);

// Function that adds two integers
int AddFunc(int a, int b)
{
    return a + b;
}

// A function that takes two integers and returns their sum
int add(int a, int b) {
    return a + b;
}

// A function that takes two integers and returns their difference
int subtract(int a, int b) {
    return a - b;
}

int multiply(int x, int y) 
{ 
    printf("%d", x*y); 
}

// A function that takes two integers and a pointer to a function that
// takes two integers and returns an integer. The function uses the
// function pointer to perform the operation specified by the caller.
int operate(int a, int b, int (*operation)(int, int)) {
    return operation(a, b);
}

int main() {
    int a = 10, b = 5;

    // Declare a function pointer to the add function
    int (*add_ptr)(int, int) = &add;

    // Call the operate function with the add function pointer
    int sum = operate(a, b, add_ptr);
    cout << "Sum: " << sum << endl;

    // Declare a function pointer to the subtract function
    int (*subtract_ptr)(int, int) = &subtract;

    // Call the operate function with the subtract function pointer
    int difference = operate(a, b, subtract_ptr);
    cout << "Difference: " << difference << endl;

    // Declare and initialize a pointer to a function that adds two integers
    MathFuncPtr pFunc = &AddFunc;

    // Call the function pointed to by pFunc to add the two integers
    int result = pFunc(a, b);

    // Output the result
    std::cout << "The sum of " << a << " and " << b << " is " << result << std::endl;

    int (*pArr[])(int, int) = {add, subtract, multiply}; 
    unsigned int c, a = 15, b = 10; 
  
    printf("(0) Add, (1) Subtract, (2) Multiply"); 
    scanf("%d", &c); 
 
    cout << (*pArr[c])(a, b);

    return 0;
}