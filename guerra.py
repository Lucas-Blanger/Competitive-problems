import numpy as np

def calcula_volume(v1, v2, v3, v4):
    matriz = np.array([
        [v1[0], v1[1], v1[2], 1],
        [v2[0], v2[1], v2[2], 1],
        [v3[0], v3[1], v3[2], 1],
        [v4[0], v4[1], v4[2], 1]
    ])
    return abs(np.linalg.det(matriz)) / 6

def identifica_vertice_alterado(vertices):
    volume_total = calcula_volume(vertices[0], vertices[1], vertices[2], vertices[3])
    
    diferencas = []
    for i in range(4):
        outros_vertices = [vertices[j] for j in range(4) if j != i]
        vertice_temporario = (0, 0, 0)  # vértice temporário na origem
        volume_com_temporario = calcula_volume(outros_vertices[0], outros_vertices[1], outros_vertices[2], vertice_temporario)
        diferenca = abs(volume_total - volume_com_temporario)
        diferencas.append(diferenca)
    
    vertice_alterado = diferencas.index(max(diferencas)) + 1
    return vertice_alterado

def main():
    while True:
        vertices = []
        for _ in range(4):
            entrada = input().strip()
            if entrada == "0 0 0":
                return
            coordenadas = tuple(map(float, entrada.split()))
            vertices.append(coordenadas)
        
        vertice_alterado = identifica_vertice_alterado(vertices)
        print(vertice_alterado)

if __name__ == "__main__":
    main()
