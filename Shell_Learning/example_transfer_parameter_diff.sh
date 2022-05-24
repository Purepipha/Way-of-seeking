#! /bin/bash
# aurthor: purepipha
# url: https://purepipha.github.io

echo "---diff $* and $@ ---"
for i in "$*"; do
    echo $i
done

for i in "$@"; do
    echo $i
done