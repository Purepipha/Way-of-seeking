#include "Vector.h"
#include "vector_bracket.h"
#include "vector_constructor_by_copying.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

int N = 100;
int main()
{
    using namespace std;
    srand(time(0));
    int arr1[N];
    for (int i = 0; i < N; i++)
        arr1[i] = (rand() % N);
    int arr2[N];
    for (int i = 0; i < N; i++)
        arr2[i] = (rand() % N);
    Vector<int> vi(arr1, N);
    clock_t start, end;
    start = clock();
    vi.mergesort(0, N);
    end = clock();
    cout << double(end - start) / CLOCKS_PER_SEC << endl;
    for(int i = 0; i < N; i++)
        cout << vi[i] << " ";
    cout << endl;
// improve mergesort
    Vector<int> vi2(arr2, N);
    start = clock();
    vi2.mergesort_improve(0, N);
    end = clock();
    cout << double(end - start) / CLOCKS_PER_SEC << endl;
    for(int i = 0; i < N; i++)
        cout << vi2[i] << " ";
    cout << endl;
    return 0;
}