#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF && n) {
		int a = 0, b = 0;

		int bit = 1;
		bool uno = true;
		for (int i = 0; i <= 30; i++) {
			if (n&(bit << i)) {
				if (uno) {
					a |= n&(bit << i);
					uno = false;
				}
				else {
					b |= n&(bit << i);
					uno = true;
				}
			}
		}

		printf("%d %d\n", a, b);
	}
}