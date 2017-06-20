#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const ll daysInYear = 365;
ll months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

struct Date {
	ll d, m, y;
};

bool isLeap(Date x) {
	return (x.y % 4 == 0 && x.y % 100 != 0) || x.y % 400 == 0;
}

ll daysPassed(Date x) {
	ll ans = 0;
	int month = x.m;
	for (int i = 0; i < month-1; i++) {
		ans += months[i];
	}

	if (month > 2 && isLeap(x)) ans++;

	return ans;
}

ll DateToInt(Date x) {
	// dias
	ll ans = x.d;
	// meses
	ans += daysPassed(x);
	// years
	ans += x.y * 365;
	// agregar los dias de los leapyears
	ll ny = x.y - 1;
	ans += (ny / 4 - ny / 100 + ny / 400);

	return ans;
}

Date IntToDate(ll num) {
	Date ans;
	ll aprox = num / 365;
	ans.y = aprox; ans.m = 1; ans.d = 1;
	while (DateToInt(ans) > num) {
		ans.y--;
	}
	ll res = num - DateToInt(ans)+1;
	// months
	ans.m = 12;
	while (daysPassed(ans)+1 > res) {
		ans.m--;
	}
	res = res - daysPassed(ans);

	ans.d = res;

	return ans;
}

int main() {
	Date x;
	ll days;
	while (scanf("%lld %lld %lld %lld", &days, &x.d, &x.m, &x.y) != EOF && (days || x.d || x.m || x.y)) {
		ll total = days + DateToInt(x);
		//cout << total << endl;
		Date ans = IntToDate(total);

		printf("%lld %lld %lld\n", ans.d, ans.m, ans.y);
	}
}