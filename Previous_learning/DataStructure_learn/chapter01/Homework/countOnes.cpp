// countOnes.cpp -- 统计整数二进制展开数中数位1的位数
#include <iostream>
#include <bitset>
int countOnes(unsigned int n)   // 复杂度O(log_2n)
{
    int ones = 0;
    while (n > 0)
    {
        ones += (n & 1);
        n >>= 1;
    }
    return ones;
// my code
    // do
    // {
    //     if (n & 1)
    //         ones++;
    // }while (n >>= 1);
    // return ones;
}
// 时间复杂度线性正比与1的实际数目
int countOnes1(unsigned int n)
{ // 统计整数二进制展开数中数位1的总数：O(ones)正比于数位1的总数
    int ones = 0;
    while (n > 0)
    { // 在n缩至0之前，反复地
        ones++; // 计数，至少有一位为1
        n &= n-1; // 清楚当前最靠右的1
    }
    return ones; // 返回计数
} // 等效于glibc的内置函数int _builtin_popcount(unsigned int n)

// 时间复杂度为O(log_2W), W = O(log_2n)为整数的位宽
#define POW(c) (1 << c) // 2^c
#define MASK(c) (((unsigned long) - 1) / (POW(POW(c)) + 1)) // 以2^c为单位分组，相间的全0和全1
// MASK(0) = 5555555555555555(h) = 01010101010101010101010101010101(b)
// MASK(1) = 3333333333333333(h) = 00110011001100110011001100110011(b)
// MASK(2) = f0f0f0f0f0f0f0f(h) = 00001111000011110000111100001111(b)
// MASK(3) = ff00ff00ff00ff(h) = 00000000111111110000000011111111(b)
// MASK(4) = ffff0000ffff(h) = 00000000000000001111111111111111(b)

// 输入：n的二进制展开中，以2^c为单位分组，各组数值已经分别等于原先这2^c位中1的数目
#define ROUND(n, c) (((n) & MASK(c)) + ((n) >> POW(c) & MASK(c))) // 运算优先级：先右移，在位与
// 过程：以2^c为单位分组，姓林的组亮亮捉对累加，累加值用原2^(c+1)位就地记录
// 输出：n的二进制展开中，以2^(c+1)位为单位分组，各组数值已经分别等于原先这2^(c + 1)位中1的数目
int countOnes2( unsigned int n)
{ // 统计整数n的二进制展开数中数位1的总数
    n = ROUND(n, 0); // 以02位为单位分组，各组内前01位与后01位累加，得到原先这02位中1的数目
    n = ROUND(n, 1); // 以04为为单位分组，各组内前02位与后02位累加，得到原先这04位中1的数目
    n = ROUND(n, 2); // 以08为为单位分组，各组内前04位与后04位累加，得到原先这08位中1的数目
    n = ROUND(n, 3); // 以16为为单位分组，各组内前08位与后08位累加，得到原先这16位中1的数目
    n = ROUND(n, 4); // 以32为为单位分组，各组内前16位与后16位累加，得到原先这32位中1的数目
    return n;
} // 32位字长时，O(log2_(32)) = O(5) = O(1)
int main()
{
    using namespace std;
    unsigned int num;
    cout << "Enter a unsigned integer: ";
    cin >> num;
    int ones = countOnes2(num);
    cout << num << " bit has "<< ones << " 1." << endl;
    cout << sizeof(unsigned int) << endl;
    // for (int i = 0; i < 5; i++)
    //     cout << "// MASK(" << i << ") = " << hex << MASK(i) << "(h)"
    //         << " = " << bitset<32>(MASK(i)) << "(b)" << endl;
    return 0;
}