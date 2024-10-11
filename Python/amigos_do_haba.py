inscritosYes = []
inscritosNo = []
primeiros = {}

while True:
    entrada = input().strip()
    if entrada == "FIM":
        break
    
    nome, escolha = entrada.split()

    if escolha == "YES":
        if nome not in primeiros:
            inscritosYes.append((nome, escolha))
            primeiros[nome] = len(inscritosYes) - 1
    else:
        if nome not in [n for n, _ in inscritosNo]:
            inscritosNo.append((nome, escolha))

tamYes = len(inscritosYes)
tamNo = len(inscritosNo)

for i in range(tamYes - 1):
    for j in range(i + 1, tamYes):
        if inscritosYes[i][0] > inscritosYes[j][0]:
            inscritosYes[i], inscritosYes[j] = inscritosYes[j], inscritosYes[i]

for i in range(tamNo - 1):
    for j in range(i + 1, tamNo):
        if inscritosNo[i][0] > inscritosNo[j][0]:
            inscritosNo[i], inscritosNo[j] = inscritosNo[j], inscritosNo[i]


vencedor = inscritosYes[0][0]  
maxLetras = len(vencedor)

for i in range(1, tamYes):
    nomeAtual = inscritosYes[i][0]
    if len(nomeAtual) > maxLetras:
        vencedor = nomeAtual
        maxLetras = len(nomeAtual)
    elif len(nomeAtual) == maxLetras:
        if primeiros[nomeAtual] < primeiros[vencedor]:
            vencedor = nomeAtual

for i in range(tamYes):
    print(inscritosYes[i][0])

for i in range(tamNo):
    print(inscritosNo[i][0])

print()

print("Amigo do Habay:")
print(vencedor)
