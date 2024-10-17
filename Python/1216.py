
soma = 0
count = 0

while True:
    try:
        b = input()
        soma += int(input())
        count += 1
    except EOFError:
        break
    
media = soma / count

print(f"{media:.1f}")