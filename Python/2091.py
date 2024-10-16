#2091
while True:
    N = int(input())
    if N == 0:
        break
    
    A = input().split()
    count = {}

    for nome in A:
        if nome in count:
            count[nome] += 1
        else:
            count[nome] = 1

    for nome in A:
        if count[nome] == 1 or count[nome] % 2 != 0:
            print(nome)
            break
