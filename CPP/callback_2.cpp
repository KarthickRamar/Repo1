#include <iostream>
#include <functional>

using namespace std;

void performOperation(int x, int y, function<int(int, int)> operation) {
    int result = operation(x, y);
    cout << "Result: " << result << endl;
}

int add(int x, int y) {
    return x + y;
}

int subtract(int x, int y) {
    return x - y;
}

int main() {
    int x = 10;
    int y = 5;
    
    performOperation(x, y, add);
    performOperation(x, y, subtract);
    
    return 0;
}
