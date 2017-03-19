#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
int count[10000000] = {0};
// const int HASHLEN = 1000;

// class Node {
// public:
// 	Node();
// 	Node* next;
// 	string value;
// };
// Node::Node() {
// 	next = NULL;
// 	value = NULL;
// }

// class HashTable {
// public:
// 	void push(char* s);
// 	void pop(int value);
// 	Node table[HASHLEN];
// };
// void HashTable::push(char* s) {
// 	int val = atoi(s);
// 	int index = val / HASHLEN;
// 	if(!table[index]) {
// 		table[index] = new Node();
// 		table[index].next = NULL;
// 		table[index].value = val;
// 	}
// 	else {
// 		Node* ptr = table[index];
// 		while(!ptr->next) {
// 			if(val == ptr->val) {
// 				pop()
// 			}
// 		}
// 	}
// }


int main() {
	// int count[10000000] = {0};
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
	int number;	// Read
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
		count[atoi(t)]++;
	}

	// string res(8, '-');
	char res[9] = {'-'};
	res[8] = '\0';
	int quotient, remainder;
	int flag = 0;
	for(int i = 0; i <= 10000000; i++) {
		if(count[i] > 1) {
			flag = 1;
			remainder = i;
			int div = 1000000;
			for(int j = 0; j < 3; j++) {
				quotient = remainder / div;
				// res[j] = quotient;
				cout << quotient;
				remainder -= quotient * div;
				div /= 10;
				// cout << res[j];
			}
			cout << '-';
			for(int j = 4; j < 8; j++) {
				quotient = remainder / div;
				// res[j] = quotient;
				cout << quotient;
				remainder -= quotient * div;
				div /= 10;
			}
			// cout << res << ' ' << count[i] << endl;
			cout << ' ' << count[i] << endl;
		}
	}
	if(!flag) {
		cout << "No duplicates." << endl;
	}
	return(0);
}