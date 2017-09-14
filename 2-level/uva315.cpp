#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;

const int N = 103;

vector<int> G[N];

int LO[N], NUM[N], P[N];
int dfsRoot, rootChild;
int t;

int ISART[N];

void init() {
	t = 1;
	for (int i = 0; i < N; i++) {
		G[i].clear();
		LO[i] = 1e9;
		NUM[i] = 1e9;
		P[i] = 0;
		ISART[i] = 0;
	}
}

void dfs(int u) {
	LO[u] = NUM[u] = t++;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (NUM[v] == 1e9) {
			P[v] = u;
			//if (u == 1) cout << "RootChild, rt = "<<dfsRoot<<"\n";
			if (u == dfsRoot) rootChild++;
			dfs(v);
			if (LO[v] >= NUM[u]) {
				ISART[u] = 1;
			}
			LO[u] = min(LO[u], LO[v]);
		}
		else if (P[u] != v) {
			//cout << "P[" << u << "] != " << v << "\n";
			LO[u] = min(LO[u], NUM[v]);
		}
	}
}

int main() {
	int n;
	string line;
	
	while (getline(cin, line)) {
		stringstream ss1(line); ss1 >> n;
		if (n == 0) break;

		init();

		int st, ed;
		while (getline(cin, line)) {
			stringstream ss(line); ss >> st;
			if (st == 0) break;
			while (ss >> ed) {
				G[st].push_back(ed);
				G[ed].push_back(st);
			}
		}

		for (int i = 1; i <= n; i++) {
			if (NUM[i] == 1e9) {
				dfsRoot = i;
				rootChild = 0;
				//cout << "root = " << dfsRoot << ", child = " << rootChild << "\n";
				dfs(i);
				//cout << "root = " << dfsRoot << ", child = " << rootChild << "\n";
				ISART[i] = (rootChild > 1)? 1: 0;
			}
		}
		/*
		for (int i = 1; i <= n; i++) {
			cout << i << ": "<<LO[i]<<", "<<NUM[i]<<", " << ISART[i] << "\n";
		}//*/

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (ISART[i]) ans++;
		}
		cout << ans << "\n";

	}

}