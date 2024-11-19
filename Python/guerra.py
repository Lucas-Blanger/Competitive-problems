import math

def distancia(v1, v2):
    return math.sqrt((v2[0] - v1[0])**2 + (v2[1] - v1[1])**2 + (v2[2] - v1[2])**2)

def verticeAlterado(vertice):
    distancias = []
    for i in range(4):
        dists = []
        for j in range(4):
            if i != j:
                dists.append(distancia(vertice[i], vertice[j]))
        distancias.append(dists)
    
    mediaDistacia = min(distancias, key=lambda d: sum(abs(d[k] - d[m]) for k in range(3) for m in range(k+1, 3)))
    mediaValor = sum(mediaDistacia) / 3
    
    alterado = -1
    maiorDesvio = 0
    for i in range(4):
        desvio = sum(abs(d - mediaValor) for d in distancias[i])
        if desvio > maiorDesvio:
            maiorDesvio = desvio
            alterado = i
    
    return alterado + 1  

pe = 0
while True:
    if pe == 1:
        break

    vertice = []
    for i in range(4):
        x, y, z = map(float, input().strip().split())
        if x == 0 and y == 0 and z == 0:
            pe = 1
            break
        vertice.append((x, y, z))
        
    if pe == 0 and len(vertice) == 4:
        print(verticeAlterado(vertice))


