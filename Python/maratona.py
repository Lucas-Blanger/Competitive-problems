def verifica_regras(texto):
    vogais = set('aeiouAEIOU')
    consoantes = set('bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ')

    # Dividindo o texto em palavras
    palavras = texto.split()

    # Verificar cada palavra
    for palavra in palavras:
        tamanho = len(palavra)
        
        if tamanho > 5:
            # Deve começar e terminar com vogais
            if not (palavra[0] in vogais and palavra[-1] in vogais):
                return "NAO"
        elif tamanho > 1:
            # Deve começar com consoante e terminar com vogal
            if not (palavra[0] in consoantes and palavra[-1] in vogais):
                return "NAO"

    return "SIM"

def main():
    import sys

    input = sys.stdin.read
    data = input().strip().split('\n')

    # Primeira linha contém o número de casos de teste
    N = int(data[0].strip())

    resultados = []
    for i in range(1, N + 1):
        paragrafo = data[i].strip()
        resultado = verifica_regras(paragrafo)
        resultados.append(resultado)

    # Imprimir resultados
    for resultado in resultados:
        print(resultado)

if __name__ == "__main__":
    main()
