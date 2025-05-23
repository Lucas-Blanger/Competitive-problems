def cartas(n):
    return (3 * n * n + n) // 2


def maior(c):
    low, high = 0, 2 * 10**9
    resposta = 0
    while low <= high:
        mid = (low + high) // 2
        total = cartas(mid)
        if total <= c:
            resposta = mid
            low = mid + 1
        else:
            high = mid - 1
    return resposta


T = int(input())
for i in range(T):
    C = int(input())
    print(maior(C))
