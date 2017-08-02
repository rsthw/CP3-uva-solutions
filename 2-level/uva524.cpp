#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPrime(int k) {
	if (!(k & 1)) return false;
	for (int i = 3; i*i <= k; i++) {
		if (!(k%i)) return false;
	}
	return true;
}

void backtrack(int pos, int n, int vis, vector<int> &nums) {
	if (pos == n && isPrime(nums[n-1]+nums[0])) {
		cout << nums[0];
		for (int i = 1; i < nums.size(); i++) {
			cout << ' ' << nums[i];
		}cout << '\n';
		return;
	}

	for (int i = (pos & 1) ? 2 : 3; i <= n; i += 2) {
		if (!(vis&(1 << i)) && isPrime(nums[pos - 1] + i)) {
			nums[pos] = i;
			backtrack(pos + 1, n, vis | (1 << i), nums);
		}
	}

}

int main() {
	cin.sync_with_stdio(0);
	int n; int tc = 1;
	vector<int> nums;
	while (cin >> n) {
		if (tc > 1) cout << '\n';
		cout << "Case " << tc++ << ":\n";

		nums.assign(n, 1);
		backtrack(1, n, 0, nums);
	}
}