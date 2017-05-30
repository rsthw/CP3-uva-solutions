#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main(){
	int n;
	while(scanf("%d", &n) != EOF && n){
		ii dp; scanf("%d %d", &dp.first, &dp.second);

		for(int i = 0; i<n; i++){
			int x, y; scanf("%d %d", &x, &y);

			if(x == dp.first || y == dp.second) printf("divisa\n");
			else if(y < dp.second){
				printf("S");
				if(x < dp.first){
					printf("O\n");
				} else{
					printf("E\n");
				}
			} else {
				printf("N");
				if(x < dp.first){
					printf("O\n");
				} else{
					printf("E\n");
				}
			}
		}
	}
}