#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> dict;
int len = 0;

bool check_del(string dic, string s) {
	if(dic.length() != s.length()+1) return false;
	bool match;
	for(int i = 0; i < dic.length(); i++) { // Del the i_th letter;
		match = true;
		int k = 0;
		for(int j = 0; j < dic.length(); j++) {
			if(i == j) continue;
			if(dic[j] != s[k]) {
				match = false;
				break;
			}
			k++;
		}
		if(match) return true;
	}
	return false;
}

bool check_replace(string dic, string s) {
	if(dic.length() != s.length()) return false;
	bool match;
	for(int i = 0; i < dic.length(); i++) { // Replace the i_th letter;
		match = true;
		for(int j = 0; j < dic.length(); j++) {
			if(i == j) continue;
			if(dic[j] != s[j]) {
				match = false;
				break;
			}
		}
		if(match) return true;
	}
	return false;
}

bool check_insert(string dic, string s) {
	if(dic.length() != s.length()-1) return false;
	bool match;
	for(int i = 0; i < s.length(); i++) { // Insert on the i_th place;
		match = true;
		int k = 0;
		for(int j = 0; j < s.length(); j++) {
			if(i == j) continue;
			if(dic[k] != s[j]) {
				match = false;
				break;
			}
			k++;
		}
		if(match) return true;
	}
	return false;
}

int main() {
	string s;
	bool correct;
	while(1) {
		cin >> s;
		if(s == "#") break;
		dict.push_back(s);
	}
	while(1) {
		cin >> s;
		if(s == "#") break;
		correct = false;
		vector<string>::iterator iter;
		for(iter = dict.begin(); iter != dict.end(); iter++) {
			if(s == *iter) {
				correct = true;
				break;
			}
		}
		if(correct) cout << s << " is correct" << endl;
		else {
			cout << s << ":";
			for(iter = dict.begin(); iter != dict.end(); iter++) {
				if(check_del(*iter, s) || check_replace(*iter, s) || check_insert(*iter, s)) cout << " " << *iter;
			}
			cout << endl;
		}
	}
	return 0;
}