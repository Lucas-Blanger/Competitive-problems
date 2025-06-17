def c_mod(a, b):
    return a % b if a >= 0 else -(abs(a) % b)


def custom_sort(x, M):
    mod = c_mod(x, M)
    is_odd = x % 2 != 0
    if is_odd:
        order = (-1, -mod, -x)
    else:
        order = (-1, -mod, x)
    return (c_mod(x, M), not is_odd, order)


while True:
    try:
        line = input()
        if line.strip() == "":
            continue
        N, M = map(int, line.split())
        if N == 0 and M == 0:
            print("0 0")
            break
        nums = []
        for _ in range(N):
            nums.append(int(input()))
        nums.sort(key=lambda x: (c_mod(x, M), x % 2 == 0, -x if x % 2 != 0 else x))
        print(f"{N} {M}")
        for num in nums:
            print(num)
    except EOFError:
        break
