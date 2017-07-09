#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <bitset>
using namespace std;
using ii = pair<int, int>;
using ll = long long;
using dll = pair<ll, ll>;
#define pb push_back

const int K = 10004;

void llenar(bitset<K> &criba, int primo) {
	for (int i = primo; i < K; i += primo) {
		criba[i] = true;
	}
}

void generar(vector<int> &primos) {
	primos.clear();

	bitset<K> criba;
	primos.pb(2); llenar(criba, 2);

	for (int i = 3; i < K; i++) {
		if (!criba[i]) {
			primos.pb(i); llenar(criba, i);
		}
	}
}

void descomponer(vector<int> &primos, vector<ii> &desc, int num) {
	desc.clear();
	// para cada primo
	int id = 0;
	ii pr;
	while (id < primos.size() && primos[id] <= num / primos[id]) {
		if (num%primos[id] == 0) {
			pr = ii(primos[id], 0);
			while (num%primos[id] == 0) {
				pr.second++;
				num /= primos[id];
			}
			desc.pb(pr);
		}
		id++;
	}
	if (num > 1) {
		desc.pb(ii(num, 1));
	}
}

void getDivisores(vector<int> &div, vector<ii> &desc) {
	div.clear();
	div.pb(1);

	// para cada primo
	int sz, pr, po, ac;
	for (int i = 0; i < desc.size(); i++) {
		pr = desc[i].first;
		po = desc[i].second;

		ac = 1;
		sz = div.size();
		for (int p = 1; p <= po; p++) {
			ac *= pr;
			for (int j = 0; j < sz; j++) {
				div.pb(div[j] * ac);
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);

	vector<int> primos;

	generar(primos);

	int k; 
	vector<ii> desc;
	vector<int> div;
	set<dll> ans;
	while (cin >> k) {
		ans.clear();
		
		descomponer(primos, desc, k*k);
		getDivisores(div, desc);


		//for (int i = 0; i < div.size(); i++) cout << div[i] << " "; cout << "\n";

		// para cada divisor calcular x,y
		for (int i = 0; i < div.size(); i++) {
			ll k2 = k;

			ll x = k2 + div[i];
			ll y = (k2*k2 + div[i] * k2) / div[i];

			ans.insert(dll(max(x, y), min(x, y)));
		}

		// imprimir
		cout << ans.size() << "\n";
		for (set<dll>::reverse_iterator it = ans.rbegin(); it != ans.rend(); it++) {
			dll nxt = *it;
			cout << "1/" << k << " = 1/" << nxt.first << " + 1/" << nxt.second << "\n";
		}
	}
}