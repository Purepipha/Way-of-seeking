#! /bin/bash

#获取字符串长度
string="abcd"
echo ${#string}     #输出4

string="abcde"
echo ${#string[0]}  #输出5

#提取字符串
string="purepipha is a great people"
echo ${string:3:6}  #输出epipha

#查找字符串
string="purepipha is a great people"
echo `expr index "$string" io`   #输出6
