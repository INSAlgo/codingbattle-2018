#!/usr/bin/env python2
from collections import defaultdict

# Reading input
N = int(raw_input())
treasures = list(map(int, raw_input().split()))
bridges = [tuple(map(int, raw_input().split()))
           for _ in range(N-1)]

# Constructing graph
relationships = defaultdict(list)
for (n1, n2, s) in bridges:
    relationships[n1].append((n2, s))
    relationships[n2].append((n1, s))

# Constructing tree
children = {}
def add_children(children, node, parent):
    """Recursively add children for a given node.
    """
    children[node] = []
    for (other, strength) in relationships[node]:
        if other != parent:
            children[node].append((other, strength))
            add_children(children, other, node)
add_children(children, 0, 0)

# Find the maximal amount of gold we can get
def most_gold(children, node, limit):
    """Recursively get the biggest amount of gold we can get at a given node
    """
    gold_from_each = [
        most_gold(children, other, strength)
        for (other, strength) in children[node]
    ] + [0]
    income = sum(gold_from_each) + treasures[node]
    if limit is not None:
        return min(limit, income)
    else:
        return income
print most_gold(children, 0, None)
