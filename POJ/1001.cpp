#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string multiply(string s, string t) {
	// if(s == "0" || t == "0") return "0";
	bool flag = true;
	for(int i = 0; i < s.size(); i++) 
		if(s[i] != '0') {
			flag = false;
			break;
		}
	for(int j = 0; j < t.size(); j++)
		if(t[j] != '0') {
			flag = false;
			break;
		}
	// cout << flag << "flag" << endl;
	if(flag) return "0";
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
	return res;
}

string power(string s, int t) {
	if(t == 0) return "1";
	if(t == 1) return s;
	else if(t%2 == 0) return multiply(power(s, t/2), power(s, t/2));
	else return multiply(s, power(s, t-1));
}

string standardize(string s, int num_decimal, int n) {
	// cout << s << endl;
	int count = 0;
	while(1) {
		if(s[count] != '0') break;
		count++;
	}
	s = s.substr(count, s.length()-count); // Erase the starting '0's;
	int index = s.length() - num_decimal*n;
	if(index >= 0)
		s.insert(s.length() - num_decimal*n, 1, '.');
	else {
		while(index++) s.insert(0, 1, '0');
		s.insert(0, 1, '.');
	}	// Insert the decimal point;
	count = s.length()-1;
	while(1) {
		if(s[count] != '0') break;
		count--;
	}
	s = s.substr(0, count+1);	// Erase the ending '0's;
	if(s[s.length()-1] == '.') s.erase(s.length()-1, 1);
	if(s == "") s = "0";
	return s;
}

int main() {
	string s;
	int n, decimal, num_decimal;
	while(cin >> s >> n) {
		int len_s = s.length();
		decimal = s.find('.');
		if(decimal != -1) {
			num_decimal = len_s-decimal-1;
			s = s.substr(0, decimal).append(s, decimal+1, num_decimal);
		}
		else num_decimal = 0;
		cout << standardize(power(s, n), num_decimal, n) << endl;
	}
	return(0);
}