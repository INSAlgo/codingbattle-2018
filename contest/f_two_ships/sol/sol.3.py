#!/usr/bin/env python3


def knapsack(nW, rivals, weights):
    # 2-dimensional DP
    # L(i, j) <-> if it is possible to have a boat with weight j, considering
    # only the pirates in the first i couples of rivals

    # L is initialized to a matrix of False
    L = [[False] * (nW + 1) for _ in range(len(rivals) + 1)]

    # L(0, 0) = true
    # L(0, j) = false for j != 0
    L[0][0] = True

    # L(i+1, j) = L(i, j-w[k]) or L(i, j), where k is one of the pirates
    # concerned by the (i+1)-th rivalry
    jWeight = 0  # How many rivalries have been explored
    for (pirate1, pirate2) in rivals:
        for j in range(nW + 1):
            if pirate2 != -1:
                if j - weights[pirate1] >= 0:
                    L[jWeight + 1][j] = (
                        L[jWeight][j - weights[pirate1]]
                        or L[jWeight + 1][j])
                if (j - weights[pirate2] >= 0):
                    L[jWeight + 1][j] = (
                        L[jWeight][j - weights[pirate2]]
                        or L[jWeight + 1][j])
            else:
                if j - weights[pirate1] >= 0:
                    L[jWeight + 1][j] = (
                        L[jWeight][j - weights[pirate1]]
                        or L[jWeight][j])
                else:
                    L[jWeight + 1][j] = L[jWeight][j]
        jWeight += 1

    nWMax = nW
    while nWMax >= 0 and not L[len(rivals)][nWMax]:
        nWMax -= 1

    return nWMax


def main():
    nN = int(input())
    nR = int(input())
    weights = list(map(int, input().split()))
    totalweight = sum(weights)

    rivals = []
    has_rival = [False] * nN
    for _ in range(nR):
        nid1, nid2 = map(int, input().split())
        rivals.append((min(nid1, nid2), max(nid1, nid2)))
        has_rival[nid1] = True
        has_rival[nid2] = True
    for i in range(nN):
        if not has_rival[i]:
            rivals.append((i, -1))

    boat_min = knapsack(totalweight // 2, rivals, weights)

    print(totalweight - 2 * boat_min)


if __name__ == "__main__":
    main()
