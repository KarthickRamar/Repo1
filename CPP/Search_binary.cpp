#include <iostream>
#include <vector>

int binarySearch(std::vector<int>& arr, int left, int right, int x) {
  if (right >= left) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == x) {
      return mid;
    } else if (arr[mid] > x) {
      return binarySearch(arr, left, mid - 1, x);
    } else {
      return binarySearch(arr, mid + 1, right, x);
    }
  }
  return -1;
}

int main() {
  std::vector<int> arr = {2, 3, 4, 10, 40};
  int n = arr.size();
  int x = 10;
  int result = binarySearch(arr, 0, n - 1, x);
  (result == -1) ? std::cout << "Element is not present in array" << std::endl
                 : std::cout << "Element is present at index " << result << std::endl;
  return 0;
}
