#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
using ll = long long;

int denominaciones[5] = { 1,5,10,25,50 };

const int D = 3 * 1e4 + 9;

ll DP[6][D];

ll solve(int numDen, int dinero) {
	if (numDen == 1) return 1;
	if (DP[numDen][dinero] > 0) return DP[numDen][dinero];

	int iter = 0;
	int total = 0;

	ll ans = 0;
	while (total <= dinero) {
		ans += solve(numDen - 1, dinero - total);
		iter++;
		total += denominaciones[numDen - 1];
	}
	DP[numDen][dinero] = ans;
	return ans;
}


int main() {
	int dinero;
	while (cin >> dinero) {
		ll ans = solve(5, dinero);
		if (ans == 1) cout << "There is only 1 way to produce " << dinero << " cents change.\n";
		else cout << "There are " << ans << " ways to produce " << dinero << " cents change.\n";
	}
}