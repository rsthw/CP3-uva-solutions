#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int k;
	int tc = 1;

	while (cin >> k && k) {
		if (tc > 1) cout << "\n";
		vector<int> nums(k, 0);
		for (int i = 0; i < k; i++) cin >> nums[i];

		int sz = nums.size();

		for (int a1 = 0; a1 <= sz - 6; a1++) {
			for (int a2 = a1 + 1; a2 <= sz - 5; a2++) {
				for (int a3 = a2 + 1; a3 <= sz - 4; a3++) {
					for (int a4 = a3 + 1; a4 <= sz - 3; a4++) {
						for (int a5 = a4 + 1; a5 <= sz - 2; a5++) {
							for (int a6 = a5 + 1; a6 <= sz - 1; a6++) {
								cout << nums[a1] << " " << nums[a2] << " " << nums[a3] << " " << nums[a4] << " " << nums[a5] << " " << nums[a6] << "\n";
							}
						}
					}
				}
			}
		}

		tc++;
	}
}