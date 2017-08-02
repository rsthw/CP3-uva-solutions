#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;


void backtrack(int col, int filas, int diagSum, int diagRes, vector<int> &sol, set<vector<int> > &todas) {
	if (col >= 8) {
		todas.insert(sol);
		return;
	}

	// filas
	for (int i = 0; i < 8; i++) {
		// checar que la fila no este ocupada
		if ((!(filas & (1 << i)))
			// checar que ninguna diagonal este ocupada
			&& (!(diagSum & (1<<(i+col))))
			&& (!(diagRes & (1<<(i-col+8))))
			) {
			// asignarlo
			sol[col] = i;
			backtrack(col + 1, (filas | (1 << i)), (diagSum | (1 << (i + col))), (diagRes | (1 << (i - col + 8))), sol, todas);
		}
	}
}

void genera(set<vector<int> > &todas) {
	int filas = 0, diagSum = 0, diagRes = 0;
	vector<int> sol(8,0);
	
	todas.clear();

	backtrack(0, filas, diagSum, diagRes, sol, todas);
}

int dif(vector<int> &a, vector<int> &b) {
	int ans = 0;
	for (int i = 0; i < 8; i++) {
		if (a[i] != b[i]) ans++;
	}
	return ans;
}

int main() {
	set<vector<int> > todas;
	genera(todas);

	vector<int> nums(8, 0);
	int tc = 1;
	while (cin >> nums[0]) {
		nums[0]--;
		for (int i = 1; i < 8; i++) {
			cin >> nums[i]; nums[i]--;
		}
		int ans = 1e9;
		vector<int> closest;
		for (auto &elem : todas) {
			vector<int> ac = elem;
			int d = dif(nums, ac);
			if (d < ans) {
				ans = d;
				closest = ac;
			}
		}
		cout << "Case " << tc++ << ": " << ans << "\n";
		//for (int i = 0; i < 8; i++) { cout << nums[i] << " "; }cout << "\n";
		//for (int i = 0; i < 8; i++) { cout << closest[i] << " "; }cout << "\n";
	}

}