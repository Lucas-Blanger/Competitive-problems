import math

def distancia(p1, p2):
    return math.sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2 + (p1[2] - p2[2])**2)

def encontrar_vertice_alterado(tetraedro):
    distancias = []
    for i in range(4):
        for j in range(i + 1, 4):
            distancias.append((distancia(tetraedro[i], tetraedro[j]), i, j))
    
    distancias.sort()
    
    contagem = [0] * 4
    for d in distancias:
        contagem[d[1]] += 1
        contagem[d[2]] += 1
    
    max_contagem = max(contagem)
    vertices_alterados = [i + 1 for i, c in enumerate(contagem) if c == max_contagem]
    
    return vertices_alterados[0]

def main():
    while True:
        tetraedro = []
        for _ in range(4):
            linha = input().strip()
            if linha == "0 0 0":
                return
            tetraedro.append(list(map(float, linha.split())))
        
        print(encontrar_vertice_alterado(tetraedro))

if __name__ == "__main__":
    main()
