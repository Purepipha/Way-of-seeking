#! /bin/bash
# aurthor: purepipha
# url: https://purepipha.github.io

echo "Simple function"
echo "--------------------------------"
Fun()
{
    echo "This is a function"
}

echo "----------函数开始执行----------"
Fun
echo "----------函数执行完毕----------"
echo "--------------------------------"

echo "A function with return"
echo "----------------------------------------------------"
function fun_With_Return()
{
    echo "计算两个数字相乘"
    echo "输入第一个数字: "
    read num1
    echo "输入第二个数字: "
    read num2
    echo "两个数字分别为 ${num1} 和 ${num2}"
    return $((${num1} \* ${num2}))
}
fun_With_Return
echo "两个数字的乘积为 $? !"
echo "----------------------------------------------------"

echo "A function with parameters"
echo "----------------------------------------------------"
function fun_With_Parameters() {
    echo "第一个参数为: $1"
    echo "第二个参数为: $2"
    echo "第三个参数为: $3"
    echo "第四个参数为: $4"
    echo "第十个参数为: $10"
    echo "参数的数目为: $#"
    echo "所有参数一行字符串表示: $*"
}
fun_With_Parameters 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
echo "----------------------------------------------------"

