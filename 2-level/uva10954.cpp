#include <iostream>
#include <queue>
#include <stdio.h>
#include <functional>
using namespace std;

int main() {
	
	int n;
	while (scanf("%d", &n) != EOF && n) {
		priority_queue<int, vector<int>, greater<int> > pq;
		for (int i = 0; i < n; i++) {
			int nxt; scanf("%d", &nxt);
			pq.push(nxt);
		}
		long long total = 0;
		while (pq.size() > 1) {
			int a = pq.top(); pq.pop();
			int b = pq.top(); pq.pop();
			total += a + b;
			pq.push(a + b);
		}
		printf("%d\n", total);
	}
	
}