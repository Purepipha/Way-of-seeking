# ! /bin/bash
# aurthor: purepipha
# url: https://purepipha.github.io

echo "Process control"
echo "--------------------------------"
a=5
b=10
if [ ${a} == ${b} ];then
    echo "a 等于 b"
elif [ ${a} -gt ${b} ];then
    echo "a 大于 b"
elif [ ${a} -lt ${b} ];then
    echo "a 小于 b"
else
    echo "没有符合的条件"
fi
echo "--------------------------------"

echo "If else and test"
echo "--------------------------------"
num1=$[2*5]
num2=$[3*4]
if test $[num1] -eq $[num2];then
    echo "num1 等于 num2"
else
    echo "num1 不等于 num2"
fi
echo "--------------------------------"

echo "for loop"
echo "--------------------------------"
echo "output figure"
echo "--------------------------------"
for loop in 1 2 3 4 5 6
do
    echo "The value is $loop"
done
echo "--------------------------------"

echo "output string"
echo "--------------------------------"
for str in This is a shell script
do
    echo $str
done
echo "--------------------------------"

echo "while loop"
echo "--------------------------------"
i=1
while(( $i<=3))
do
    echo $i
    let "i++"
done
echo "--------------------------------"


echo "while and read keyboard input"
echo "--------------------------------"
echo "按下 <CRTL-D> 退出"
echo -n '输入你最喜欢的电影：'
while read FILM
do
    echo "是的，${FILM} 是一个很棒的电影"
done
echo "--------------------------------"

echo "until loop"
echo "--------------------------------"
a=0
until [ ! ${a} -lt 5 ]
do
    echo ${a}
    a=`expr ${a} + 1`
done
echo "--------------------------------"

echo "case ... esac: figure"
echo "--------------------------------"
echo "输入 1 到 7 之间的数字: "
echo "你输入的数字为: "
read num
case ${num} in
    1) echo "选择了1"
    ;;
    2) echo "选择了2"
    ;;
    3) echo "选择了3"
    ;;
    4) echo "选择了4"
    ;;
    5) echo "选择了5"
    ;;
    6) echo "选择了6"
    ;;
    7) echo "选择了7"
    ;;
    *) echo "输入了其他数字"
    ;;
esac
echo "--------------------------------"

echo "case ... esac: string"
echo "--------------------------------"
site="purepipha"

case "$site" in
    "purepipha") echo "个人博客"
    ;;
    "google") echo "谷歌搜索"
    ;;
    "baidu") echo "百度搜索"
    ;;
esac
echo "--------------------------------"

echo "Jump loop: break"
echo "--------------------------------"
while :
do
    echo -n "输入 1 到 3 之间的数字: "
    read num
    case ${num} in
        1|2|3) echo "输入的数字为: ${num}"
        ;;
        *) echo "输入数字不再范围，退出循环"
            break
        ;;
    esac
done
echo "--------------------------------"

echo "Jump loop continue"
echo "--------------------------------"
while :
do
    echo -n "输入 1 到 3 之间的数字: "
    read num
    case ${num} in
        1|2|3) echo "输入的数字为: ${num}"
        ;;
        *) echo "输入数字不再范围"
            continue
            echo "退出循环"
        ;;
    esac
done



