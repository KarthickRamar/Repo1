#include <iostream>
#include <cstring>

void reverseString(char* str) {
    int len = strlen(str);
    for(int i = 0; i < len/2; i++) {
        char temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
}

int main() {
    char str[] = "Hello, world!";
    std::cout << "Original string: " << str << std::endl;
    reverseString(str);
    std::cout << "Reversed string: " << str << std::endl;
    return 0;
}
