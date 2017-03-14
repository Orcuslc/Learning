#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int t;
	cin >> s;
	// t = s.substr(0, 2).append(s);
	t = s.find('.');
	cout << t << endl;
	return(0);
}