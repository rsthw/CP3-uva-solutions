#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

const int N = 103;
set<int> G[N];

void init() {
	for (int i = 0; i < N; i++) {
		G[i].clear();
	}
}

int main() {
	string nxt, A, B;
	int n, m;
	int tc = 1;
	while (cin >> n) {
		init();
		map<string, int> ID;
		map<int, string> NAME;
		vector<int> grado(n+1, 0);

		int idx = 1;

		for (int i = 0; i < n; i++) {
			cin >> nxt;
			NAME[idx] = nxt;
			ID[nxt] = idx++;
		}

		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> A >> B;
			int st, ed;
			if (ID.find(A) == ID.end() || ID.find(B) == ID.end()) {
				continue;
			}
			st = ID[A]; ed = ID[B];
			if (G[st].find(ed) == G[st].end()) {
				G[st].insert(ed);
				grado[ed]++;
			}
		}

		vector<int> vis(n+1, 0);
		vector<string> ans;

		for(int k = 0; k<n; k++){

			for (int i = 1; i <= n; i++) {
				if (grado[i] <= 0 && !vis[i]) {
					vis[i] = 1;
					ans.push_back(NAME[i]);
					for (auto& v : G[i]) {
						grado[v]--;
					}
					break;
				}
			}

		}

		cout << "Case #"<<tc++<<": Dilbert should drink beverages in this order:";
		for (int i = 0; i < ans.size(); i++) {
			cout << " " << ans[i];
		}
		cout << ".\n\n";
	}
}
