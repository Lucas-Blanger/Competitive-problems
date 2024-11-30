#include <stdio.h>
#include <cmath>
#include <algorithm>

struct pontos{
	bool usado;
	int x, y;
};

bool Ordenar(pontos a,pontos b){
	if (a.x != b.x)
		return a.x < b.x;
	return a.y < b.y;
}

int produtoVetorial(pontos x1, pontos x2, pontos x3){
	return (x3.x - x2.x)*(x2.y - x1.y) - (x2.x - x1.x)*(x3.y - x2.y);
}

int main(){
	int n, u, d, val, cont, up[2000], t, ultimo, j;
	pontos p[2000], aux;
	while (scanf("%d", &n) != EOF&&n != 0){
		for (int i = 0; i < n; i++){
			scanf("%d%d",&p[i].x,&p[i].y);
			p[i].usado = false;
		}
		std::sort(p, p + n, Ordenar);
		d=val=cont=0;
		while (val < n){
			u = j = 0;
			while (p[j].usado)
				j++;
			ultimo = j;
			for (; j < n; j++){
				aux = p[j];
				if (!aux.usado){
					while (u >= 2 && produtoVetorial(p[up[u-2]],p[up[u-1]],aux)<0)u--;
					up[u++] = j;
				}
			}t = u + 1;
			for (int i = 0; i < u; i++)
				p[up[i]].usado = true;
			for (int i = up[u-1]-1; i > ultimo; i--){
				aux = p[i];
				if (!aux.usado){
					while (u >= t && produtoVetorial(p[up[u - 2]], p[up[u - 1]], aux) < 0)u--;
					up[u++] = i;
				}
			}
			while (u >= t && produtoVetorial(p[up[u - 2]], p[up[u - 1]],p[ultimo]) < 0)u--;
			for (int i = 0; i < u; i++)
				p[up[i]].usado = true;
			cont++;
			val += u;
		}
		if (cont % 2 == 0)
			printf("Do not take this onion to the lab!\n");
		else
			printf("Take this onion to the lab!\n");
	}
}