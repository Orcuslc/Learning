#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;
int count[10000000] = {0};

int main() {
	char trans[128] = {'\0'}; // Translation
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
	int number, MIN = 10000001, MAX = -1, v;	// Read
	cin >> number;
	string s;
	char t[7];
	for(int i = 1; i <= number; i++) {
		cin >> s;
		for(int j = 0, k = 0; s[j]; j++) {
			if(trans[s[j]])	{
				t[k++] = trans[s[j]];
			}
		}
		v = atoi(t);
		if(v < MIN) {
			MIN = v;
		}
		if(v > MAX) {
			MAX = v;
		}
		count[v]++;
	}

	int flag = 0;
	for(int i = MIN; i <= MAX; i++) {
		if(count[i] > 1) {
			flag = 1;
			// cout << i/10000 << '-' << i%10000 << ' ' << count[i] << endl;
			printf("%03d-%04d %d\n", i/10000, i%10000, count[i]);
		}
	}
	if(!flag) {
		cout << "No duplicates." << endl;
	}
	return(0);
}