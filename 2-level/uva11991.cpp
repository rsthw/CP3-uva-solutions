#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {
		map<int, vector<int> > pos;
		for (int i = 1; i <= n; i++) {
			int num; scanf("%d", &num);
			pos[num].push_back(i);
		}
		for (int i = 0; i < m; i++) {
			int k, v; scanf("%d %d", &k, &v);
			
			if (pos[v].size() < k) printf("0\n");
			else {
				printf("%d\n", pos[v][k - 1]);
			}
		}
	}
}