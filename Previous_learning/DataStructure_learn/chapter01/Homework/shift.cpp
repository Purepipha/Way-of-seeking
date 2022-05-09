// shift.cpp -- 数组循环左移算法
// 数据结构C++习题1-26
#include <iostream>
void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}
void reverse(int * A, int lo, int hi)
{ //数组倒置(多递归基递归版)
    if (lo < hi)
    {
        swap(A[lo], A[hi]);// 交换A[lo]和A[hi]
        reverse (A, lo + 1, hi - 1);// 递归倒置A(lo,hi)
    } //else隐含了两种递归基
} //O(hi - lo + 1)
int shift2(int * A, int n, int k)
{
    k %= n;
    reverse(A, 0, k);
    reverse(A, k, n - 1);
    reverse(A, 0, n - 1);
    return 3 * n;
}

int main()
{
    using namespace std;
    int arr[6] = {1,2,3,4,5,6};
    cout << "Before shift:" << endl;
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";
    cout << endl;
    int n = shift2(arr, 6, 2);
    cout << "After shift:" << endl;
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";
    cout << endl;
}