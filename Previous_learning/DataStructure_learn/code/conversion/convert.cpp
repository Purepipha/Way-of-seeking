void convert(Stack<char>& S, __int64_t n, int base){//进制转换
    static char digit[] //0<n,1<base<=16，新机制下的数位符号，可视base的范围适当扩充
    = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (n > 0){//由低到高，逐一计算出新进制下的数位
        S.push(digit[n % base]);//余数位入栈
        n /= base;//更新n
    }
}