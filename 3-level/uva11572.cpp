#include <iostream>
#include <map>
#include <queue>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		map<int, int> nums;
		queue<int> anteriores;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int k; scanf("%d", &k);
			if (nums.find(k) == nums.end()) nums[k] = 0;

			if (nums[k] == 0) {
				nums[k] = 1;
				anteriores.push(k);
			}
			else {
				while (anteriores.front() != k) {
					nums[anteriores.front()] = 0;
					anteriores.pop();
				}
				// quitar la k
				anteriores.pop();

				// agregar el numero
				anteriores.push(k);
			}
			ans = max((int)anteriores.size(), ans);
		}

		printf("%d\n", ans);
	}
}