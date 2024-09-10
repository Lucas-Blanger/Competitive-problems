def menor_numero_de_movimentos(n, combinacao_atual, combinacao_final):
    movimentos = 0
    acumulado = 0

    for i in range(n - 1, -1, -1):
        atual = (combinacao_atual[i] + acumulado) % 10
        desejado = combinacao_final[i]
        
        movimento_cima = (desejado - atual + 10) % 10
        movimento_baixo = (atual - desejado + 10) % 10
        
        movimento_minimo = min(movimento_cima, movimento_baixo)
        

        if movimento_cima <= movimento_baixo:
            acumulado += movimento_cima
        else:
            acumulado -= movimento_baixo

        movimentos += movimento_minimo

    return movimentos


def processar_testes(testes):
    resultados = []
    for i in range(0, len(testes), 3):
        n = int(testes[i])
        combinacao_atual = list(map(int, testes[i+1].split()))
        combinacao_final = list(map(int, testes[i+2].split()))
        resultado = menor_numero_de_movimentos(n, combinacao_atual, combinacao_final)
        resultados.append(resultado)
    return resultados


testes = []
while True:
    try:
        linha = input()
        if linha.strip():
            testes.append(linha.strip())
        else:
            break
    except EOFError:
        break
    
resultados = processar_testes(testes)
for resultado in resultados:
    print(resultado)
