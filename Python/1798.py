def maxValor(N, T, canos):
    dp = [0] * (T + 1)

    for t in range(1, T + 1):
        for comprimento, valor in canos:
            if t >= comprimento:  
                dp[t] = max(dp[t], dp[t - comprimento] + valor)

    return dp[T]



N, T = map(int, input().split())
canos = [tuple(map(int, input().split())) for i in range(N)]


resultado = maxValor(N, T, canos)
print(resultado)
