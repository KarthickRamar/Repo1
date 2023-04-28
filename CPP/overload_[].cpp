/*
The overloaded [] operator in C++ typically returns a reference to the element being accessed in an array-like object.This is because returning a reference allows the user to modify the element directly, rather than creating a copy of the element and returning that copy, which would be less efficient.

In the case of the below C++ program, which defines a class MyArray that simulates an array of integers, the overloaded [] operator returns an int& reference to the element being accessed. This allows the user to modify the element in the MyArray object by assigning a new value to the reference.

For example, suppose we have a MyArray object arr and we want to modify the value of the element at index i using the overloaded [] operator. We can do this as follows:

arr[i] = newValue;
If the [] operator had returned an int instead of an int&, we would not be able to modify the value of the element in arr, since we would only have a copy of the element's value, rather than a reference to the element itself.
*/

#include <iostream>
using namespace std;

class Array {
  private:
    int arr[5];

  public:
    Array() {
        for (int i = 0; i < 5; i++) {
            arr[i] = 0;
        }
    }

    // Overloaded [] operator
    int& operator[](int index) {
        if (index < 0 || index >= 5) {
            cout << "Index out of bounds" << endl;
            // Return first element if index is out of bounds
            return arr[0];
        }
        return arr[index];
    }
};

int main() {
    Array a;

    // Set values using [] operator
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;

    // Access values using [] operator
    cout << a[0] << endl;
    cout << a[1] << endl;
    cout << a[2] << endl;
    cout << a[3] << endl;
    cout << a[4] << endl;

    // Access out-of-bounds index
    cout << a[5] << endl;

    return 0;
}
