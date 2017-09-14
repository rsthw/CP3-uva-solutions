#include <iostream>
#include <iomanip>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 5 * 1e4;

int dir[N];
int vis[N];
int cuantos[N];
int T[N];

void init(int n) {
	memset(dir, 0, N * sizeof(int));
	memset(vis, 0, N * sizeof(int));
	memset(cuantos, 0, N * sizeof(int));
	memset(T, 0, N * sizeof(int));
}

void vis2(int pos) {
	vis[pos] = 2;
	if (cuantos[dir[pos]] == 0) {
		vis2(dir[pos]);
	}
	cuantos[pos] = cuantos[dir[pos]];
}

void visitar(int pos, int t) {
	vis[pos] = 1;
	T[pos] = t;
	if (vis[dir[pos]] == 2) {
		cuantos[pos] = cuantos[dir[pos]]+1;
	}
	else if (vis[dir[pos]] == 1) {
		cuantos[dir[pos]] = T[pos]-T[dir[pos]] + 1;
		vis2(dir[dir[pos]]);
	}
	else {
		visitar(dir[pos], t + 1);
		if(!cuantos[pos])
			cuantos[pos] = cuantos[dir[pos]] + 1;
	}
	vis[pos] = 2;

}

int main() {
	int t; cin >> t;
	int tc = 1;
	while (t--) {
		int n; cin >> n;
		init(n);
		vis[0] = 0;
		for (int i = 0; i < n; i++) {
			int st, ed; cin >> st >> ed;
			dir[st] = ed;
		}

		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				visitar(i, 1);
			}
		}
		/*
		for (int i = 1; i <= n; i++) { cout << cuantos[i] << " ";} cout << "\n";//*/
		int ans = 0;
		int best = 0;
		for (int i = 1; i <= n; i++) {
			if (cuantos[i] > best) {
				ans = i;
				best = cuantos[i];
			}
		}
		cout << "Case " << tc++ << ": " << ans << "\n";
	}
}