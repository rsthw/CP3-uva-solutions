#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int equal(vector<vector<char> > &m1, vector<vector<char> > &m2, int x, int y) {
	for (int i = 0; i < m2.size(); i++) {
		for (int j = 0; j < m2.size(); j++) {
			if (m1[x + i][y + j] != m2[i][j]) return false;
		}
	}
	return true;
}

int contar(vector<vector<char> > &m1, vector<vector<char> > &m2) {
	int s1 = m1.size();
	int s2 = m2.size();

	int ans = 0;

	for (int i = 0; i <= s1 - s2; i++) {
		for (int j = 0; j <= s1 - s2; j++) {
			if (equal(m1, m2, i, j)) ans++;
		}
	}
	return ans;
}


void girar(vector<vector<char> > &m) {
	int sz = m.size();
	vector<vector<char> > nm(sz, vector<char>(sz, ' '));
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			nm[j][sz - i - 1] = m[i][j];
		}
	}
	m = nm;
}

int main() {
	int N, n;
	vector<vector<char> > mat, m2;
	while (scanf("%d %d", &N, &n) != EOF && (n || N)) {
		mat.assign(N, vector<char>(N, ' '));
		m2.assign(n, vector<char>(n, ' '));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf(" %c", &mat[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf(" %c", &m2[i][j]);
			}
		}

		vector<int> ans(4, 0);
		for (int i = 0; i < 4; i++) {
			ans[i] = contar(mat, m2);
			girar(m2);
		}
		printf("%d", ans[0]);
		for (int i = 1; i < 4; i++) {
			printf(" %d", ans[i]);
		} printf("\n");

	}
	
}