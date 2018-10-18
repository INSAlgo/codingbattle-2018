# Solution written by Thibault Douzon

# inputs
N = int(input())
r = int(input())
p = list(map(int, input().split()))

# Will hold indices of rival pirates, we will remove them from the listĿ
to_del = []
for _ in range(r):
    # For each pair of pirates, store the absolute difference,
    # ie the unbalance they create instead of the two pirates separately
    p1, p2 = map(int, input().split())
    p.append(abs(p[p1] - p[p2]))
    to_del += [p[p1], p[p2]]
# Delete every pirate involved in a rivalry
for d in to_del:
    p.remove(d)

# Now the problem is a knapsack which objective sum is
# half of the total sum of the unbalanced pirates.
# It might be impossible to reach the objective -> take the best solution
L = sum(p) // 2 + 1

dp = [None for _ in range(L)]
dp[0] = True

for pi in p:
    for i in range(L - 1, -1, -1):
        if dp[i] and i + pi < L:
            dp[i + pi] = True

# Print the first encountered solution in reversed order
for i in range(L - 1, -1, -1):
    if dp[i]:
        # abs(i - (sum(p) - i)) === sum(p) - 2 * i iff i <= sum(p) / 2
        print(sum(p) - 2 * i)
        break
