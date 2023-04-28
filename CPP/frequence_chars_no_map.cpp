#include <iostream>
#include <cstring>

using namespace std;

const int MAX_CHAR = 128; // Maximum number of characters in ASCII table

int main()
{
    char str[100];
    int freq[MAX_CHAR] = {0}; // Initialize frequency array to 0

    cout << "Enter a string: ";
    cin.getline(str, 100); // Reads utill the EOL
    //cin.read(str, 100);  // Reads 100 characters irrespective of EOL
    //cin >> str;          // Reads untill the space or EOL.

    int len = strlen(str);

    // Count frequency of each character in the string
    for (int i = 0; i < len; i++)
    {
        int ascii_val = (int) str[i];
        freq[ascii_val]++;
    }

    // Print frequency of each character
    cout << "Frequency of all characters in the string: " << endl;

    for (int i = 0; i < MAX_CHAR; i++)
    {
        if (freq[i] > 0)
        {
            cout << "'" << (char) i << "' occurs " << freq[i] << " times" << endl;
        }
    }

    return 0;
}
