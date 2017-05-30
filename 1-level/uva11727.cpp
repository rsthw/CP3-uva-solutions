#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc; scanf("%d", &tc);
	int vals[3];
	for(int t = 1; t<=tc; t++){
		for(int i = 0; i<3; i++){
			scanf("%d", &vals[i]);
		}
		sort(vals, vals+3);
		printf("Case %d: %d\n", t, vals[1]);
	}
}