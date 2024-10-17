numeros = input().split() 
numeros2 = input().split() 
cod1, num1, val1 = map(float, numeros)
cod2, num2, val2 = map(float, numeros2)

soma = (num1 * val1) + (num2 * val2)

print(f"VALOR A PAGAR: R$ {soma:.2f}")
