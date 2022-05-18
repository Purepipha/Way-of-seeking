// gs_IC.cpp -- 递增算法
#include <iostream>

int gs_IC(int A[], int n);

int main()
{
    int arr[6] = {1, -3, 6, 9, -5, 3};
    int max = gs_IC(arr, 6);
    std::cout << max << std::endl;
    return 0;
}

int gs_IC(int A[], int n)
{
    int gs = A[0];
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += A[j];
            gs = sum > gs ? sum : gs;       // 每次都需要判断，而不是最后判断一次
        }
    }
    return gs;
}