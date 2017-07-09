#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

const int N = 100009;

int nums[N];
int reps[N];
int anter[N];
int nxt[N];
int segTree[4 * N];

void generar(int n) {
	int rep = 0;
	int ant = -1;
	int a = 0;
	int b = 0;

	while (b < n) {
		// inicializar
		rep = 0;
		ant = b - 1;
		// siguiente
		while (b < n && nums[b] == nums[a]) {
			b++;
			rep++;
		}
		// guardar
		while (a < b) {
			reps[a] = rep;
			anter[a] = ant;
			nxt[a] = b;
			a++;
		}
	}
}

void init(int node, int l, int r) {
	if (l > r) return;
	if (l == r) {
		segTree[node] = reps[l];
		return;
	}
	int ln = node<<1;
	int rn = ln + 1;
	int mid = (l + r) >> 1;

	init(ln, l, mid);
	init(rn, mid + 1, r);

	segTree[node] = max(segTree[ln], segTree[rn]);
}

int query(int node, int l, int r, int a, int b) {
	if (l > r || r < a || l > b || a>b) return -1e9;
	if (a<=l && r <= b) {
		return segTree[node];
	}
	int ln = node << 1;
	int rn = ln + 1;
	int mid = (l + r) >> 1;

	int q1 = query(ln, l, mid, a, b);
	int q2 = query(rn, mid + 1, r, a, b);
	return max(q1, q2);
}


int main() {
	int n, q;
	while (scanf("%d", &n) != EOF && n) {
		scanf("%d", &q);

		for (int i = 0; i < n; i++) {
			scanf("%d", &nums[i]);
		}

		generar(n);
		init(1, 0, n - 1);

		for (int i = 0; i < q; i++) {
			int st, ed; scanf("%d %d", &st, &ed); st--; ed--;
			// repeticiones del primero
			int rep1 = min(nxt[st] - st, ed - st+1);
			// repeticiones del ultimo
			int repN = min(ed - anter[ed], ed - st+1);
			// repeticiones de enmedio
			int repMid = query(1, 0, n - 1, nxt[st], anter[ed]);
			


			int ans = max(rep1, max(repMid, repN));

			printf("%d\n", ans);
		}
	}
}