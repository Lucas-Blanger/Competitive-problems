numeros = input().split() 
n, h = map(int, numeros)
total = 0

lista = list(map(int, input().split()))
for i in range(n):
    if(h >= lista[i]):
        total = total + 1

print(total)


