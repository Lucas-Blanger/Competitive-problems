a = float(input())

nota100 =  int(a / 100)
nota50 = int((a - (nota100 * 100) ) / 50)
nota20 = int((a - ((nota100 * 100 + (nota50  * 50))) ) / 20)
nota10 = int((a - ((nota100 * 100 + (nota50  * 50) + (nota20 * 20))) ) / 10)
nota5 = int((a - ((nota100 * 100 + (nota50  * 50) + (nota20 * 20) + (nota10 * 10))) ) / 5)
nota2 =  int((a - ((nota100 * 100 + (nota50  * 50) + (nota20 * 20) + (nota10 * 10) + (nota5 * 5))) ) / 2)

resto = a - (nota100 * 100 + (nota50  * 50) + (nota20 * 20) + (nota10 * 10) + (nota5 * 5) + (nota2 * 2))



moeda1 = int(resto // 1)
resto = round(resto - moeda1 * 1, 2)
moeda50 = int(resto // 0.50)
resto = round(resto - moeda50 * 0.50, 2)
moeda25 = int(resto // 0.25)
resto = round(resto - moeda25 * 0.25, 2)
moeda10 = int(resto // 0.10)
resto = round(resto - moeda10 * 0.10, 2)
moeda05 = int(resto // 0.05)
resto = round(resto - moeda05 * 0.05, 2)
moeda01 = int(round(resto / 0.01))

print("NOTAS:")
print(nota100, "nota(s) de R$ 100.00")
print(nota50, "nota(s) de R$ 50.00")
print(nota20, "nota(s) de R$ 20.00")
print(nota10, "nota(s) de R$ 10.00")
print(nota5, "nota(s) de R$ 5.00")
print(nota2, "nota(s) de R$ 2.00")
print("MOEDAS:")
print(moeda1, "moeda(s) de R$ 1.00")
print(moeda50, "moeda(s) de R$ 0.50")
print(moeda25, "moeda(s) de R$ 0.25")
print(moeda10, "moeda(s) de R$ 0.10")
print(moeda05, "moeda(s) de R$ 0.05")
print(moeda01, "moeda(s) de R$ 0.01")


