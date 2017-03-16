#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void reversed(string* s) {
	int len = s->length();
	char temp;
	for(int i = 0; i < len/2; i++) {
		temp = (*s)[i];
		(*s)[i] = (*s)[len-i-1];
		(*s)[len-i-1] = temp;
	}
}

string exp(string s, int n) {
	
}

string multiply(string s, string t) {
	// s is {longer than||the same as} t;
	int len_s = s.length(), len_t = t.length();
	int len_res = len_s + len_t + 1;
	string res[len_res];
	for(int i = len_s; i) {
		for(int j = )
	}
}



int main() {
	string s;
	int n, decimal, num_decimal;
	while(cin >> s >> n) {
		len_s = s.length();
		decimal = s.find('.');
		num_decimal = len_s-decimal-1;
		if(decimal != -1) {
			s = s.substr(0, decimal).append(s, decimal+1, num_decimal);
		}
		s = 
		res = exp(s, n);
		res.insert(res.length()-num_decimal*n, '.');
		cout << res << endl;
	}
	return(0);
}