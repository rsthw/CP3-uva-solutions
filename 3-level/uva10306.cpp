#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
const int K = 303;

int conVal[45], infoVal[45];

int DP[K][K][K];

void init() {
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < K; k++) {
				DP[i][j][k] = 0;
			}
		}
	}
}

int solve(int con, int info, int total, int dinero, int k) {
	if (total == dinero) {
		return 0;
	}
	if (DP[con][info][dinero] != 0) return DP[con][info][dinero];

	//cout << "Solve with " << con << ", " << info << ", " << total << ", " << dinero << "\n";

	int ans = 1e9;
	for (int i = 0; i < k; i++) {
		if (conVal[i] > 300 || infoVal[i] > 300) continue;

		int total2 = (con + conVal[i])*(con + conVal[i])
			+ (info + infoVal[i])*(info + infoVal[i]);

		if (total2 > dinero) continue;

		int posAns = solve(con + conVal[i], info + infoVal[i], total2, dinero, k);
		if (posAns == -1) continue;

		ans = min(ans, posAns + 1);
	}
	if (ans == 1e9) ans = -1;
	DP[con][info][dinero] = ans;
	return ans;
}

int main() {
	int tc; cin >> tc;
	while (tc--) {
		init();
		int k, dinero; cin >> k >> dinero;
		dinero = dinero*dinero;

		for (int i = 0; i < k; i++) {
			cin >> conVal[i] >> infoVal[i];
		}

		int ans = solve(0, 0, 0, dinero, k);
		if (ans == -1) cout << "not possible\n";
		else cout << ans << "\n";
	}
}