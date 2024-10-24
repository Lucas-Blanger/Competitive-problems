class UnionFind:
    def __init__(self, n):
        self.pai = list(range(n))
        self.rank = [0] * n

    def encontrar(self, u):
        if self.pai[u] != u:
            self.pai[u] = self.encontrar(self.pai[u])
        return self.pai[u]

    def unir(self, u, v):
        raiz_u = self.encontrar(u)
        raiz_v = self.encontrar(v)
        
        if raiz_u != raiz_v:
            if self.rank[raiz_u] > self.rank[raiz_v]:
                self.pai[raiz_v] = raiz_u
            elif self.rank[raiz_u] < self.rank[raiz_v]:
                self.pai[raiz_u] = raiz_v
            else:
                self.pai[raiz_v] = raiz_u
                self.rank[raiz_u] += 1

def kruskal(n, arestas):
    uf = UnionFind(n)
    arestas.sort(key=lambda x: x[2]) 
    custoMST = 0
    for u, v, custo in arestas:
        if uf.encontrar(u) != uf.encontrar(v):
            uf.unir(u, v)
            custoMST += custo
    return custoMST

while True:
    m, n = map(int, input().split())
    if m == 0 and n == 0:
        break
    
    arestas = []
    totalCusto = 0
    for _ in range(n):
        x, y, z = map(int, input().split())
        arestas.append((x, y, z))
        totalCusto += z

    custoMST = kruskal(m, arestas)
    print(totalCusto - custoMST)
