#! /bin/bash
# aurthor: purepipha
# url: https://purepipha.github.io

echo "Value test"
echo "--------------------------------"
num1=10
num2=20

if test $[num1] -eq $[num2];then
    echo "两个数相等"
else
    echo "两个数不相等"
fi
echo "--------------------------------"

echo "[] calculate the basic calculation"
echo "----------------------------------------------------"
a=5
b=10
result=$[a + b]
echo "result = $result"
echo "----------------------------------------------------"

echo "String test"
echo "----------------------------------------------------"
name1="auroa"
name2="luroa"
if test $name1 = $name2;then
    echo "两个字符串相等"
else
    echo "两个字符串不相等"
fi
echo "----------------------------------------------------"

echo "File test"
echo "----------------------------------------------------"
cd /bin
if test -e ./bash;then
    echo "文件存在"
else
    echo "文件不存在"
fi
echo "----------------------------------------------------"
echo "Add logic operators"
echo "----------------------------------------------------"
cd /bin
if test -e ./bash -o -e ./file;then
    echo "至少有一个文件存在"
else
    echo "两个文件都不存在"
fi
echo "----------------------------------------------------"
