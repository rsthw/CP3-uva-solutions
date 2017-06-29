#include <iostream>
#include <set>
#include <stdio.h>
using namespace std;

int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF && (n || m)) {
		set<int> nums;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int nxt; scanf("%d", &nxt);
			if (nums.find(nxt) != nums.end()) ans++;
			nums.insert(nxt);
		}
		for (int i = 0; i < m; i++) {
			int nxt; scanf("%d", &nxt);
			if (nums.find(nxt) != nums.end()) ans++;
			nums.insert(nxt);
		}
		printf("%d\n", ans);
	}
}