#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string s, t;
int n;

string multiply(string s, string t) {
	string res(s.size()+t.size(), '0');
	for(int i = s.size() - 1; i >= 0; i--) {
		int carry = 0, sn = s[i] - '0';
		for(int j = t.size() - 1; j >= 0; j--) {
			int tn = t[j] - '0';
			int sum = sn*tn + carry + res[i+j+1] - '0';
			carry = sum / 10;
			res[i+j+1] = sum%10 + '0';
		}
		if(carry) res[i] += carry;
	}
	int index = 0;
	while(res[index] == '0') {
		index++;
	}
	return res.substr(index, res.length()-index);
}

string construct_9(int n) {
	stringstream ss;
	while(n--) ss << "9";
	return ss.str();
}

string convert(int n) {
	stringstream ss;
	ss << n;
	return ss.str();
}

int main() {
	while(cin >> s) {
		n = s.length();
		if(construct_9(n) == multiply(s, convert(n+1))) cout << s << " is cyclic" << endl;
		else cout << s << " is not cyclic" << endl;
	}
	return 0;
}