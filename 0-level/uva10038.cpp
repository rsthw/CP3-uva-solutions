#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		vector<int> nums(n, 0);
		int ant; scanf("%d", &ant);
		
		if (n == 1) {
			printf("Jolly\n");
			continue;
		}

		bool ok = true;
		for (int i = 1; i < n; i++) {
			int nxt; scanf("%d", &nxt);
			
			int dif = abs(ant - nxt);
			if (dif > 0 && dif < n) {
				if (nums[dif] != 0) ok = false;
				nums[dif] = 1;
			}
			else {
				ok = false;
			}

			ant = nxt;
		}

		if (ok) printf("Jolly\n");
		else printf("Not jolly\n");
	}
}