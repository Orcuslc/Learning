#include <iostream>
#include <string>
using namespace std;

int main() {
	// Translation
	char trans[128] = {'\0'};
	trans['A'] = trans['B'] = trans['C'] = '2';
	trans['D'] = trans['E'] = trans['F'] = '3';
	trans['G'] = trans['H'] = trans['I'] = '4';
	trans['J'] = trans['K'] = trans['L'] = '5';
	trans['M'] = trans['N'] = trans['O'] = '6';
	trans['P'] = trans['R'] = trans['S'] = '7';
	trans['T'] = trans['U'] = trans['V'] = '8';
	trans['W'] = trans['X'] = trans['Y'] = '9';
	for(char i = '0'; i <= '9'; i++) {
		trans[i] = i;
	}

	int number;
	cin >> number;
	// cout << cin.get();
	// char s;
	// char t[8];
	string s;
	string* t = new string(8, '\0');
	for(int i = 1; i <= number; i++) {
		cin >> s;
		for(int j = 0, k = 0; s[j]; j++) {
			if(trans[s[j]])	{
				(*t)[k++] = trans[s[j]];
			}
		}
		// int k = 0;
		// cin.get(s);
		// while(s != '\n') {
		// 	if(trans[s])
		// 		t[k++] = trans[s];
		// 	cin.get(s);
		// }
		// t[7] = '\0';
		cout << *t << endl;
	}
}