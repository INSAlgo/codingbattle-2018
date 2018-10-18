#!/usr/bin/env python3


def main():
    _ = int(input())
    nR = int(input())
    weights = list(map(int, input().split()))
    totalweight = sum(weights)

    for _ in range(nR):
        nid1, nid2 = map(int, input().split())

    print(totalweight % 2)


if __name__ == "__main__":
    main()
