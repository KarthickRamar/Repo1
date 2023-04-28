/*================================================================================================
----------------------------------------------------------------------------------
VARIOUS WAYS OF PASSING FUNCTION AS ARGUMENT
----------------------------------------------------------------------------------
typedef int (*operation)(int, int)

void callback(int a, int b, operation funcOpr) {
	funcOpr(a, b);
}

void callback(int a, int b, int (*operation)(int, int)) {
	operation(a, b);
}

void callback(int a, int b, std::function<int(int, int)> operation) {
	operation(a, b);
}
==================================================================================================*/

#include <iostream>

// Define a callback function that takes an int as an argument and returns void
typedef void (*CallbackFunction)(int);

// A function that takes a callback function as an argument
void doSomething(CallbackFunction callback) {
    // Do some work...
    int result = 42;
    
    // Call the callback function with the result
    callback(result);
}

// A sample callback function that simply prints the result to the console
void printResult(int result) {
    std::cout << "The result is " << result << std::endl;
}

int main() {
    // Call doSomething with printResult as the callback function
    doSomething(printResult);
    
    return 0;
}
