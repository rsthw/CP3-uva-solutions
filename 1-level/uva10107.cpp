#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
using ll = long long;
using dll = pair<ll, ll>;

bool mayorQueTodos(set<dll> &S, ll val) {
	if (S.empty()) return false;

	set<dll>::iterator it = S.end(); it--;

	ll mayor = (*it).first;

	return val > mayor;
}

dll getLast(set<dll> &S) {
	set<dll>::iterator it = S.end(); it--;
	return (*it);
}
dll getFirst(set<dll> &S) {
	set<dll>::iterator it = S.begin();
	return (*it);
}

void balancear(set<dll> &A, set<dll> &B) {
	while (abs((int)(A.size() - B.size())) > 1) {
		if (A.size() > B.size()) {
			dll grande = getLast(A);
			A.erase(grande);
			B.insert(grande);
		}
		else if (B.size() > A.size()) {
			dll chico = getFirst(B);
			B.erase(chico);
			A.insert(chico);
		}
	}
}

int main() {
	ll nxt;
	ll idx = 1;
	set<dll> men, may;
	while (scanf("%lld", &nxt) != EOF) {
		if (mayorQueTodos(men, nxt)) may.insert(dll(nxt,idx++));
		else men.insert(dll(nxt, idx++));

		balancear(men, may);

		if (abs((int)(men.size() - may.size())) > 0) {
			if (men.size() > may.size()) {
				printf("%lld\n", getLast(men).first);
			}
			else {
				printf("%lld\n", getFirst(may).first);
			}
		}
		else {
			ll ans = (getFirst(may).first + getLast(men).first) / 2;
			printf("%lld\n", ans);
		}
	}
}