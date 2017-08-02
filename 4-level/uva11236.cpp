#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
using ll = long long;
const ll cota = 2000;
const ll exac = 1000000;

vector<double> vals;


void generate() {
	// Generate all posibilities
	// Generation time: less than 3 minutes
	for (ll i = 1; i <= cota; i++) {
		if (i*i*i*i > cota*exac) break;
		for (ll j = i; j <= cota-i; j++) {
			if (i*j*j*j > cota*exac) break;
			for (ll k = j; k <= cota-i-j; k++) {
				if (i*j*k*k > cota*exac) break;

				if (i*j*k - exac == 0) continue;
				ll m = (exac*(i + j + k)) / ((i*j*k) - exac);
				
				if (m >= k && m <= cota-i-j-k && i*j*k*m == (i + j + k + m)*exac) {
					cout <<setprecision(2)<<fixed<< (double)i/(double)100 << " " << (double)j / (double)100 << " " << (double)k / (double)100 << " " << (double)m / (double)100 << "\n";
				}
			}
		}
	}
}

int main() {
	generate();
}