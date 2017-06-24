#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int lft[100009];
int rght[100009];

const int ast = 0;

int main() {
	int n, q; 
	while (scanf("%d %d", &n, &q) != EOF && (n || q)) {
		for (int i = 1; i <= n; i++) {
			lft[i] = i - 1;
			rght[i] = i + 1;
		}
		
		lft[1] = ast;
		rght[n] = ast;


		while (q--) {
			int st, ed; scanf("%d %d", &st, &ed);

			if (lft[st] == ast) printf("* ");
			else printf("%d ", lft[st]);

			if (rght[ed] == ast) printf("*\n");
			else printf("%d\n", rght[ed]);

			// now connect the one in the left with the one in the right
			rght[lft[st]] = rght[ed];
			lft[rght[ed]] = lft[st];
		}
		printf("-\n");
	}

}