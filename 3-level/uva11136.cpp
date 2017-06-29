#include <iostream>
#include <stdio.h>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
using ii = pair<int, int>;

int primero(set<ii> &S) {
	set<ii>::iterator it = S.begin();

	ii val = *it;

	S.erase(val);
	
	return val.first;
}
int ultimo(set<ii> &S) {
	set<ii>::iterator it = S.end(); it--;

	ii val = *it;

	S.erase(val);

	return val.first;
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF && n) {
		set<ii> nums;

		int idx = 1;
		long long total = 0;

		for (int i = 0; i < n; i++) {
			int m; scanf("%d", &m);
			for (int j = 0; j < m; j++) {
				int nxt; scanf("%d", &nxt);

				nums.insert(ii(nxt, idx++));
			}

			// al final del dia, sacar el minimo y maximo
			int peq = primero(nums);
			int gran = ultimo(nums);

			
			total += (gran - peq);
		}

		printf("%lld\n", total);

	}
}