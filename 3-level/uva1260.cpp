#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1003;

int arr[N];
int n;

class Sol1 {
public:
	static int solve() {
		int ans = 0;
		for (int i = 1; i < n; i++) {
			int ac = 0;
			for (int j = 0; j < i; j++) {
				if (arr[j] <= arr[i]) ac++;
			}
			ans += ac;
		}
		return ans;
	}
};

void readCase() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

int main() {
	cin.sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		readCase();
		int ans = Sol1::solve();
		cout << ans << "\n";
	}
}