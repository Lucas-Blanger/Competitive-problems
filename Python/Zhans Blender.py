def tempo_minimo_para_bater(t, casos_de_teste):
    resultados = []
    for caso in casos_de_teste:
        n, x, y = caso
        
        if n == 0:
            resultados.append(0)
            continue

        if y >= x:
            resultados.append((n + x - 1) // x)
        else:
            tempo_para_processar = (n + y - 1) // y
            resultados.append(tempo_para_processar)
    
    return resultados

t = int(input())
casos_de_teste = []
for _ in range(t):
    n = int(input())
    x, y = map(int, input().split())
    casos_de_teste.append((n, x, y))

resultados = tempo_minimo_para_bater(t, casos_de_teste)
for res in resultados:
    print(res)
