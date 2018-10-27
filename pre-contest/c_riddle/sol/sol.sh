#!/bin/bash

read L
read N

declare -A det_cycle

i=0
while [[ "$i" -lt "$N" ]]
do
    ((i+=1))
    L=$(echo $L | grep -o . | sort | uniq -c | tr -d "[:space:]")

    if [ ! -z "${det_cycle[$L]}" ]; then
        ((cycle = i - det_cycle[$L]))
        ((to_go = (N - i) / cycle))
        ((i += to_go * cycle))
    else
        det_cycle+=( [$L]=$i )
    fi
done
echo $L
