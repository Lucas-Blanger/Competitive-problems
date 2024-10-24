S = int(input())
Q = list(map(int, input().split()))
N = list(map(int, input().split()))


Q.sort()
N.sort()

vitorias = 0
i = 0
j = 0

while i < S and j < S:
    if N[j] > Q[i]:  
        vitorias += 1
        i += 1  
    j += 1  

print(vitorias)
