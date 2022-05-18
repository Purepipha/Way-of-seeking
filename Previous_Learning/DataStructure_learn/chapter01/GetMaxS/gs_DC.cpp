// gs_DC.cpp -- 分治算法
#include <iostream>
#include <algorithm>

int gs_DC(int A[], int lo, int hi);

int main()
{
    int arr[6] = {1, -3, 6, 9, -5, 3};
    int max = gs_DC(arr, 0, 6);
    std::cout << max << std::endl;
    return 0;
}

int gs_DC(int A[], int lo, int hi)
{
    if (hi - lo < 2)
        return A[lo];
    int mid = (lo + hi) / 2;
    int gsL = A[mid - 1];
    int sL = 0;
    int i = mid;
    while (lo < i--)
        if (gsL < (sL += A[i]))
            gsL = sL;
    int gsR = A[mid];
    int sR = 0;
    int j = mid - 1;
    while (++j < hi)
        if (gsR < (sR += A[j]))
            gsR = sR;
    return std::max<int>(gsL + gsR, std::max<int>(gs_DC(A, lo, mid), gs_DC(A, mid, hi)));
}