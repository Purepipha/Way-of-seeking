// gs_LS.cpp -- 蛮力算法
#include <iostream>

int gs_LS(int A[], int n);

int main()
{
    int arr[6] = {1, -3, 6, 9, -5, 3};
    int max = gs_LS(arr, 6);
    std::cout << max << std::endl;
    return 0;
}

int gs_LS(int A[], int n)
{
    int gs = A[0];
    int s = 0;
    int i = n;
    while (--i > 0)
    {
        s += A[i];
        gs = s > gs ? s : gs;
        if (s < 0)
            s = 0;
    }
    return gs;
}