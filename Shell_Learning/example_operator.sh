#! /bin/bash
# aurthor: purepipha
# url: https://purepipha.github.io

echo "expr use"
echo "--------------------------------"
val=`expr 1 + 1`
echo "1+1 = ${val}"
echo "--------------------------------"

echo "Math operators"
echo "--------------------------------"
a=30
b=50

val=`expr ${a} + ${b}`
echo "a+b = ${val}"

val=`expr ${a} - ${b}`
echo "a-b = ${val}"

val=`expr ${a} \* ${b}`
echo "a*b = ${val}"

val=`expr ${a} / ${b}`
echo "a/b = ${val}"

val=`expr ${a} % ${b}`
echo "a%b = ${val}"

if [ ${a} == ${b} ]; then
    echo "a = b"
fi

if [ ${a} != ${b} ]; then
    echo "a != b"
fi
echo "--------------------------------"

echo "Relational operators"
echo "-eq -ne -gt -lt -ge -le"
echo "--------------------------------"

a=30
b=50

if [ ${a} -eq ${b} ]; then
    echo "a -eq b : a 等于 b"
else
    echo "a -eq b : a 不等于 b"
fi

if [ ${a} -ne ${b} ]; then
    echo "a -ne b : a 不等于 b"
else
    echo "a -ne b : a 等于 b"
fi

if [ ${a} -gt ${b} ]; then
    echo "a -gt b : a 大于 b"
else
    echo "a -gt b : a 不大于 b"
fi

if [ ${a} -lt ${b} ]; then
    echo "a -lt b : a 小于 b"
else
    echo "a -lt b : a 不小于 b"
fi

if [ ${a} -ge ${b} ]; then
    echo "a -ge b : a 大于等于 b"
else
    echo "a -ge b : a 小于 b"
fi

if [ ${a} -le ${b} ]; then
    echo "a -le b : a 小于等于 b"
else
    echo "a -le b : a 大于 b"
fi
echo "--------------------------------"

echo "Bool operators"
echo "! -o -a"
echo "------------------------------------------------------"
a=10
b=20

if [ ${a} -lt ${b} -a ${a} -gt 40 ];then
    echo "${a} 小于 ${b} 且 ${a} 大于 5 : 返回 true"
else
    echo "${a} 小于 ${b} 且 ${a} 大于 5 : 返回 false"
fi

if [ ${a} -lt ${b} -o ${a} -gt 40 ];then
    echo "${a} 小于 ${b} 或 ${a} 小于 40 : 返回true"
else
    echo "${a} 小于 ${b} 或 ${a} 小于 40 : 返回false"
fi


echo "--------------------------------------------------------"

echo "Logic operators"
echo "&& ||"
echo "--------------------------------------------------------"

if [[ ${a} -gt ${b} && ${b} -ge 15 ]];then
    echo "${a} 大于 ${b} 且 ${b} 大于等于 15 : 返回 true"
else
    echo "${a} 大于 ${b} 且 ${b} 大于等于 15 : 返回 false"
fi

if [[ ${a} -gt ${b} || ${b} -ge 15 ]];then
    echo "${a} 大于 ${b} 或 ${b} 大于等于 15 : 返回 true"
else
    echo "${a} 大于 ${b} 或 ${b} 大于等于 15 : 返回 false"
fi
echo "--------------------------------------------------------"

echo "Strings operators"
echo "= != -z -n $"
echo "--------------------------------------------------------"

a="pure"
b="pip"

if [ ${a} = ${b} ];then
    echo "${a} = ${b} : a 等于 b"
else
    echo "${a} = ${b} : a 不等于 b"
fi

if [ ${a} != ${b} ];then
    echo "${a} != ${b} : a 不等于b"
else
    echo "${a} != ${b} : a 等于 b"
fi

if [ -z ${a} ];then
    echo "-z ${a} : 字符串长度为 0"
else
    echo "-z ${a} : 字符串长度不为 0"
fi

if [ -n ${a} ];then
    echo "-n ${a} : 字符串长度不为 0"
else
    echo "-n ${a} : 字符串长度为 0"
fi

if [ ${a} ];then
    echo "$a : 字符串不为空"
else
    echo "$a : 字符串为空"
fi

echo "--------------------------------------------------------"

echo "File test operators"
echo "-b -c -d -f -g -k -p -u -r -w -x -s -e"
echo "----------------------------------------------------------------"

file="./example_array.sh"

if [ -r "$file" ];then
    echo "文件${file}可读"
else
    echo "文件${file}不可读"
fi
if [ -w "$file" ];then
    echo "文件${file}可写"
else
    echo "文件${file}不可写"
fi

if [ -x ${file} ];then
    echo "文件${file}可执行"
else
    echo "文件${file}不可执行"
fi

if [ -s $file ];then
    echo "文件${file}不为空"
else
    echo "文件${file}为空"
fi

if [ -f ${file} ];then
    echo "文件${file}为普通文件"
else
    echo "文件${file}为特殊文件${file}"
fi

if [ -e ${file} ];then
    echo "文件${file}存在"
else
    echo "文件${file}不存在"
fi

if [ -d ${file} ];then
    echo "文件${file}是个目录"
else
    echo "文件${file}不是目录"
fi

echo "----------------------------------------------------------------"