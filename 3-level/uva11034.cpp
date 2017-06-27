#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;



int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int l, m; scanf("%d %d", &l, &m); l *= 100;
		char dir[15];

		queue<int> left, right;

		for (int i = 0; i < m; i++) {
			int len; scanf("%d %s", &len, dir);
			if (dir[0] == 'l') {
				left.push(len);
			}
			else {
				right.push(len);
			}
		}

		// simular
		bool barcoLeft = true;

		int ans = 0;
		while (!left.empty() || !right.empty()) {
			// subir carros hasta que ya no se pueda
			if (barcoLeft) {
				int total = 0;
				while (!left.empty() && left.front() + total <= l) {
					total += left.front(); left.pop();
				}
			}
			else {
				int total = 0;
				while (!right.empty() && right.front() + total <= l) {
					total += right.front(); right.pop();
				}
			}

			// moverse al otro lado
			barcoLeft = barcoLeft ^ true;
			ans++;
		}

		printf("%d\n", ans);
	}
}