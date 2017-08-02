#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void findSimilar(vector<vector<char> > &common, vector<vector<char> > &grid1, vector<vector<char> > &grid2) {
	common.assign(5, vector<char>());

	for (int i = 0; i < 5; i++) {
		int id1 = 0, id2 = 0;

		while (id1 < 6 && id2 < 6) {
			if (grid1[i][id1] < grid2[i][id2]) id1++;
			else if (grid1[i][id1] > grid2[i][id2]) id2++;
			else if (grid1[i][id1] == grid2[i][id2]) {
				common[i].push_back(grid1[i][id1]);
				id1++;
				while (id1 < 6 && grid1[i][id1] == grid1[i][id1 - 1]) id1++;
				id2++;
				while (id2 < 6 && grid2[i][id2] == grid2[i][id2 - 1]) id2++;
			}
		}

	}

}

int main() {
	cin.sync_with_stdio(0);
	int t; cin >> t;

	vector<vector<char> > G1(5, vector<char>(6, ' ')), G2(5, vector<char>(6, ' '));

	vector<vector<char> > common;

	vector<int> elemPorNivel(5, 0);

	while (t--) {
		int k; cin >> k;

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> G1[j][i];
			}
		}
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> G2[j][i];
			}
		}

		for (int i = 0; i < 5; i++) {
			sort(G1[i].begin(), G1[i].end());
			sort(G2[i].begin(), G2[i].end());
		}

		findSimilar(common, G1, G2);

		/*
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < common[i].size(); j++) {
				cout << common[i][j] << " ";
			}cout << "\n";
		}//*/

		elemPorNivel[4] = common[4].size();
		for (int i = 3; i >= 0; i--) {
			elemPorNivel[i] = elemPorNivel[i + 1] * common[i].size();
		}

		// buscar el k-esimo
		if (elemPorNivel[0] < k) cout << "NO\n";
		else {
			vector<char> ans(5, ' ');

			// buscar letra por letra
			for (int i = 0; i < 4; i++) {
				// buscar la ultima que sea menor en cuanto a lexicografico
				int id = 0;
				while (elemPorNivel[i + 1] * id < k) id++; id--;

				// agregarlo
				ans[i] = common[i][id];
				// restarle
				k -= elemPorNivel[i + 1] * id;
			}

			ans[4] = common[4][k-1];

			for (int i = 0; i < 5; i++) cout << ans[i]; cout << "\n";
		}
	}
}