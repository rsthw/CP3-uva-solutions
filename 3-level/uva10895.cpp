#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
using namespace std;

int contar(vector<vector<int> > &mat, int col, vector<int> &idx, vector<int> &vals, int m) {
	idx.clear();
	vals.clear();

	int ans = 0;
	for (int i = 0; i < m; i++) {
		if (mat[i][col] != 0) {
			ans++;
			idx.push_back(i+1);
			vals.push_back(mat[i][col]);
		}
	}
	return ans;
}

int main() {
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF) {
		vector<vector<int> > mat(m, vector<int>(n, 0));
		vector<int> idx;
		for (int i = 0; i < m; i++) {
			int total; scanf("%d", &total);
			idx.resize(total);
			for (int j = 0; j < total; j++) {
				scanf("%d", &idx[j]);
			}
			for (int j = 0; j < total; j++) {
				int num; scanf("%d", &num);
				mat[i][idx[j] - 1] = num;
			}
		}
		/*
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << setw(3) << mat[i][j];
			}
			cout << endl;
		}//*/

		vector<int> vals;

		printf("%d %d\n", n, m);
		for (int i = 0; i < n; i++) {
			int total = contar(mat, i, idx, vals, m);
			if (total) {
				printf("%d ", total);
				//printf("%d %d\n", idx.size(), vals.size());

				for (int j = 0; j < idx.size() - 1; j++) {
					printf("%d ", idx[j]);
				}
				printf("%d\n", idx[idx.size() - 1]);

				for (int j = 0; j < vals.size() - 1; j++) {
					printf("%d ", vals[j]);
				}
				printf("%d\n", vals[vals.size() - 1]);
			}
			else {
				printf("0\n\n");
			}
		}
	}
}