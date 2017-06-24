#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;
using ll = long long;

int numDig(ll a) {
	int ans = 0;
	while (a) {
		ans++;
		a /= 10;
	}
	return ans;
}

ll cambio(ll a, ll b) {
	ll potDif = 1;
	while (a / potDif != b / potDif) {
		potDif *= 10;
	}
	return b%potDif;
}

int main() {
	int n;
	int tc = 1;
	while (scanf("%d", &n) != EOF && n) {
		printf("Case %d:\n", tc++);
		ll small; 
		scanf("0");
		scanf("%lld", &small);

		ll ant = small;
		for (int i = 1; i < n; i++) {
			ll nxt; 
			scanf("0");
			scanf("%lld", &nxt);

			if (nxt == ant + 1) ant = nxt;
			else {
				// imprimir los anteriores
				if (small == ant) {
					// solo es un numero
					printf("0");
					printf("%lld\n", ant);
				}
				else {
					// son varios numeros
					printf("0");
					printf("%lld", small);
					// imprimir solo la parte que cambia del anterior
					ll ans = cambio(small, ant);
					printf("-");
					printf("%lld\n", ans);
				}
				// ac
				small = nxt;
				ant = nxt;
			}

		}
		// imprimir los anteriores
		if (small == ant) {
			// solo es un numero
			printf("0");
			printf("%lld\n", ant);
		}
		else {
			// son varios numeros
			printf("0");
			printf("%lld", small);
			// imprimir solo la parte que cambia del anterior
			ll ans = cambio(small, ant);
			printf("-");
			printf("%lld\n", ans);
		}

		printf("\n");
	}
}