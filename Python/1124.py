import math

while True:
    numeros = input().split() 
    L, C, R1, R2 = map(int, numeros)
    if (L == 0 and C == 0 and R1 == 0 and R2 == 0):
        break

    if 2 * R1 > L or 2 * R1 > C or 2 * R2 > L or 2 * R2 > C:
        print("N")
        continue

    distanciaCentros = math.sqrt((L - R1 - R2) ** 2 + (C - R1 - R2) ** 2)

    if distanciaCentros >= R1 + R2:
        print("S")
    else:
        print("N")
