#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 2003;

int nums[2 * N];

int ultimoMenor(int val, vector<int> &lista) {
	int lo = 0, hi = lista.size() - 1;
	while (lo < hi) {
		int mid = (lo + hi) >> 1;

		if (mid + 1 <= hi) mid++;

		if (lista[mid] < val) {
			lo = mid;
		}
		else {
			hi = mid - 1;
		}
	}
	return lo;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = n; i < 2 * n; i++) {
			cin >> nums[i];
		}
		// copiar al reves
		for (int i = n - 1; i >= 0; i--) {
			nums[i] = nums[n - i + n - 1];
		}
		// test
		//for (int i = 0; i < 2 * n; i++) cout << nums[i]<< " "; cout << "\n";

		// buscar maxima secuencia creciente para los elementos de nums
		vector<int> MSC; MSC.push_back(-1e9);
		
		for (int i = 0; i < 2 * n; i++) {
			// test
			//for (int j = 0; j < MSC.size(); j++) cout << MSC[j] << " "; cout << "\n";
			// buscar posicion
			int pos = ultimoMenor(nums[i], MSC);

			if (pos == MSC.size()-1) {
				MSC.push_back(nums[i]);
			}
			else {
				MSC[pos + 1] = min(MSC[pos + 1], nums[i]);
			}
		}
		cout << MSC.size() - 1 << "\n";
	}
}