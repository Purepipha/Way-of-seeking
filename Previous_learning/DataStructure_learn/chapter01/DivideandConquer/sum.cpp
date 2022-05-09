#include <iostream>

int sum(int A[], int lo, int hi);

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int result = sum(arr, 0, 4);
    std::cout << result << "\n";
    return 0;
}

int sum(int A[], int lo, int hi)
{
    if(lo == hi)
        return A[lo];
    int mid = (lo + hi) >> 1;
    return sum(A, lo, mid) + sum(A, mid + 1, hi);
}