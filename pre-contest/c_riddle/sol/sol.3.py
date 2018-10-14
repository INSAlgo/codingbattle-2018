#!/usr/bin/env python3

L = input()
N = int(input())

counter = [0] * 10
det_cycle = {}
k = 0
while(k < N):
    k += 1
    # Count occurences of every digit in the current number's string
    for i in L:
        counter[int(i)] += 1

    # Create the new number's string
    L = ""
    for i in range(10):
        if(counter[i] != 0):
            L += str(counter[i]) + str(i)
            counter[i] = 0

    # Detect cycles
    if L in det_cycle:
        # Cycle detected, skip as many steps as possible
        cycle = k - det_cycle[L]
        to_go = int((N - k) / cycle)
        k += to_go * cycle
    else:
        # No cycle detected, carry on
        det_cycle[L] = k

print(L)
