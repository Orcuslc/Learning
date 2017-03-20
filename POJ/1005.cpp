#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n; cin >> n;
	float ay = 100/3.1416;
	float x, y;
	for(int i = 1; i <= n; i++) {
		cin >> x >> y;
		cout << "Property " << i << ':' << " This property will begin eroding in year " << floor((x*x+y*y)/ay) + 1 << '.' << endl;
	}
	cout << "END OF OUTPUT." << endl;
}