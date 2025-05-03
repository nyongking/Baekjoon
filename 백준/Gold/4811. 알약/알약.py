def dp(lst, i, j):
    if not lst[i][j]:
        if j == 0:
            lst[i][j] = dp(lst, i-1, j+1)
        else:
            lst[i][j] = dp(lst, i-1, j+1) + dp(lst, i, j-1)


    return lst[i][j]

while True:
    N = int(input())
    if N == 0:
        break
    cache = [[0] * (N+1) for _ in range(N+1)]
    for j in range(N+1):
        cache[0][j] = 1
    print(dp(cache, N, 0))