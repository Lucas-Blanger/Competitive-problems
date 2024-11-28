def calculaLucroMaximo(dias, custo, receitas):
  
    receitaLiquida = [r - custo for r in receitas]

    maxLucro = 0
    lucroAtual = 0

    for receita in receitaLiquida:
        lucroAtual = max(receita, lucroAtual + receita)
        maxLucro = max(maxLucro, lucroAtual)

    return maxLucro

while True:
    try:
        N = int(input().strip())

        custo = int(input().strip())
        receitas = [int(input().strip()) for i in range(N)]

        maxLucro = calculaLucroMaximo(N, custo, receitas)
        print(maxLucro)
    except EOFError:
        break


