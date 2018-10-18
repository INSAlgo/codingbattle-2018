#!/usr/bin/env python3

g, n = map(int, input().split())
best_offer = 0
seller = ""

# Go through all trainers in the given order
for k in range(n):
    name, p, c = input().split()
    p = int(p)
    c = int(c)

    # Compute how many parrots we can buy from this trainer
    nb_parrots = (g - c) // p

    # Check if it's better than the best encountered yet
    if nb_parrots > best_offer:
        best_offer = nb_parrots
        seller = name

if best_offer:
    print(best_offer)
    print(seller)
else:
    print("Impossible")
