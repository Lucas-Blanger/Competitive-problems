import math

g = 9.80665
pi = 3.14159


def calcula(h, alguloRaios, v):
    alguloRad = alguloRaios * pi / 180
    vx = v * math.cos(alguloRad)
    vy = v * math.sin(alguloRad)

    t = (vy + math.sqrt(vy**2 + 2 * g * h)) / g
    alcance = vx * t
    return alcance


while True:
    try:
        h = float(input())
        p1, p2 = map(int, input().split())
        n = int(input())
        for i in range(n):
            angulo, velocidade = map(float, input().split())
            alcance = calcula(h, angulo, velocidade)
            acertou = p1 <= alcance <= p2
            print(f"{alcance:.5f} -> {'DUCK' if acertou else 'NUCK'}")
    except EOFError:
        break
