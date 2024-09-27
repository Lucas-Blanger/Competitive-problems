def sequencia_maxima_lexicografica(N, arr):
    # Itera sobre cada posição de bit, da mais alta (30) até a mais baixa (0)
    for bit in range(30, -1, -1):
        # Índice máximo que está sendo manipulado
        indice_max = -1
        # Procura o maior número com o bit atual igual a 1
        for i in range(indice_max + 1, N):
            if (arr[i] >> bit) & 1:
                indice_max += 1
                # Troca o número encontrado com a posição mais à frente possível
                arr[indice_max], arr[i] = arr[i], arr[indice_max]

    return arr

# Lendo entrada
N = int(input())  # Número de inteiros
arr = list(map(int, input().split()))  # Lista de inteiros

# Encontrando a sequência máxima lexicograficamente
resultado = sequencia_maxima_lexicografica(N, arr)

# Imprimindo o resultado
print(" ".join(map(str, resultado)))
