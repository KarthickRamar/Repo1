#include <iostream>
#include <unordered_map>

using namespace std;

void printFrequency(string str) {
    unordered_map<char, int> freq; // create an empty unordered_map

    // iterate through each character in the string
    for (char c : str) {
        freq[c]++; // increment the frequency of the character
    }

    // print the frequency of each character
    for (auto it = freq.begin(); it != freq.end(); it++) {
        cout << "'" << it->first << "': " << it->second << endl;
    }
}

int main() {
    string str = "hello, world!";
    printFrequency(str);
    return 0;
}
