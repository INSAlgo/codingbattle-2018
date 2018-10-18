#!/usr/bin/env python2


def backtrack(state, last_covered_pos, current_pos_index):
    # we have reached the last position
    if current_pos_index == n:
        if last_covered_pos >= l:
            return True
        return False

    # find the widest hat we haven't placed yet
    max_hat = 0
    for i in range(n):
        if state[i] == 0 and hats[i] > max_hat:
            max_hat = hats[i]
    # if twice the widest hat can't cover one of the remaining gaps,
    # go back
    for i in range(current_pos_index, n - 1):
        if last_covered_pos < pos[i] and pos[i + 1] - pos[i] - 1 > 2 * max_hat:
            return False
    if last_covered_pos < l and pos[n - 1] + max_hat < l:
        return False

    # consider every hat we haven't placed yet
    for i in range(n):
        if state[i] == 0:
            # if placing the current hat here can lead to a solution
            if pos[current_pos_index] - hats[i] - 1 <= last_covered_pos:
                # push the current hat here and recurse to the next position
                state[i] = 1
                if backtrack(state, max(pos[current_pos_index]
                   + hats[i], last_covered_pos), current_pos_index + 1):
                    # a solution was found !
                    return True
                # pop back the current hat before we evaluate the other hats
                state[i] = 0
    return False


l, n = map(int, raw_input().split())
pos = list(map(int, raw_input().split()))
hats = list(map(int, raw_input().split()))

state = [0] * n
hats.sort()

if backtrack(state, 1, 0):
    print "YES"
else:
    print "NO"
