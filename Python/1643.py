def fibo(n):
   fib = [0] * (n + 1)
   fib[1] = 1
   fib[2] = 2
  
   for i in range(3, n + 1):
       fib[i] = fib[i - 1] + fib[i - 2]
      
   return fib

fib = fibo(45)
  
n = int(input())
  
for i in range(n):
   m = int(input())
      
   j = 45
   resosta = 0
   while j > 1:
       if fib[j] <= m:
           m -= fib[j]
           resosta += fib[j - 1]
       j -= 1
      
   print(resosta)
