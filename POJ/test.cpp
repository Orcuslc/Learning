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
	int num;
	int* a = new int[num];
	cin >> num;
	for(int i = 0; i < num; i++) cin >> a[i];
	sort(a, a+num);
	for(int i = 0; i < num; i++) cout << a[i] << endl;
	return 0;
}