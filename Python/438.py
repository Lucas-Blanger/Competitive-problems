import math

PI = 3.141592653589793

while True:
    try:
        x1, y1, x2, y2, x3, y3 = map(float, input().split())
        
        a = math.sqrt((x1 - x2)**2 + (y1 - y2)**2)
        b = math.sqrt((x2 - x3)**2 + (y2 - y3)**2)
        c = math.sqrt((x3 - x1)**2 + (y3 - y1)**2)
        
        A = 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1)
        
        R = ((a * b * c) / (4 * A)) * 2 * PI
        
        print(f"{R:.2f}")
    except EOFError:
        break