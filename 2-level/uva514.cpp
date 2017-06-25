#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF && n) {
		int nxt;
		while (scanf("%d", &nxt) != EOF && nxt) {
			vector<int> orden(n, 0);
			orden[0] = nxt;
			for (int i = 1; i < n; i++) {
				scanf("%d", &nxt);
				orden[i] = nxt;
			}


			// checar que esta bien
			bool ok = true;
			queue<int> orig;
			for (int i = 1; i <= n; i++) {
				orig.push(i);
			}

			stack<int> S;

			for (int i = 0; i < n; i++) {
				if (!orig.empty() && orden[i] == orig.front()) {
					orig.pop();
				}
				else if (!S.empty() && S.top() == orden[i]) {
					S.pop();
				}
				else {
					while (!orig.empty() && orden[i] != orig.front()){
						S.push(orig.front()); orig.pop();
					}

					if (orig.empty()) {
						ok = false;
						break;
					}
					else {
						orig.pop();
					}
				}
			}
			

			if (ok) printf("Yes\n");
			else printf("No\n");
		}
		printf("\n");
	}
}