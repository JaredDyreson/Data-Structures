#!/usr/bin/env python3.8

def knap(capacity: int, weight: list, values: list, size: int):
    if not(isinstance(capacity, int) and
           isinstance(weight, list) and
           isinstance(values, list) and
           isinstance(size, int) and
           len(values) == len(weight)):
           raise ValueError

    cache = [[0 for x in range(capacity + 1)] for x in range(size+1)]

    for i in range(size + 1):
        for w in range(capacity + 1):
            if(i == 0 or w == 0):
                cache[i][w] = 0
            elif(weight[i-1] <= capacity):
                a = values[i-1] + cache[i-1][w-weight[i-1]]
                b = cache[i-1][w]
                cache[i][w] = max(a, b)
            else:
                cache[i][w] = cache[i-1][w]

    # print_matrix(cache, capacity, size)
    print(cache)
    return cache[size][capacity]

values = [1, 2, 3]
weights = [6, 10, 12]
cap = 5
size = len(values)


def solution(W: int, weights: list, values: int):
    cache = [[0 for x in range(len(weights) + 1)] for x in range(W+1)]
    for x in range(len(weights)):
        for y in range(W):
            print(x, y)

print(solution(cap, weights, values))

