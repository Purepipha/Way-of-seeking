#! /bin/bash
# aurthor: purepipha
# url: https://purepipha.github.io

echo "Display string"
echo "--------------------------------"
echo "Hello world"
echo Hello World
echo "--------------------------------"

echo "Display escape character"
echo "--------------------------------"
echo "\"Hello World\""
echo \"Hello World\"
echo "--------------------------------"

echo "Display variment"
echo "--------------------------------"
read name
echo "Hello, ${name}"
echo "--------------------------------"

echo "Display \n"
echo "--------------------------------"
echo -e "Hello! \n"
echo "World!"
echo "--------------------------------"

echo "Display not \n"
echo "--------------------------------"
echo -e "Hello, \c"
echo "World!"
echo "--------------------------------"

echo "Display result redirect to file"
echo "--------------------------------"
echo "Hello world!" > test.txt
echo "--------------------------------"

echo "Display string, no get value and escape"
echo "--------------------------------------------------------"
echo '"$name\"'
echo "--------------------------------------------------------"

echo "Display comand excute result"
echo "--------------------------------------------------------"
echo `date`
echo "--------------------------------------------------------"

