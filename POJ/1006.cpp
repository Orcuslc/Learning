#include <iostream>
#include <math.h>
using namespace std;

// The solution has a representation of 
// x = 5544p + 14421e + 1288i + 21252y - d
// (According to CRT)

int main() {
	int p, e, i, d, y, n, x, count = 0;
	while(1) {
		cin >> p >> e >> i >> d;
		if(p == -1) {
			break;
		}
		n = 5544*p + 14421*e + 1288*i;
		y = floor(d-n)/21252 + 1;
		x = n + 21252*y - d;
		if(x%21252) {
			x = x % 21252;
		}
		cout << "Case " << ++count << ": the next triple peak occurs in " << x << " days." << endl;
	}
	return(0);
}