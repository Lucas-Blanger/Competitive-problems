import math
while True:
    try:
        numeros = input().split() 
        D, VF, VG = map(int, numeros)
        
        DG = math.sqrt(12 * 12 + D * D)
        
        tf = 12 / VF
        tg = DG / VG
        
        if(tg > tf):
            print("N")
        else:
            print("S")        

    except EOFError:
        break
