#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int N = 1024009;
const int nada = -1;
const int buccaneer = 1;
const int barbary = 0;
const int flipNum = 2;

int arr[N];
int tree[4 * N];
int lazy[4 * N];

void init(int node, int a, int b) {
	if (a > b) return;
	if (a == b) {
		tree[node] = arr[a];
		lazy[node] = nada;
		return;
	}
	int ln = node << 1;
	int rn = ln | 1;
	int mid = (a + b) >> 1;

	init(ln, a, mid);
	init(rn, mid + 1, b);

	tree[node] = tree[ln] + tree[rn];
	lazy[node] = nada;
}

bool rangoCorrecto(int a, int b, int st, int ed) {
	if (a > b || st > ed || b<st || a > ed) return false;
	return true;
}

void flipLazy(int node) {
	if (lazy[node] == nada) {
		lazy[node] = flipNum;
	}
	else if (lazy[node] == flipNum) {
		lazy[node] = nada;
	}
	else if (lazy[node] == buccaneer) {
		lazy[node] = barbary;
	}
	else if (lazy[node] == barbary) {
		lazy[node] = buccaneer;
	}
}

void propagar(int node, int a, int b) {
	if (a > b) return;
	int ln = node << 1;
	int rn = ln | 1;
	int rng = b - a + 1;

	if (lazy[node] != nada) {
		if (lazy[node] == buccaneer) {
			tree[node] = rng;
			lazy[node] = nada;
			if (rng > 1) {
				lazy[ln] = buccaneer;
				lazy[rn] = buccaneer;
			}
		}
		else if (lazy[node] == barbary) {
			tree[node] = 0;
			lazy[node] = nada;
			if (rng > 1) {
				lazy[ln] = barbary;
				lazy[rn] = barbary;
			}
		}
		else if (lazy[node] == flipNum) {
			tree[node] = rng - tree[node];
			lazy[node] = nada;
			if (rng > 1) {
				flipLazy(ln);
				flipLazy(rn);
			}
		}
	}
}

void color(int node, int a, int b, int st, int ed, int c) {
	propagar(node, a, b);
	if (!rangoCorrecto(a, b, st, ed)) return;

	if (st <= a && b <= ed) {
		lazy[node] = c;
		propagar(node, a, b);
		return;
	}

	int ln = node << 1;
	int rn = ln | 1;
	int mid = (a + b) >> 1;

	color(ln, a, mid, st, ed, c);
	color(rn, mid + 1, b, st, ed, c);

	tree[node] = tree[ln] + tree[rn];
}

void flip(int node, int a, int b, int st, int ed) {
	propagar(node, a, b);
	if (!rangoCorrecto(a, b, st, ed)) return;

	if (st <= a && b <= ed) {
		flipLazy(node);
		propagar(node, a, b);
		return;
	}

	int ln = node << 1;
	int rn = ln | 1;
	int mid = (a + b) >> 1;

	flip(ln, a, mid, st, ed);
	flip(rn, mid + 1, b, st, ed);

	// recuerda asegurar que ambos lados esten actualizados
	tree[node] = tree[ln] + tree[rn];
}

int query(int node, int a, int b, int st, int ed) {
	if (!rangoCorrecto(a, b, st, ed)) return 0;
	propagar(node, a, b);

	if (st <= a && b <= ed) return tree[node];

	int ln = node << 1;
	int rn = ln | 1;
	int mid = (a + b) >> 1;

	int q1 = query(ln, a, mid, st, ed);
	int q2 = query(rn, mid + 1, b, st, ed);

	return q1 + q2;
}

void actualizarTest(int node, int a, int b) {
	if (a > b) return;
	
	propagar(node, a, b);

	if (a == b) {
		arr[a] = tree[node];
		return;
	}
	int ln = node << 1;
	int rn = ln | 1;
	int mid = (a + b) >> 1;

	actualizarTest(ln, a, mid);
	actualizarTest(rn, mid + 1, b);

	// recuerda asegurar que ambos lados esten actualizados
	tree[node] = tree[ln] + tree[rn];
}

int main() {
	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n = 0;

		int m; cin >> m;
		// read pirates
		while (m--) {
			int w; 
			string line; 
			cin >> w >> line;

			for (int i = 0; i < w; i++) {
				for (int j = 0; j < line.size(); j++) {
					arr[n++] = (line[j] - '0');
				}
			}
		}
		// test
		// for (int i = 0; i < n; i++) cout << arr[i] << " "; cout << endl;

		// create segTree
		init(1, 0, n - 1);

		int q; cin >> q;
		cout << "Case " << tc << ":" << endl;
		// read queries
		int sId = 1;
		while (q--) {
			char op; int st, ed; cin >> op >> st >> ed;
			
			if (op == 'F') { // Buccaneer
				color(1, 0, n - 1, st, ed, buccaneer);
			}
			else if (op == 'E') { // Barbary
				color(1, 0, n - 1, st, ed, barbary);
			}
			else if (op == 'I') { // Inverse
				flip(1, 0, n - 1, st, ed);
			}
			else { // Query, how many buccaneers, how many 1
				int ans = query(1, 0, n - 1, st, ed);
				cout << 'Q' << sId++ << ": " << ans << endl;
			}

			

			// test
			//actualizarTest(1, 0, n - 1);
			//for (int i = 0; i < n; i++) cout << arr[i] << " "; cout << endl;
			
		}
	}
}