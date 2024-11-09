import math

def distancia(p1, p2):
    return math.sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2 + (p1[2] - p2[2]) ** 2)

def verificaVerticeAlterado(vertices):
    distancias = [
        (distancia(vertices[0], vertices[1]), 0, 1),
        (distancia(vertices[0], vertices[2]), 0, 2),
        (distancia(vertices[0], vertices[3]), 0, 3),
        (distancia(vertices[1], vertices[2]), 1, 2),
        (distancia(vertices[1], vertices[3]), 1, 3),
        (distancia(vertices[2], vertices[3]), 2, 3)
    ]
    
    inconsistencias = [0, 0, 0, 0]
    
    mediaDistacia = sum(d[0] for d in distancias) / len(distancias)
    
    for d, v1, v2 in distancias:
        if abs(d - mediaDistacia) > 0.01 * mediaDistacia:
            inconsistencias[v1] += 1
            inconsistencias[v2] += 1
    
    for i in range(4):
        if inconsistencias[i] == 3:
            return i + 1  



while True:

    vertices = []
    for i in range(4):
        x, y, z = map(float, input().split())
        
        vertices.append((x, y, z))
        
    if all(v == (0.0, 0.0, 0.0) for v in vertices):
        break
        

    verticeAlterado = verificaVerticeAlterado(vertices)
    print(verticeAlterado)


