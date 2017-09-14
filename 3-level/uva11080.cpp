#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <utility>
using namespace std;
const int N = 203;
vector<int> G[N];
int n, m;

void init() {
	for (int i = 0; i < N; i++) {
		G[i].clear();
	}
}

void colorear(int pos, int C1, int C2, vector<int> &color, bool &posible) {
	color[pos] = C1;
	for (int i = 0; i < G[pos].size(); i++) {
		int nxt = G[pos][i];
		if (color[nxt] == -1) {
			colorear(nxt, C2, C1, color, posible);
		}
		else if (color[nxt] == color[pos]) {
			posible = false;
		}
	}
}

void resolver(int pos, int C1, int C2, vector<int> &color, int &ans, bool &posible, vector<int> &obli) {
	// colorear bipartitamente la CC de pos
	colorear(pos, C1, C2, color, posible);

	// contar cuantos hay de cada uno
	int T1 = 0; int T2 = 0;
	for (int i = 0; i < n; i++) {
		if (color[i] == C1) T1++;
		else if (color[i] == C2) T2++;
	}

	// ver si hay uno obligatorio en esta CC
	int val = -1;
	for (auto &x : obli) {
		if (color[x] == C1 || color[x] == C2) {
			if (val == -1) {
				val = color[x];
			}
			else if (color[x] != val) {
				posible = false;
			}
		}
	}
	// incrementar ans
	if (val == -1) {
		if (T2 == 0) ans += T1;
		else ans += min(T1, T2);
	}
	else if (val == C1) {
		ans += T1;
	}
	else if (val == C2) {
		ans += T2;
	}
}

int main() {
	int t; cin >> t;
	while (t--) {
		init();
		cin >> n >> m;
		vector<int> obli;

		// leer y verificar los que deben de estar con guardia
		for (int i = 0; i < m; i++) {
			int st, ed; cin >> st >> ed;
			if (st == ed) {
				obli.push_back(st);
			}
			else {
				G[st].push_back(ed);
				G[ed].push_back(st);
			}
		}

		// hacer el proceso por cada componente
		vector<int> color(n, -1);
		int idx = 1;
		int ans = 0;
		bool posible = true;
		for (int i = 0; i < n; i++) {
			if (color[i] == -1) {
				resolver(i, idx, idx + 1, color, ans, posible, obli);
				idx += 2;
			}
		}

		if (posible) cout << ans << "\n";
		else cout << "-1\n";
	}
}