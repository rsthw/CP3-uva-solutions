#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
using namespace std;
#define pb push_back
const int V = 303;

vector<int> G[V];

void init() {
	for (int i = 0; i < V; i++) {
		G[i].clear();
	}
}

void colorear(int pos, int C1, int C2, vector<int> &color, bool &ok) {
	color[pos] = C1;
	for (int i = 0; i < G[pos].size(); i++) {
		int nxt = G[pos][i];
		if (!color[nxt]) {
			colorear(nxt, C2, C1, color, ok);
		}
		else if (color[nxt] == color[pos]) {
			ok = false;
		}
	}
}

int main() {
	int v;
	while (cin >> v && v) {
		init();
		int st, ed;
		while (cin >> st >> ed && (st || ed)) {
			G[st].pb(ed);
			G[ed].pb(st);
		}

		bool ok = true;
		// buscar si hay biparticion
		vector<int> color(v + 1, 0);
		colorear(1, 1, 2, color, ok);

		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
}
