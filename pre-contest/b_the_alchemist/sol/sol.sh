#!/bin/bash

SOL=0
read P L G

for ((x=0; x < $P && x*x < $G; x++))
do
    for ((y = 0; y < $L; y++))
    do
        ((r=$x*$x + $y + $x*$y))
        if [ "$r" -eq "$G" ]; then
            ((SOL+=1))
        elif [ "$r" -gt "$G" ]; then
            break
        fi
    done
done

echo $SOL
