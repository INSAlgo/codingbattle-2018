#!/usr/bin/env python3


def backtrack(state, last_covered_pos, current_pos_index):
    # every hat has been placed, did we cover everything ?
    if current_pos_index == n:
        if last_covered_pos >= l:
            return True
        return False
        
    # look back : we can cut off this branch if the hats that we already placed don't allow us to cover everything
    if (last_covered_pos + 21) < pos[current_pos_index]:
        return False;
    
    # look forward : we can cut off this branch if the widest remaining hat can't cover one of the remaining gaps
    # find the widest remaining hat
    max_hat = 0
    for i in range(n):
        if state[i] == 0 and hats[i] > max_hat:
            max_hat = hats[i]
    # if the widest hat can't cover one of the remaining gaps, cut off the branch
    for i in range(current_pos_index, n-1):
        if last_covered_pos < pos[i] and pos[i+1] - pos[i] - 1 > 2*max_hat:
            return False
    if last_covered_pos < l and pos[n-1] + max_hat < l:
        return False
    
    # consider every hat we haven't placed yet
    for i in range(n):
        if state[i] == 0: # hat available
            # next_covered_pos is the next position that is now covered from the beginning without any gaps, if we use the current hat
            next_covered_pos = last_covered_pos;
            if pos[current_pos_index] - hats[i] - 1 <= last_covered_pos:
                next_covered_pos = max(pos[current_pos_index] + hats[i], last_covered_pos);
            # push the current hat here and recurse to the next position
            state[i] = 1
            if backtrack(state, next_covered_pos, current_pos_index + 1):
                # a solution was found !
                return True
            # pop back the current hat before we evaluate the other hats
            state[i] = 0
    return False

l, n = map(int,input().split())
pos = list(map(int,input().split()))
hats = list(map(int,input().split()))
state = [0] * n
hats.sort();
if backtrack(state, 1, 0):
    print("YES")
else:
    print("NO")
