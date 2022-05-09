// LSC_RDD.cpp -- 递归 + 减而治之 + 分而治之
#include <iostream>
#include <algorithm>
// 求A[0,m]与B[0,n]的最大公共子序列长度
int LCS_RDD(char A[], int m, char B[], int n);

int main()
{
    using namespace std;
    char cha[12] = "EDUCATIONAL";
    char chb[10] = "ADVANTAGE";
    int length = LCS_RDD(cha, 10, chb, 8);
    cout << length << endl;
    return 0;
}

int LCS_RDD(char A[],int m, char B[], int n)
{
    if (m < 0 || n < 0)
        return 0;
    if (A[m] == B[n])
        return LCS_RDD(A, m - 1, B, n - 1) + 1;
    else
        return std::max<int>(LCS_RDD(A, m - 1, B, n),
            LCS_RDD(A, m, B, n - 1));
}

