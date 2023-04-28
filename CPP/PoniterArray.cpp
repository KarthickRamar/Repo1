/*
*ptr[] is an array of pointers. It declares an array of pointers to a particular type, where each element in the array is a pointer to that type. For example, int *ptr[5] declares an array of five pointers to integers. You can access each element of the array using the subscript operator [], like ptr[0], ptr[1], and so on.

On the other hand, (*ptr)[] is a pointer to an array. It declares a pointer to an array of a particular type. For example, int (*ptr)[5] declares a pointer to an array of five integers. You can access the elements of the array using the pointer and the subscript operator [], like (*ptr)[0], (*ptr)[1], and so on.
*/

#include <iostream>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    //Array of pointers
    int *ptr1[5] = {&arr[0], &arr[1], &arr[2], &arr[3], &arr[4]};
    std::cout << *ptr1[0] << " " << *ptr1[1] << " " << *ptr1[2] << " " << *ptr1[3] << " " << *ptr1[4] << std::endl;

    //Pointer to array
    int (*ptr2)[5] = &arr;
    std::cout << (*ptr2)[0] << " " << (*ptr2)[1] << " " << (*ptr2)[2] << " " << (*ptr2)[3] << " " << (*ptr2)[4] << std::endl;

    return 0;
}
