#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

struct frac {
	int n, d;
};

int mcd(int a, int b) {
	if (b == 0) return a;
	if (a < b) return mcd(b, a);
	return mcd(b, a%b);
}
void simplificar(frac &f) {
	int d = mcd(f.n, f.d);
	f.n = f.n / d;
	f.d = f.d / d;
}
int parteEntera(frac &f) {
	return f.n / f.d;
}
int sobraN(frac &f) {
	return f.n%f.d;
}
int numDig(int x) {
	int ans = 0;
	while (x) {
		ans++;
		x /= 10;
	}
	return ans;
}

int main() {
	int n;
	int tc = 1;
	while (scanf("%d", &n) != EOF && n) {
		frac ans; ans.n = 0; ans.d = n;
		for (int i = 0; i < n; i++) {
			int tmp; scanf("%d", &tmp);
			ans.n += tmp;
		}
		bool negativo = (ans.n < 0);
		ans.n = abs(ans.n);

		simplificar(ans);
		// fraccion lista

		bool tieneEntero = (parteEntera(ans) > 0);
		bool tieneFraccion = (sobraN(ans) > 0);

		int len = 0;
		printf("Case %d:\n", tc++);
		if (negativo) {
			if (tieneFraccion) {
				if (tieneEntero) {
					int entero = parteEntera(ans);
					int num = sobraN(ans);
					int den = ans.d;

					len = 2 + numDig(entero) + max(numDig(num), numDig(den));

					for (int i = 0; i < len - numDig(num); i++) printf(" "); printf("%d\n", num);
					printf("- "); printf("%d", entero); for (int i = 0; i < len - 2 - numDig(entero); i++) printf("-"); printf("\n");
					for (int i = 0; i < len - numDig(den); i++) printf(" "); printf("%d\n", den);
				}
				else {
					int num = sobraN(ans);
					int den = ans.d;

					len = 2 + max(numDig(num), numDig(den));

					for (int i = 0; i < len - numDig(num); i++) printf(" "); printf("%d\n", num);
					printf("- "); for (int i = 0; i < len - 2; i++) printf("-"); printf("\n");
					for (int i = 0; i < len - numDig(den); i++) printf(" "); printf("%d\n", den);
				}
			}
			else {
				printf("- %d\n", parteEntera(ans));
			}
		}
		else {
			if (tieneFraccion) {
				if (tieneEntero) {
					int entero = parteEntera(ans);
					int num = sobraN(ans);
					int den = ans.d;

					len = numDig(entero) + max(numDig(num), numDig(den));

					for (int i = 0; i < len - numDig(num); i++) printf(" "); printf("%d\n", num);
					printf("%d", entero); for (int i = 0; i < len - numDig(entero); i++) printf("-"); printf("\n");
					for (int i = 0; i < len - numDig(den); i++) printf(" "); printf("%d\n", den);
				}
				else {
					int num = sobraN(ans);
					int den = ans.d;

					len = max(numDig(num), numDig(den));

					for (int i = 0; i < len - numDig(num); i++) printf(" "); printf("%d\n", num);
					for (int i = 0; i < len; i++) printf("-"); printf("\n");
					for (int i = 0; i < len - numDig(den); i++) printf(" "); printf("%d\n", den);
				}
			}
			else {
				printf("%d\n", parteEntera(ans));
			}
		}
	}
}