// cut_rod.cpp -- using resursion
#include <iostream>
#include <algorithm>
int cut_rod(int p[], int n);
int main()
{
    using namespace std;
    int price[11] = {0,1,5,8,9,10,17,17,20,24,30};
    int max4 = cut_rod(price,9);
    cout << max4 << endl;
    return 0;
}
int cut_rod(int p[], int n)
{
    if (n == 0)
        return 0;
    int q = 0;
    for (int i = 1; i <= n; i++)
        q = std::max<int>(q,p[i] + cut_rod(p, n - i));
    return q;
}