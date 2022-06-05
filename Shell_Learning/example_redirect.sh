#! /bin/bash
# aurthor: purepipha
# url: https://purepipha.github.io

echo "Output redirect"
echo "================================================"
echo "cover"
echo "--------------------------------"
echo "Hello" > test.txt
cat test.txt
echo "World" > test.txt
cat test.txt
echo "--------------------------------"

echo "no cover"
echo "--------------------------------"
echo "Hello" > test.txt
cat test.txt
echo "World" >> test.txt
cat test.txt
echo "--------------------------------"
echo "================================================"

echo "Get the line of test.txt"
echo "================================================"
echo "no redirect"
echo "--------------------------------"
wc -l test.txt
echo "--------------------------------"
echo "redirect"
echo "--------------------------------"
wc -l < test.txt
echo "--------------------------------"
echo "================================================"

echo "Here Document"
echo "================================================"
echo "Get the line of Here Document"
echo "--------------------------------"
wc -l << EOF
    Hello
    I am purepipha
    Fighting
EOF
echo "--------------------------------"

echo "Copy the contents of Here Document"
echo "--------------------------------"
cat << EOF
    Welcome
    Purepipha's blog
    https://purepipha.github.io
EOF
echo "--------------------------------"
echo "================================================"
