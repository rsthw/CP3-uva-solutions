#include <iostream>
#include <stack>
#include <iomanip>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;

ll C[N];

struct stack_sum {
	stack<int> nums;
	int sum;
};

void popsts(stack_sum &sts) {
	int nxt = sts.nums.top(); sts.nums.pop();

	sts.sum -= nxt;

}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> C[i];
		}

		stack_sum sts; sts.sum = 0; sts.nums = stack<int>();

		for (int i = 0; i < n; i++) {
			int val = C[i];
			while (sts.sum > val) {
				popsts(sts);
			}
			sts.nums.push(val);
			sts.sum += val;
		}

		cout << sts.nums.size() << "\n";
	}
}