while True:
    try:
        N, K = map(int, input().split())
        pos = [0] + list(map(int, input().split()))

        gaps = []
        for i in range(1, N):
            gaps.append(pos[i] - pos[i - 1])

        soma = pos[-1] - pos[0]

        gaps.sort(reverse=True)

        soma -= sum(gaps[: K - 1])

        print(soma)
    except EOFError:
        break
