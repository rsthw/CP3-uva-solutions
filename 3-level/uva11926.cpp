#include <iostream>
#include <stdio.h>
#include <bitset>
#include <algorithm>
using namespace std;

bitset<1000009> usado;

bool pinta(int st, int ed) {
	for (int i = st; i < ed; i++) {
		if (usado[i]) {
			return false;
		}
		usado[i] = true;
	}
	return true;
}

int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF && (n || m)) {
		usado.reset();
		//cout << usado << endl;
		//cout << usado.count() << endl;

		bool ok = true;
		for (int i = 0; i < n; i++) {
			int st, ed; scanf("%d %d", &st, &ed);
			if (ok) {
				ok = pinta(st, ed);
			}
		}

		for (int i = 0; i < m; i++) {
			int st, ed, rep; scanf("%d %d %d", &st, &ed, &rep);
			if (ok) {
				for (int i = 0; i*rep + st <= 1000000; i++) {
					ok = pinta(i*rep + st, min(i*rep + ed, 1000000));
					if (!ok) break;
				}
			}
		}

		if (ok) printf("NO CONFLICT\n");
		else printf("CONFLICT\n");

	}
}