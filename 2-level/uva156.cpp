/*
Time to read:
	3:10
Preparation time:
	3:50
Programming time:
	14:55

Notes:
	Read a little bit faster
	This had a solid preparation
	Should program a little bit faster
	Decent program organization :)
*/

#include <bits/stdc++.h>
using namespace std;


class Helper{
public:
	static char toLowerCase(char a){
		if('A'<=a && a<='Z'){
			return a-'A'+'a';
		}
		return a;
	}

	static bool endOfCase(string &word){
		if(word.size() >= 1 && word[0] == '#') return true;
		return false;
	}

	static int placeInAlphabet(char a){
		return a-'a';
	}

	static void test(vector<int> &letters, string &word){
		cout << word<<endl;
		for(int i = 0; i<letters.size(); i++) cout << letters[i]<<" ";cout<<endl;
	}
};

int main(){
	string word;

	set<vector<int> > lettersOfAnagrams;
	set<string> ananagrams;

	map<vector<int>, string> wordOfChoice;

	while(cin >> word && !Helper::endOfCase(word)){
		// obtener el conjunto de letras y cuantas veces aparece cada una
		vector<int> letras(28, 0);

		for(int i = 0; i<word.size(); i++){
			char letra = Helper::toLowerCase(word[i]);

			// contar
			letras[Helper::placeInAlphabet(letra)]++;
		}

		// ver si hay otra que coincida
		if(lettersOfAnagrams.find(letras) == lettersOfAnagrams.end()){
			// si es nuevo
			lettersOfAnagrams.insert(letras);
			ananagrams.insert(word);
			wordOfChoice[letras] = word;
		} else {
			string wordNotAnanagram = wordOfChoice[letras];
			ananagrams.erase(wordNotAnanagram);
		}

		//Helper::test(letras, word);
		//cout << ananagrams.size()<<endl;
	}

	// imprimir ananagrams

	for(auto &solution : ananagrams){
		cout << solution << endl;
	}
}