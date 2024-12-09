def primos(n):
    eh_primo = [True] * (n + 1)
    eh_primo[0] = eh_primo[1] = False  

    for i in range(2, int(n**0.5) + 1):
        if eh_primo[i]:
            for multiplo in range(i * i, n + 1, i):
                eh_primo[multiplo] = False
    return [numero for numero in range(n + 1) if eh_primo[numero]]


def primosApos(n, quantidade=10):

    limite = n + quantidade * 50 
    todos_primos = primos(limite)

    resultado = []
    for primo in todos_primos:
        if primo >= n: 
            resultado.append(primo)
            if len(resultado) == quantidade:
                break

    return resultado


n = int(input())

resultado = sum(primosApos(n))

tempo_horas = 60000000 // resultado
tempo_dias = tempo_horas // 24

print(f"{resultado} km/h")
print(f"{tempo_horas} h / {tempo_dias} d")
