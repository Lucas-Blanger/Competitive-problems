def resposta_valida(n0, n1, n2, operacao):
    if operacao == "*":
        return n0 * n1 == n2
    elif operacao == "+":
        return n0 + n1 == n2
    elif operacao == "-":
        return n0 - n1 == n2
    elif operacao == "I":
        return n0 * n1 != n2 and n0 + n1 != n2 and n0 - n1 != n2
    return True


try:
    while True:
        while True:
            linha = input()
            if linha.strip() != "":
                break
        T = int(linha.strip())
        jogadas = []
        respostas = []
        jogadores_errados = set()

        for _ in range(T):
            while True:
                linha = input()
                if linha.strip() != "":
                    break
            linha = linha.replace(" ", "=")
            jogadas.append(linha)

        for _ in range(T):
            while True:
                linha = input()
                if linha.strip() != "":
                    break
            respostas.append(linha)

        for i in range(T):
            partes = respostas[i].split()
            nome = partes[0]
            indice = int(partes[1]) - 1
            operacao = partes[2]

            partes_jogada = jogadas[indice].split("=")
            n0 = int(partes_jogada[0])
            n1 = int(partes_jogada[1])
            n2 = int(partes_jogada[2])

            if not resposta_valida(n0, n1, n2, operacao):
                jogadores_errados.add(nome)

        if len(jogadores_errados) == T:
            print("None Shall Pass!")
        elif len(jogadores_errados) == 0:
            print("You Shall All Pass!")
        else:
            print(" ".join(sorted(jogadores_errados)))

except EOFError:
    pass
