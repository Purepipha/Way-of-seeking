// gs_BF.cpp -- 蛮力算法
#include <iostream>

int gs_BF(int A[], int n);

int main()
{
    int arr[6] = {1, -3, 6, 9, -5, 3};
    int max = gs_BF(arr, 6);
    std::cout << max << std::endl;
    return 0;
}

int gs_BF(int A[], int n)
{
    int gs = A[0];
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += A[k];
            gs = sum > gs ? sum : gs;
        }
    return gs;
}