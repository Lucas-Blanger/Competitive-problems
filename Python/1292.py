import sys
import math

k = math.sin(math.radians(108)) / math.sin(math.radians(63))

for line in sys.stdin:
    try:
        valor = float(line.strip())
        resultado = k * valor
        print(f"{resultado:.10f}")
    except ValueError:
        continue
