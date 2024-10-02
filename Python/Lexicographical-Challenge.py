stringOriginal = input().strip()
k = int(input())
tamanho = len(stringOriginal)


posicao= [False] * tamanho

stringOriginal = list(stringOriginal)

for inicio in range(k):
    if not posicao[inicio]:
        indices= []
        indiceAtual = inicio
        
        while indiceAtual < tamanho:
            indices.append(indiceAtual)
            posicao[indiceAtual] = True
            indiceAtual += k 
        
        stringIndices = sorted(stringOriginal[indice] for indice in indices)
        
        for indice, caractere in zip(indices, stringIndices):
            stringOriginal[indice] = caractere

print(''.join(stringOriginal))
