#include <iostream>
using namespace std;

__int64 k, t, d;

__int64 gcd(__int64 a, __int64 b) {
	if(b == 0) {
		k = 1; t = 0; d = a;
		return a;
	}
	else {
		__int64 temp = gcd(b, a%b), sw;
		sw = k; k = t; t = sw - (a/b)*t;
		return temp;
	}
}

int main() {
	__int64 x, y, m, n, l;
	cin >> x >> y >> m >> n >> l;
	__int64 a = m-n, b = y-x;
	if(a < 0) {
		a = -a; b = -b;
	}
	gcd(a, l);
	if(b%d != 0) cout << "Impossible" << endl;
	else {
		k = k*b/d; t = t*b/d; l = l/d;
		if(k >= 0) k = k%l;
		else k = k%l+l;
		cout << k << endl;
	}
	return 0;
}