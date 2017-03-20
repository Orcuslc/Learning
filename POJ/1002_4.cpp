#include <iostream>
#include <string>
using namespace std;
char trans[128] = {'\0'}; // Translation
const int HASHLEN = 1000;

class Node {
public:
	Node();
	Node* next;
	string value;
};
Node::Node() {
	*next = NULL;
	value = NULL;
}

class 

class HashTable {
public:
	void push(char* s);
	void pop(int value);
	Node table[HASHLEN];
};
void HashTable::push(char* s) {
	int val = atoi(s);
	int index = val / HASHLEN;
	if(!table[index]) {
		table[index] = new Node();
		table[index].next = NULL;
		table[index].value = val;
	}
	else {
		Node* ptr = table[index];
		while(!ptr->next) {
			if(val == ptr->val) {
				
			}
		}
	}
}


int main() {
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
	char s, transed, t[7];
	for(int i = 1; i <= number; i++) {
		int key = 6;
		while(key >= 0) {
			cin.get(s);
			transed = trans[s];
			if(transed) {
				t[6 - key] = transed;
				key--;
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
			printf("%03d-%04d %d\n", i/10000, i%10000, count[i]);
		}
	}
	if(!flag) {
		cout << "No duplicates." << endl;
	}
	return(0);
}