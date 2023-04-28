#include <iostream>

char* copyString(const char* str) {
    // Calculate the length of the input string
    int len = 0;
    const char* p = str;
    while (*p != '\0') {
        ++len;
        ++p;
    }
    
    // Allocate memory for the copied string
    char* copiedStr = new char[len + 1];  // +1 for the null terminator
    
    // Copy the string using pointers
    p = str;
    char* q = copiedStr;
    while (*p != '\0') {
        *q = *p;
        ++p;
        ++q;
    }
    *q = '\0';  // Add the null terminator to the end of the copied string
    
    // Return the copied string
    return copiedStr;
}

int main() {
    const char* str = "Hello, world!";
    char* copiedStr = copyString(str);
    
    std::cout << copiedStr << std::endl;  // Output: Hello, world!
    
    delete[] copiedStr;  // Remember to free the memory
    
    return 0;
}