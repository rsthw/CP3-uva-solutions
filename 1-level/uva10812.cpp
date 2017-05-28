#include <bits/stdc++.h>
using namespace std;

int main(){
	// big + small  = sum
	// big - small  = dif
	// 2*big = sum+dif
	// big = (sum+dif)/2   ie   sum+dif  es par
	// small = sum - big
	// big,small >=0

	// Assumption: big+small fits in an integer

	int n; scanf("%d", &n);
	while(n--){
		int sum, dif; scanf("%d %d", &sum, &dif);
		int big, small;

		bool ok = true;
		if((sum+dif)%2 == 0){ // hay solucion
			big = (sum+dif)/2;
			small = sum - big;

			if(big < 0 || small < 0) ok = false;
		} else {
			ok = false;
		}

		if(ok) printf("%d %d\n", big, small);
		else printf("impossible\n");
	}

}