void convert(Stack<char> & S, __int64_t n, int base){//十进制正整数n到base进制的转换(递归版)
    static char digit[] //0<n,1<base<=16，新机制下的数位符号，可视base的范围适当扩充
    = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    if (0 < n){//在有余数之前，反复
        S.push(digit[n % base]);//逆向记录当前最低位，再
        convert(S, n / base, base);//通过递归求得更高位
    }

}