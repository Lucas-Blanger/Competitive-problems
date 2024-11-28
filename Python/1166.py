import math
def quadradoPerfeito(num):
    root = int(math.sqrt(num))
    return root * root == num

def maxBolas(N):
    r = [0] * N
    bola = 1 

    while True:
        colocada = False
        for i in range(N):
            if r[i] == 0 or quadradoPerfeito(r[i] + bola):
                r[i] = bola
                colocada = True
                break
        if not colocada:  
            break
        bola += 1 

    return bola - 1  


T = int(input())
for i in range(T):
    N = int(input())
    print(maxBolas(N))
