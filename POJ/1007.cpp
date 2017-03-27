#include <iostream>
#include <string>

using namespace std;

class str_rev {
public:
	string* str;
	int rev;
	str_rev();
private:
	void _merge(int left, int mid, int right);
};

void str_rev::_merge(int left, int mid, int right) {
	string L(*str, left, mid-left);
	string R(*str, mid+1, right-mid);
	L += '\0';
	R += '\0';

}

int str_rev::str_rev() {
	rev = 0;
	
}

int main() {
	int len, num;
	cin >> len >> num;	
	return(0);
}