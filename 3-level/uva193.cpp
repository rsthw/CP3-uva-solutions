#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <bitset>
#include <string>
using namespace std;

vector<bool> usar(vector<bool> vis, int u, vector<vector<int> > &ady) {
	vis[u] = true;
	for (int i = 0; i < ady[u].size(); i++) {
		int v = ady[u][i];
		vis[v] = true;
	}
	return vis;
}

vector<int> backtrack(int n, vector<bool> vis, vector<vector<int> > &ady, map<vector<bool>, vector<int> > &DP) {
	if (DP.find(vis) != DP.end()) return DP[vis];

	// encontrar siguiente indice no visitado
	int nxt = -1;
	for (int i = 1; i < vis.size(); i++) {
		if (!vis[i]) {
			nxt = i; break;
		}
	}

	// si ya se visitaron todos, asignarle el vacio para la grafica vacia
	if (nxt == -1) {
		DP[vis] = vector<int>();  return vector<int>();
	}

	// ya con el siguient: hay 2 posibilidades: visitarlo o no
	// visitarlo
	vector<bool> vis_tmp;

	vis_tmp = usar(vis, nxt, ady);

	vector<int> opcion1 = backtrack(n, vis_tmp, ady, DP);
	opcion1.push_back(nxt);

	// no visitarlo
	vis_tmp = vis;
	vis_tmp[nxt] = true;

	vector<int> opcion2 = backtrack(n, vis_tmp, ady, DP);

	// guardar la solucion
	if (opcion1.size() > opcion2.size()) {
		DP[vis] = opcion1;
	}
	else {
		DP[vis] = opcion2;
	}
	return DP[vis];
}

int main() {
	cin.sync_with_stdio(0);
	int t; cin >> t;

	map<vector<bool>, vector<int> > DP;
	vector<vector<int> > ady;
	vector<bool> vis;
	while (t--) {
		int n, m; cin >> n >> m;
		ady.assign(n + 1, vector<int>());
		vis.assign(n + 1, false);
		DP.clear();

		for (int i = 0; i < m; i++) {
			int st, ed; cin >> st >> ed;
			ady[st].push_back(ed);
			ady[ed].push_back(st);
		}

		vector<int> ans = backtrack(n, vis, ady, DP);

		cout << ans.size() << '\n';
		if (ans.size() > 0) {
			cout << ans[0];
			for (int i = 1; i < ans.size(); i++) {
				cout << ' ' << ans[i];
			}cout << '\n';
		}
	}
}