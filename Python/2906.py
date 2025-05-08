def limpar(s):
    resultado = []
    for c in s:
        if c == ".":
            continue
        if c == "+":
            break
        resultado.append(c)
    return "".join(resultado)


n = int(input())
emails = []

for _ in range(n):
    email = input()
    nome, dominio = email.split("@")
    nome_limpo = limpar(nome)
    emails.append(f"{nome_limpo}@{dominio}")

emails.sort()

diferentes = 1 if emails else 0
for i in range(1, len(emails)):
    if emails[i] != emails[i - 1]:
        diferentes += 1

print(diferentes)
