#include <iostream>
#include <cmath>

double square(double x) {
	return sqrt(x);
}

int main() {
	using namespace std;
	cout << "Input:";
	cout << endl;
	double x;
	cin >> x;
	x = square(x);
	cout << "Output:" << x << endl;
	cin.get();
}

