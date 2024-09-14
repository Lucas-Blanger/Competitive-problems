import math

def contar_quadrados_perfeitos(L, R):
    raiz_inicio = math.ceil(math.sqrt(L))
    raiz_fim = math.floor(math.sqrt(R))
    
    if raiz_inicio <= raiz_fim:
        return raiz_fim - raiz_inicio + 1
    else:
        return 0

Q = int(input())

for _ in range(Q):
    L, R = map(int, input().split())
    print(contar_quadrados_perfeitos(L, R))