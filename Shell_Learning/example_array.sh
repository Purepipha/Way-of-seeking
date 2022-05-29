#! /bin/bash
# aurthor: purepipha
# url: https://purepipha.github.io

my_array=(P "U" R E)

# Another define method
# array_name[0]=val0
# array_name[1]=val1
# array_name[2]=val2

# read the array
# ${array_name[index]}

# example get one element
echo "get one element:"
echo "first element: ${my_array[0]}"
echo "second element: ${my_array[1]}"
echo "third element: ${my_array[2]}"
echo "fourth element: ${my_array[3]}"

# example get all elements
echo "get all elements"
echo "All elements: ${my_array[*]}"
echo "All elements: ${my_array[@]}"

# get length of the array
echo "number of elements: ${#my_array[*]}"
echo "length of array: ${#my_array[@]}"