#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
const int N = 13;

struct frac {
	int nom, den;
};

int fr[N], rea[N];

bool menor(frac &a, frac &b) {
	return a.nom*b.den < a.den*b.nom;
}

frac operator/(frac a, frac b) {
	frac ans;
	ans.nom = a.nom*b.den;
	ans.den = a.den*b.nom;
	return ans;
}

int main() {
	cin.sync_with_stdio(0);
	int f, r;
	while (cin >> f && f) {
		cin >> r;
		for (int i = 0; i < f; i++) {
			cin >> fr[i];
		}
		for (int i = 0; i < r; i++) {
			cin >> rea[i];
		}

		vector<frac> drives;
		frac ac;
		for (int i = 0; i < f; i++) {
			for (int j = 0; j < r; j++) {
				ac.nom = rea[j]; ac.den = fr[i];
				drives.push_back(ac);
			}
		}
		sort(drives.begin(), drives.end(), menor);

		//for (int i = 0; i < drives.size(); i++) cout << drives[i].nom / ((double)drives[i].den) << " "; cout << endl;

		// search for max spread
		frac maxSpread; maxSpread.nom = 0; maxSpread.den = 1;
		for (int i = 1; i < drives.size(); i++) {
			frac drive = drives[i] / drives[i - 1];
			if (menor(maxSpread, drive)) {
				maxSpread = drive;
			}
		}
		double ans = (double)maxSpread.nom / (double)maxSpread.den;
		cout << setprecision(2) << fixed << ans << "\n";
	}
}