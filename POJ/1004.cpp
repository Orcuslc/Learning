#include <iostream>
#include <stdio.h>

int main() {
	using namespace std;
	float sum = 0.0, s;
	for(int i = 1; i <= 12; i++) {
		cin >> s;
		sum += s;
	}
	printf("$%.2f\n", sum/12);
	return(0);
}