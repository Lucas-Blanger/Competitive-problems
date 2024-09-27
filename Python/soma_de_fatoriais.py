def fatorial(n):
    if(n == 1 or n == 0):
        return 1
    else:
        return fatorial(n -1) * n 


try:
    while True:
        numeros = input().split()
        a, b = map(int, numeros)
        
        soma_fatoriais = fatorial(a) + fatorial(b)
        print(soma_fatoriais)
except EOFError:
    pass