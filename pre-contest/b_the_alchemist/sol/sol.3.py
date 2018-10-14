#!/usr/bin/env python3
import math

P, L, G = map(int, input().split())
cpt = 0
for x in range(min(P, math.ceil(math.sqrt(G)))):
    for y in range(L):
        r = x**2 + y + x * y
        if r == G:
            cpt += 1
        elif r > G:
            break
print(cpt)
