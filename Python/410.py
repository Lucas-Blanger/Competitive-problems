casos = 1
while True:
    try:
        C, S = map(int, input().split())
        a = list(map(int, input().split()))
        y = sum(a) / C
        while len(a) < 2 * C:
            a.append(0)
 
        a.sort()
        imbalance = 0
        print(f"Set #{casos}")
        casos += 1
        for i in range(C):
            print(f"{i:2d}:", end='')
            if a[i] > 0:
                print(f" {a[i]}", end='')
            if a[2*C-1-i] > 0:
                print(f" {a[2*C-1-i]}", end='')
            imbalance += abs(a[i] + a[2*C-1-i] - y)
            print()
 
        print(f"IMBALANCE = {imbalance:.5f}")
        print()
    except:
        break