numeros = input().split() 
hi, mi, hf, mf = map(int, numeros)

inicio = (hi * 60) + mi
fim = (hf * 60) + mf

if (fim <= inicio):
    fim += 24 * 60

horas = (fim - inicio) // 60
minutos = (fim - inicio) % 60

print(f"O JOGO DUROU {horas} HORA(S) E {minutos} MINUTO(S)")