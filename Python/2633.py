while True:
    try:
        n = int(input())
        if n == 0:
            continue

        carne = []
        data = []

        for i in range(n):
            string = input().split()
            carne.append(string[0])
            data.append(int(string[1]))

        string2 = list(zip(data, carne))
        string2.sort()

        resultado = [string2[j][1] for j in range(n)]
        print(" ".join(resultado))

    except EOFError:
        break
