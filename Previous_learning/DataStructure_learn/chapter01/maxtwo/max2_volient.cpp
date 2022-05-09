// max2_volient.cpp --volient solution
#include <iostream>
void max2(int A[], int lo, int hi, int &x1, int &x2);

int main()
{
    int arr[6] = {3, 2, 6, 8, 4, 9};
    int x1, x2;
    max2(arr,0, 6, x1, x2);
    std::cout << arr[x1] << " " << arr[x2] << "\n";
    return 0;
}

void max2(int A[], int lo, int hi, int & x1, int &x2)
{
    x1 = lo;
    for (int i = lo + 1; i < hi; i++)   // 扫描A[lo,hi),得到x1;
        x1 = A[i] > A[x1] ? i : x1;
    x2 = lo;
    for (int i = lo + 1; i < x1; i++)   // 扫描A[lo,x1),得到[lo,x1)上的x2
        x2 = A[i] > A[x2] ? i : x2;
    for (int i = x1 + 1; i < hi; i++)   // 扫描A[x1+1,hi),得到x2
        x2 = A[i] > A[x2] ? i : x2;
}