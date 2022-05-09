#include <iostream>
#include <algorithm>
void swap(int &a, int &b);  // swap a and b
void bubblesort(int ar[], int n);   // sort ar
int main()
{
    int arr[5] = {9,5,4,6,7};
    bubblesort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
void swap(int &a, int &b)
{
    int temp;
    temp = b;
    b = a;
    a = temp;
}
void bubblesort(int ar[], int n)
{
    for (bool sorted = false; sorted = !sorted; n--)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (ar[i] > ar[i+1])
            {
                swap(ar[i],ar[i+1]);
                sorted = false;
            }
        }
    }
}