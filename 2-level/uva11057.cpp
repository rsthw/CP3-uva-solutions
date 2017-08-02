#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

const int N = 10004;
int nums[N];

int main() {
	cin.sync_with_stdio(0);
	int n, m;
	while (cin >> n) {
		for (int i = 0; i < n; i++) cin >> nums[i];
		cin >> m;

		int a, b;
		int dif = 1e9;

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (nums[i] + nums[j] == m) {
					int x = min(nums[i], nums[j]), y = max(nums[i], nums[j]);
					if (y - x < dif) {
						a = x; b = y;
						dif = y - x;
					}
				}
			}
		}


		cout << "Peter should buy books whose prices are " << a << " and " << b << ".\n\n";
	}
}