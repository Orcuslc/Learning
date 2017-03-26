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


int main() {
	string s;
	cin >> s;
	reversed(&s);
	cout << s << endl;
	return(0);
}