def fatorial(n):
    if(n == 1 or n == 0):
        return 1
    else:
        return fatorial(n -1) * n 


numeros = input().split()

a, b = map(int, numeros)

print(fatorial(a)+fatorial(b))
