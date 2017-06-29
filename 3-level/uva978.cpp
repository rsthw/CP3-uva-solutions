#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int t; scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		if (tc > 1) printf("\n");
		int bat, gre, blu; scanf("%d %d %d", &bat, &gre, &blu);

		priority_queue<int> greArm, bluArm;
		for (int i = 0; i < gre; i++) {
			int nxt; scanf("%d", &nxt);
			greArm.push(nxt);
		}
		for (int i = 0; i < blu; i++) {
			int nxt; scanf("%d", &nxt);
			bluArm.push(nxt);
		}

		while (!greArm.empty() && !bluArm.empty()) {
			int fights = min(bat, (int)min((int)greArm.size(), (int)bluArm.size()));

			vector<int> G, B;
			for (int i = 0; i < fights; i++) {
				G.push_back(greArm.top()); greArm.pop();
				B.push_back(bluArm.top()); bluArm.pop();
			}

			for (int i = 0; i < fights; i++) {
				if (G[i] > B[i]) {
					greArm.push(G[i] - B[i]);
				}
				else if (G[i] < B[i]) {
					bluArm.push(B[i] - G[i]);
				}
			}
		}

		if (greArm.empty() && bluArm.empty()) {
			printf("green and blue died\n");
		}
		else if (greArm.empty()) {
			printf("blue wins\n");
			while(!bluArm.empty()){
				printf("%d\n", bluArm.top()); bluArm.pop();
			}
		}
		else {
			printf("green wins\n");
			while(!greArm.empty()){
				printf("%d\n", greArm.top()); greArm.pop();
			}
		}
	}
	
}