// reverse.cpp -- two methods
#include <iostream>
void swap(int &a, int &b);
void reverse(int A[], int lo, int hi);

int main()
{
    int arr[5] = {1,2,3,4,5};
    reverse(arr,0,4);
    for (int i = 0; i < 5; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    return 0;
}

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void reverse(int A[], int lo, int hi)
{
    if(lo < hi)
    {
        swap(A[lo],A[hi]);
        reverse(A, lo+1,hi-1);
    }
}

// 迭代
// void reverse(int A[], int lo, int hi)
// {
//     while (lo < hi)
//         swap(A[lo++],A[hi--]);
// }
