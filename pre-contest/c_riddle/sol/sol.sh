#!/bin/bash

read L
read N

# Declare an associative array for detecting cycle
declare -A det_cycle

i=0
while [[ "$i" -lt "$N" ]]
do
    ((i+=1))
    # grep -o prints only matching characters and each match is separated by a new line. Here, the "." mean any character in regex.
    # sort will sort all the lines in an alphabetical order. Here, we only have digits so all our digits will be sorted.
    # uniq -c will print every unique consecutive lines with the number of times it appeared. Here, because we sorted the input, it will print every digit once with the right count.
    # tr -d "[:space:]" removes the spaces between each digit and its count, and the line feed ('\n') between each digit.
    # Thus, L is our new number's string.
    L=$(echo $L | grep -o . | sort | uniq -c | tr -d "[:space:]")

    # If we detect a cycle, we skip as many steps as possible
    if [ ! -z "${det_cycle[$L]}" ]; then
        ((cycle = i - det_cycle[$L]))
        ((to_go = (N - i) / cycle))
        ((i += to_go * cycle))
    else
        # Else, we store this combinaison for later detections
        det_cycle+=( [$L]=$i )
    fi
done
echo $L
