#include <iostream>
#include <algorithm>
#include <string.h>
//#include <omp.h>
using namespace std;

int mat[25];
int ans[5];

int dis(int a, int b) {
	return abs(a / 5 - b / 5) + abs(a % 5 - b % 5);
}

int main() {
	cin.sync_with_stdio(0);
	
	//double dtime = omp_get_wtime();

	int t; cin >> t;
	int n;
	while (t--) {
		memset(mat, 0, sizeof(mat));
		cin >> n;
		while (n--) {
			int x, y, v;
			cin >> x >> y >> v;
			mat[x * 5 + y] = v;
		}

		int best = 1e9;

		for (int p1 = 0; p1 < 25; p1++) {
			for (int p2 = p1 + 1; p2 < 25; p2++) {
				for (int p3 = p2 + 1; p3 < 25; p3++) {
					for (int p4 = p3 + 1; p4 < 25; p4++) {
						for (int p5 = p4 + 1; p5 < 25; p5++) {
							int total = 0;
							// para cada lugar
							for (int i = 0; i < 25; i++) {
								total+=min(min(min(dis(i, p1), dis(i, p2)), min(dis(i, p3), dis(i, p4))), dis(i, p5))*mat[i];
								if (total >= best) break;
							}
							if (total < best) {
								best = total;
								ans[0] = p1; ans[1] = p2; ans[2] = p3; ans[3] = p4; ans[4] = p5;
							}
						}
					}
				}
			}
		}
		//cout << best << endl;
		cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << " " << ans[4] << "\n";
	}
	//dtime = omp_get_wtime() - dtime;
	//cout << "time in seconds " << dtime << "\n";
	
}