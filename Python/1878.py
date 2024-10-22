

colocacao = set()


while True:
   try:
       n, m = map(int, input().split())
   except EOFError:
       break


   c = list(map(int, input().split()))


   colocacao.clear()
   flag = 0


   if n > 1:
       for i in range(1, m + 1):
           for j in range(1, m + 1):
               if n == 3:
                   for k in range(1, m + 1):
                       pont = c[0] * i + c[1] * j + c[2] * k
                       if pont in colocacao:
                           flag = 1
                           break
                       colocacao.add(pont)
                   if flag:
                       break
               else:
                   pont = c[0] * i + c[1] * j
                   if pont in colocacao:
                       flag = 1
                       break
                   colocacao.add(pont)
           if flag:
               break
       if flag:
           print("Try again later, Denis...")
