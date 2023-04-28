//Passing array as a pointer:
void myFunction(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

//Passing array by reference:
void myFunction2(int (&arr)[5]) {
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}

//Passing array using a pointer to an array:
void myFunction3(int (*arr)[5]) {
    for (int i = 0; i < 5; i++) {
        cout << (*arr)[i] << " ";
    }
}

//Passing array using a reference to an array:
void myFunction4(int (&arr)[5]) {
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}

//Passing as an array itself
void myFunction5(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    myFunction(arr, size);

    int arr2[] = {1, 2, 3, 4, 5};
    myFunction2(arr2);

    int arr3[] = {1, 2, 3, 4, 5};
    int (*ptr)[5] = &arr3;
    myFunction3(ptr);

    int arr4[] = {1, 2, 3, 4, 5};
    int (&ref)[5] = arr4;
    myFunction4(ref);

    int arr5[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr5) / sizeof(arr5[0]);
    myFunction5(arr5, n);

    
}

/*In all the above examples, the function myFunction accepts an array as a parameter and then iterates through the array and prints out each element. The first example passes the array as a pointer, the second example passes it by reference, the third example passes it using a pointer to an array, and the fourth example passes it using a reference to an array*/