import bisect

n = int(input())
cubos = list(map(int, input().split()))

cubos.sort(reverse=True)  
torres = [cubos[0]]  

for i in range(1, len(cubos)):
    pos = bisect.bisect_right(torres, cubos[i])
    if pos < len(torres):
        torres[pos] = cubos[i]
    else:
        torres.append(cubos[i])

print(len(torres))
