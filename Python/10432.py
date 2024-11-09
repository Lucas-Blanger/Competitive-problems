import math

while True:
    try:
        r, n = map(float, input().split())

        PI = 360 / n

        theta = 90 - (PI / 2)

        thetaR = math.radians(theta)

        a = 2 * r * math.cos(thetaR)

        h = r * math.sin(thetaR)

        A = ((a * h) / 2) * n

        print(f"{A:.3f}")
    except EOFError:
        break
