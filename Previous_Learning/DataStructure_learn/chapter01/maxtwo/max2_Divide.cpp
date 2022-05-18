// max2_Divede.cpp --DivideadnConque
#include <iostream>
void swap(int &a, int &b);
void max2(int A[], int lo, int hi, int &x1, int &x2);

int main()
{
    int arr[6] = {3, 2, 6, 8, 4, 9};
    int x1, x2;
    max2(arr,0, 6, x1, x2);
    std::cout << arr[x1] << " " << arr[x2] << "\n";
    return 0;
}

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void max2(int A[], int lo, int hi, int & x1, int &x2)
{
    if (lo + 2 == hi)
    {
        A[lo] > A[lo + 1] ? x1 = lo, x2 = lo+1 : x1 = lo + 1, x2 = lo;
        return;
    }
    if (lo + 3 == hi)   // 关系
    {
        if (A[x1 = lo] < A[x2 = lo + 1])
        {
            swap(x1, x2);
        }
        if (A[lo + 2] > A[x2])
        {
            if (A[x1] < A[x2 = lo + 2])
                swap(x1,x2);
        }
        return;
    }
    int mid = (lo + hi)/2;
    int x1L,x2L;
    max2(A, lo, mid, x1L, x2L);
    int x1R,x2R;
    max2(A, mid, hi, x1R, x2R); // 区间是开区间
    if (A[x1L] > A[x1R])
    {
        x1 = x1L;
        if (A[x1R] > A[x2L])
            x2 = x1R;
        else
            x2 = x2L;
    }
    else
    {
        x1 = x1R;
        if (A[x1L] > A[x2R])
            x2 = x1L;
        else
            x2 = x2R;
    }
}