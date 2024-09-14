def verifica_estrategia_vencedora(tabuleiro):
    n = len(tabuleiro)
    
    # Verifica as possíveis combinações para Maria vencer
    for i in range(n - 2):
        # Verifica as condições: XX., .XX, X.X
        if (tabuleiro[i] == 'X' and tabuleiro[i+1] == 'X' and tabuleiro[i+2] == '.') or \
           (tabuleiro[i] == '.' and tabuleiro[i+1] == 'X' and tabuleiro[i+2] == 'X') or \
           (tabuleiro[i] == 'X' and tabuleiro[i+1] == '.' and tabuleiro[i+2] == 'X'):
            return 'S'
    
    # Se nenhuma condição for encontrada, retorna 'N'
    return 'N'

def main():
    while True:
        # Lê o tamanho do tabuleiro
        N = int(input())
        if N == 0:
            break
        
        # Lê o estado do tabuleiro
        tabuleiro = input().strip()
        
        # Verifica se Maria tem uma estratégia vencedora e imprime o resultado
        print(verifica_estrategia_vencedora(tabuleiro))

# Executa o programa
main()