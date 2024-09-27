def verifica_estrategia_vencedora(tabuleiro):
    n = len(tabuleiro)
    
    for i in range(n - 2):
        if (tabuleiro[i] == 'X' and tabuleiro[i+1] == 'X' and tabuleiro[i+2] == '.') or \
           (tabuleiro[i] == '.' and tabuleiro[i+1] == 'X' and tabuleiro[i+2] == 'X') or \
           (tabuleiro[i] == 'X' and tabuleiro[i+1] == '.' and tabuleiro[i+2] == 'X'):
            return 'S'
    
    return 'N'

def main():
    while True:
        N = int(input())
        if N == 0:
            break
        
        tabuleiro = input().strip()
        
        print(verifica_estrategia_vencedora(tabuleiro))

main()