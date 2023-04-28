#include <iostream>
#include <cstring>

void reverseString(char* str) {
    char* start = str; //pointer to the start of the string
    char* end = str + strlen(str) - 1; //pointer to the end of the string
    while (start < end) { //swap characters until the middle of the string is reached
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main()
{
    reverseString("Hello");
    return 0;
}
