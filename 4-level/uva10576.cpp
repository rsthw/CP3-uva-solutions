#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

ll calcula(int st, int ed, vector<ll> &nums) {
	ll ans = 0;
	for (int i = st; i <= ed; i++) {
		ans += nums[i];
	}
	return ans;
}

ll backtrack(int month, vector<ll> &nums, int s, int d) {
	ll ac = calcula(0, month - 1, nums);
	ll last5 = calcula(max(0, month - 5), month - 1, nums);

	if (month >= 5 && last5 >= 0) return -1e9;
	if (month >= 12) {
		return ac;
	}


	ll ans;

	nums.push_back(s);
	ans = backtrack(month + 1, nums, s, d);
	nums.pop_back();

	nums.push_back(-d);
	ans = max(ans, backtrack(month + 1, nums, s, d));
	nums.pop_back();

	return ans;
}

ll solve(vector<ll> &nums, int s, int d) {
	ll ans;
	
	nums.push_back(s);
	ans = backtrack(1, nums, s, d);
	nums.pop_back();
	nums.push_back(-d);
	ans = max(ans, backtrack(1, nums, s, d));
	nums.pop_back();

	return ans;
}

int main() {
	ll s, d;
	vector<ll> nums;
	while (cin >> s >> d) {
		nums.clear();

		ll best = solve(nums, s, d);
		if(best >= 0)
			cout << best << "\n";
		else cout << "Deficit\n";
	}
}