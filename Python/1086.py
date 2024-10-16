#1086
while True:
    M, N = map(int, input().split())
        
    if M == 0 and N == 0:
            break
        
    L = int(input()) / 100
        
    K = int(input())
        
    tabuas = list(map(int, input().split()))
        
    areaSalao = M * N
        
    areaTabuas = [L * comprimento for comprimento in tabuas]
        
    areaTabuas.sort(reverse=True)
        

    areaCoberta = 0
    numTabuas = 0
        
    for area in areaTabuas:
        if areaCoberta >= areaSalao:
            break
        areaCoberta += area
        numTabuas += 1
        
    if areaCoberta >= areaSalao:
        print(numTabuas)
    else:
        print("impossivel")


