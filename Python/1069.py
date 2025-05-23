N = int(input())

for i in range(N):
    linha = input().replace(".", "")
    pilha = []
    diamantes = 0

    for c in linha:
        if c == "<":
            pilha.append(c)
        elif c == ">":
            if pilha:
                pilha.pop()
                diamantes += 1

    print(diamantes)
