/*
Time to read:
	1:18
Preparation time:
	1:15
Programming time:
	8:07

Notes:
	Reading can improve
	Wrong assumptions
*/
#include <bits/stdc++.h>
using namespace std;

class Help{
public:
	static char toLowerCase(char a){
		if('A'<=a && a<='Z') return a-'A'+'a';
		return a;
	}

	static int upperCaseValue(char a){
		if('A'<=a && a<='Z') return 0;
		return 1;
	}
};

struct Comparison{
	bool operator()(const char &a, const char &b) const {
		if(Help::toLowerCase(a) != Help::toLowerCase(b)) return Help::toLowerCase(a)<Help::toLowerCase(b);
		return Help::upperCaseValue(a) < Help::upperCaseValue(b);
	}
};

int main(){
	string word;
	int n; scanf("%d", &n);
	while(n-- > 0){
		cin >> word;
		sort(word.begin(), word.end(), Comparison());

		do {
			cout << word<<endl;
		} while(next_permutation(word.begin(), word.end(), Comparison()));
	}
}