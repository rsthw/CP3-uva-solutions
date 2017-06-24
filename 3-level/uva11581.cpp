#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int sumM2(int x, int y, vector<vector<int> > &mat) {
	int ans = 0;
	for (int i = -1; i <= 1; i++) {
		if (i == 0) continue;
		if (x + i >= 0 && x + i <= 2) {
			ans += mat[x + i][y];
		}
		if (y + i >= 0 && y + i <= 2) {
			ans += mat[x][y + i];
		}
	}
	return ans%2;
}

void f(vector<vector<int> > &mat) {
	vector<vector<int> > nm(3, vector<int>(3, 0));

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			nm[i][j] = sumM2(i, j, mat);
		}
	}

	mat = nm;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		vector<vector<int> > mat(3, vector<int>(3, 0));
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				char tmp; scanf(" %c", &tmp);
				if (tmp == '0') mat[i][j] = 0;
				else if (tmp == '1') mat[i][j] = 1;
			}
		}

		map < vector<vector<int> >, int> getIdx;
		int idx = 0;

		getIdx[mat] = idx++;

		f(mat);
		while (getIdx.find(mat) == getIdx.end()) {
			getIdx[mat] = idx++;
			f(mat);
		}

		int ans = getIdx[mat] - 1;
		printf("%d\n", ans);
	}
}