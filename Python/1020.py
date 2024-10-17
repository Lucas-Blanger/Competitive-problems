a = int(input())

ano = int(a / 365)
mes = int((a - (ano * 365)) // 30)
dias = int((a - ((ano * 365) + (mes * 30))))

print(ano, "ano(s)")
print(mes, "mes(es)")
print(dias, "dia(s)")