import math

numeros = input().split()
a, b, c = map(float, numeros)

raiz = float( (b**2) - 4*a*c) 
if(raiz <= 0 or 2 * a == 0):
    print("Impossivel calcular")
else:
    raiz = float(math.sqrt( (b**2) - 4*a*c)) 
    r1 = float((-b + raiz) /  (2 * a))
    r2 = float((-b - raiz) /  (2 * a))
    print(f"R1 = {r1:.5f}")
    print(f"R2 = {r2:.5f}")

