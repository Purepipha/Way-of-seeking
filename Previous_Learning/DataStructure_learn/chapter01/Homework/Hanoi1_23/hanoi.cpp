// hanoi塔问题
// 1-23
// 按照Hanoi规则，将柱子Sx上的n只盘子，借助Sy中转，移到Sz上
void hanoi(int n, Stack<Disk> & Sx, Stack<Disk> & Sy, Stack<Disk> & Sz)
{
    if (n > 0)
    { //没有盘子剩余时，不再递归
        hanoi(n - 1, Sx, Sz, Sy);   // 递归：将Sx上的n-1只盘子，借助Sz中转，移到Sy上
        move(Sx, Sy);   // 直接：将Sx上最后一只盘子，移到Sz上
        hanoi(n - 1, Sy, Sx, Sz); // 递归：将Sy上的n-1只盘子，借助Sx中转，移到Sz闪光
    }
}