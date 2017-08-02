#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

double p, q, r, s, t, u;
const double eps = 0.000000001;

// esta funcion es decreciente
double f(double x) {
	return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main() {
	cin.sync_with_stdio(0);
	while (cin >> p >> q >> r >> s >> t >> u) {
		double hi = 0, lo = 1;
		if (f(hi)*f(lo) > 0) {
			cout << "No solution\n"; continue;
		}

		while (lo - hi > eps) {
			double mid = (lo + hi) / 2;
			double val = f(mid);
			if (val > 0) hi = mid;
			else if (val < 0) lo = mid;
			else {
				lo = mid; hi = mid;
			}
		}

		cout << setprecision(4) << fixed << lo<<"\n";
	}
}