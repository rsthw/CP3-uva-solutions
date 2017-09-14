#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
const int N = 105;

vector<int> G[N];
int vis[N];
int grade[N];

void init() {
	for (int i = 0; i < N; i++) {
		G[i].clear();
		vis[i] = 0;
		grade[i] = 0;
	}
}

int main() {
	int n, m;
	while (cin >> n >> m && (n||m)) {
		init();
		for (int i = 0; i < m; i++) {
			int st, ed; cin >> st >> ed;
			G[st].push_back(ed);
			grade[ed]++;
		}

		vector<int> ans;
		while (ans.size() < n) {
			for (int i = 1; i <= n; i++) {
				if (grade[i] == 0 && !vis[i]) {
					vis[i] = 1;
					ans.push_back(i);
					for (int j = 0; j < G[i].size(); j++) {
						int nxt = G[i][j];
						grade[nxt]--;
					}
				}
			}
		}
		cout << ans[0];
		for (int i = 1; i < ans.size(); i++) {
			cout <<" "<< ans[i];
		}cout << "\n";
	}
}