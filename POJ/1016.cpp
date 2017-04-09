#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string inventory(string s) {
	int count[10] = {0};
	stringstream str;
	for(int i = 0; i < s.length(); i++) {
		count[s[i] - 48]++;
	}
	for(int i = 0; i < 10; i++) {
		if(count[i] > 0) {
			str << 10*count[i] + i;
		}
	}
	return str.str();
}

int main() {
	string s, inv_s, t;
	string inv_list[15];
	bool flag;
	while(cin >> s) {
		int count = 0;
		inv_s = "";
		t = s;
		flag = false;
		if(s == "-1") break;
		cout << s;
		for(int i = 0; i < 15; i++) {
			inv_list[i] = s;
			s = inventory(s);
			for(int j = 0; j <= i; j++) {
				if(s == inv_list[j]) {
					if(i == j && j == 0)
						cout << " is self-inventorying" << endl;
					else if(i == j && j > 0)
						cout << " is self-inventorying after " << j << " steps" << endl;
					else
						cout << " enters an inventory loop of length " << i-j+1 << endl;
					flag = true;
					break;
				}
			}
			if(flag) break;
			else if(i == 14)
				cout << " can not be classified after 15 iterations" << endl;
		}
	// 	inv_s = inventory(s);
	// 	if(inv_s == s) {
	// 		cout << s << " is self-inventorying" << endl;
	// 		continue;
	// 	}
	// 	while(count < 14) {
	// 		count++;
	// 		s = inv_s;
	// 		inv_s = inventory(s);
	// 		if(s == inv_s) {
	// 			cout << s << " is self-inventorying after " << count << "steps" << endl;
	// 			flag = true;
	// 			break;
	// 		}
	// 		if(s == t) {
	// 			cout << t << " enters an inventory loop of length " << count << endl;
	// 			flag = true;
	// 			break;
	// 		}
	// 	}
	// 	if(!flag)
	// 		cout << t << " can not be classified after 15 iterations" << endl;
	}
	return 0;
}