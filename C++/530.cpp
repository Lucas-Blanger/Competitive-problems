#include <cstdio>
using namespace std;

long long a[5001][5001];

int main() {
	int n, k;
	unsigned long long resultado;

	while (scanf("%d %d", &n, &k), n || k) {

		resultado = 1;
		if (k > (n / 2))
			k = n - k;

		for (int i = 0; i < k; i++) {
			resultado *= (n - i);
			resultado /= (1 + i);
		}

		printf("%llu\n", resultado);
	}

	return 0;
}