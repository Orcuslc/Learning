#include <iostream>
#include <string>

using namespace std;

class str_rev {
public:
	string* str;
	int rev;
	str_rev(void);
	str_rev(string* s);	// Count Reversing by Merge Sort
private:
	void _merge_sort(int left, int right);
	void _merge(int left, int mid, int right);
};

str_rev::str_rev(string* s): str(s) {
	_merge_sort(0, (*str).length());
}

str_rev::str_rev(void) {
	rev = 0;
}

void str_rev::_merge_sort(int left, int right) {
	int mid;
	if(left < right) {
		mid = (left+right)/2;
		_merge_sort(left, mid);
		_merge_sort(mid+1, right);
		_merge(left, mid, right);
	}
}

void str_rev::_merge(int left, int mid, int right) {
	string L(*str, left, mid-left);
	string R(*str, mid+1, right-mid);
	L += '\0';
	R += '\0';
	int i = 0, j = 0;
	for(int k = left; k < right; k++) {
		if(L[i] <= R[j]) {
			(*str)[k] = L[i++];
		}
		else {
			(*str)[k] = R[j++];
			rev++;
		}
	}
}

int main() {
	int len, num, flag;
	cin >> len >> num;
	str_rev* SR = new str_rev[num];
	string* s;
	for(int i = 0; i < num; i++) {
		cin >> *s;
		SR[i] = str_rev(s);
		flag = 0;
		for(int j = 0; j < i; j++) { // Insertion Sort
			if(SR[i]->rev < SR[j]->rev) {
				flag = j;
				break;
			}
		}
		for(int j = i+1; j > flag; j++) {
			SR[j] = SR[j-1];
		}
	}
}