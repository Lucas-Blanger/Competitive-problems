from math import pi
import sys


for l in sys.stdin:
    l2 = float(l)**2
    area = l2 * (pi / 2 - 1)

    areaQuadrado = 4 * l2 * (1 - pi / 6 - (3**0.5) / 4)
    areaListrada = areaQuadrado + 2 * area - l2
    areaPontos = 2 * area - 2 * areaListrada


    print(f"{areaListrada:.3f} {areaPontos:.3f} {areaQuadrado:.3f}") 