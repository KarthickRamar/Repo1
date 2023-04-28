/*The stringCopy function takes two arguments: a pointer to the destination string (dest) and a pointer to the source string (src). It uses a while loop to copy the contents of the source string to the destination string one character at a time. The loop continues until it reaches the end of the source string (indicated by the null character '\0').

In the main function, we declare an array source and a character array destination to store the strings. We then call stringCopy to copy the contents of source to destination. Finally, we print the contents of both strings to verify that the copy was successful.*/

#include <iostream>
#include <cstring>

using namespace std;

void stringCopy(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int main() {
    char source[] = "Hello, World!";
    char destination[20];

    stringCopy(destination, source);

    cout << "Source: " << source << endl;
    cout << "Destination: " << destination << endl;

    return 0;
}





