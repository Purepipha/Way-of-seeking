template <typename T>
struct Hailstone
{// 函数对象：按照Hailstone规则转化为一个T类对象
    virtual void operator() (T & e)
    {// 假设T可直接做算数运算
        int steps = 0;
        while (1 != e)
        { // 奇、偶逐步转换，直至为一
            (e & 1) ? e = 3 * e + 1 : e /= 2;
            steps++;
        }
        e = steps;//返回转换所经步数
    }
};