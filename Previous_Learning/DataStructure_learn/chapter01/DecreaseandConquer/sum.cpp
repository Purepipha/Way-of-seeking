#include <iostream>

int sum(int A[], int n);

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int result = sum(arr, 5);
    std::cout << result << std::endl;
    return 0;
}

int sum(int A[], int n)
{
    return n > 0 ? sum(A,n-1) + A[n-1] : 0;
}