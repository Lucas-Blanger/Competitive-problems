def caixeiroViajante_com(n, matrizAdj):
    dp = [[float('inf')] * (1 << n) for _ in range(n)]
    dp[0][1] = 0  

    for mascara in range(1 << n):
        for u in range(n):
            if mascara & (1 << u):
                for v in range(n):
                    if not mascara & (1 << v):
                        dp[v][mascara | (1 << v)] = min(dp[v][mascara | (1 << v)], dp[u][mascara] + matrizAdj[u][v])

    menor_custo = min(dp[u][(1 << n) - 1] for u in range(n))

    return menor_custo


n = int(input())
matrizAdj = []
for i in range(n):
    linha = list(map(int, input().split()))
    matrizAdj.append(linha)

resultado = caixeiroViajante_com(n, matrizAdj)
print(resultado)
