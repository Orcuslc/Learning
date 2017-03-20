#include <math.h>
#include <iostream>

float dict[274] = {0.0};
using namespace std;

// Since ln(\frac{n+1}{2}) < \Sum_{i=2}^{n}\frac{1}{i} < ln(n)

int Binary_Search(float t, int MIN, int MAX) {
	int MID = floor((MIN+MAX)/2);
	if(dict[MID] < t) {
		if(dict[MID+1] >= t) {
			return(MID+1);
		}
		else {
			return(Binary_Search(t, MID, MAX));
		}
	}
	else {
		if(dict[MID-1] < t) {
			return(MID);
		}
		else {
			return(Binary_Search(t, MIN, MID));
		}
	}
}

int main() {
	float count = 0.5;
	for(int i = 1; i < 274; i++) {
		dict[i] = 1/float(i+1) + dict[i-1];
	} // Calculate the dict;
	float t;
	while(1) { // Binary Search;
		cin >> t;
		if(t == 0.00) {
			break;
		}
		int MIN = floor(exp(t)-1), MAX = ceil(2*exp(t)-1);
		if(MAX >= 273) {
			MAX = 273;
		}
		cout << Binary_Search(t, MIN, MAX) << " card(s)" << endl;
	}
}