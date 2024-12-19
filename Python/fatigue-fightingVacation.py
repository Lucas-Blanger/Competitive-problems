
d, c, r = map(int, input().split())
AC = []
for i in range(c):
    AC.append(int(input()))

AR = []
for i in range(r):
    AR.append(int(input()))

AR.sort(reverse=True)

t = 0
i, j = 0, 0

while i < c or j < r:
    if i < c and AC[i] <= d:
        d -= AC[i]
        i += 1
        t += 1
    elif j < r:
        d += AR[j]
        j += 1
        t += 1
    else:
        break

print(t)
