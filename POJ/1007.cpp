#include <iostream>
#include <string>

using namespace std;

class str_rev {
public:
	int rev;
	string str;
	string origin_str;
	str_rev(void);
	str_rev(string s);	// Count Reversing by Merge Sort
private:
	void _merge_sort(int left, int right);
	void _merge(int left, int mid, int right);
};


str_rev::str_rev(string s): str(s), origin_str(s) {
	rev = 0;
	_merge_sort(0, str.length()-1);
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
	string L(str, left, mid-left+1);
	string R(str, mid+1, right-mid);
	int i = 0, j = 0;
	L.append("Z");
	R.append("Z");
	for(int k = left; k <= right; k++) {
		if(L[i] <= R[j]) {
			str[k] = L[i++];
		}
		else {
			str[k] = R[j++];
			rev += (mid-left-i+1);
		}
	}
}

int main() {
	int len, num, flag;
	cin >> len >> num;
	str_rev* SR = new str_rev[num];
	str_rev temp;
	string s;
	for(int i = 0; i < num; i++) {
		cin >> s;
		temp = str_rev(s);
		flag = 0;
		for(int j = i; j >= 1; j--) { // Insertion Sort
			if(temp.rev > SR[j-1].rev) {
				flag = j;
				break;
			}
		}		
		for(int j = i; j > flag; j--) {
			SR[j] = SR[j-1];
		}
		SR[flag] = temp;
	}
	for(int i = 0; i < num; i++) {	// Output
		cout << SR[i].origin_str << endl;
	}
	delete [] SR;
}