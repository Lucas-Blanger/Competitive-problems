#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

#define MAXSIZE 300000

using namespace std;

struct G {
    int u, v;
    double w;
};

struct Point {
    int x, y;
};

int p[MAXSIZE];
G g[MAXSIZE];
Point points[MAXSIZE];

// Função para encontrar o representante do conjunto
int parent(int i) {
    return (i == p[i]) ? i : parent(p[i]);
}

// Função para calcular a distância euclidiana entre dois pontos
double dist(const Point& a, const Point& b) {
    return hypot(b.x - a.x, b.y - a.y);
}

// Função de comparação para ordenação de arestas
bool compare(const G& a, const G& b) {
    return a.w < b.w;
}

// Algoritmo de Kruskal para encontrar a soma das arestas da Árvore Geradora Mínima
double kruskal(int count) {
    double ans = 0.0;
    for (int i = 0; i < count; ++i) {
        int u = parent(g[i].u);
        int v = parent(g[i].v);
        if (u != v) {
            p[u] = p[v];
            ans += g[i].w;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;

    while (c--) {
        int n;
        cin >> n;
        int k = 0;

        for (int i = 0; i < n; ++i) {
            cin >> points[i].x >> points[i].y;
            for (int j = 0; j < i; ++j) {
                g[k].u = j;
                g[k].v = i;
                g[k].w = dist(points[j], points[i]) / 100.0;
                ++k;
            }
        }

        sort(g, g + k, compare);

        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }

        cout << fixed << setprecision(2) << kruskal(k) << '\n';
    }

    return 0;
}