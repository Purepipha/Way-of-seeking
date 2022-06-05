#! /bin/bash
# aurthor: purepipha
# url: https://purepipha.github.io

echo "echo && printf"
echo "--------------------------------"
echo "Hello, world"
printf "Hello, world\n"
echo "--------------------------------"

echo "printf format output"
echo "-----------------------------------------------------"
printf "%-10s %-8s %-4s\n" 姓名 性别 体重kg
printf "%-10s %-8s %-4.2f\n" 约翰 男 66.2845
printf "%-10s %-8s %-4.2f\n" 罗拉 女 49.3281
echo "-----------------------------------------------------"

echo "some cases"

echo "format-string 为双引号"
echo "----------------------------------------------------"
printf "%d %s\n" 1 "auroa"
echo "----------------------------------------------------"

echo "format-string 为单引号，效果与双引号一样"
echo "----------------------------------------------------"
printf '%d %s\n' 1 "auora"
echo "----------------------------------------------------"

echo "没有引号也可以"
echo "--------------------------------"
printf %s auora
echo
echo "--------------------------------"

echo "format-string 被重用，多个参数，一个格式化串"
echo "----------------------------------------------------"

printf %s auora john

printf "%s\n" auora john

printf "%s %s %s\n" a b c d e f g h i j

printf "%s and %d\n"
echo "----------------------------------------------------"

echo "printf's escape sequence"
echo "\a \b \c \f \n \r \t \v \\ \ddd \0ddd"
echo "----------------------------------------------------"

printf "a string, no processing:<%s>\n" "A\nB"

printf "a string, no processing:<%b>\n" "A\nB"

printf "\\ \n"

printf "https://purepipha.github.io \a"



