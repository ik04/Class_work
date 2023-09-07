#!/bin/bash
echo Enter value for n
read n
sum=0
i=1
while [ $i -le $n ]; do
    sum=$((sum + i))
    i=$((i + 2))

done
echo Sum is $sum
