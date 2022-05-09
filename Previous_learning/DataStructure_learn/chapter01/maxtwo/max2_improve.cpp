// max2_improve.cpp --improve solution
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
    A[lo] > A[lo+1]? x1 = lo, x2 = lo + 1 : x1 = lo + 1, x2 = lo;
    for (int i = lo + 2; i < hi; i++)
    {
        if (A[i] > A[x2])
        {
            x2 = i;
            if (A[x2] > A[x1])
                swap(x1,x2);
        }
    }

}