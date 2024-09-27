s = input().strip()
k = int(input().strip())
n = len(s)
grupos = [[] for j in range(k)]

for i in range(n):
    grupos[i % k].append(s[i])

for grupo in grupos:
    grupo.sort()

resultado = []
indices = [0] * k
for i in range(n):
    indice_grupo = i % k
    resultado.append(grupos[indice_grupo][indices[indice_grupo]])
    indices[indice_grupo] += 1

print(''.join(resultado))
