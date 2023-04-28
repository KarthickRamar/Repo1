#include <iostream>
using namespace std;

int interpolation_search(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while(left <= right && key >= arr[left] && key <= arr[right]) {
        int pos = left + ((key - arr[left]) * (right - left)) / (arr[right] - arr[left]);
        if(arr[pos] == key) {
            return pos;
        } else if(arr[pos] < key) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 3;
    int index = interpolation_search(arr, n, key);
    if(index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}
