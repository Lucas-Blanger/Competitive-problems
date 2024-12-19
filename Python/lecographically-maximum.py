n = int(input())
lista = list(map(int, input().split()))


lista.sort(reverse=True)
dif = 0
aux = 0

for i in range(4):

    if lista[0] < 32:
        lista[0] += lista[1]
        dif = lista[0] - 31
        if 0 < dif < 31:
            lista[1] = dif
        else:
            lista[1] = 0
        if lista[0] > 31:
            lista[0] = 31

    if lista[2] < 32:
        lista[2] += lista[3]
        dif = lista[2] - 31
        if 0 < dif < 31:
            lista[3] = dif
        else:
            lista[3] = 0
        if lista[2] > 31:
            lista[2] = 31

    lista.sort(reverse=True)

print(" ".join(map(str, lista)))
