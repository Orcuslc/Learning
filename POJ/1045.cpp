#include <cmath>
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int n; 
	float Vs, R, C, omega, Vr;
	cin >> Vs >> R >> C >> n;
	while(n--) {
		cin >> omega;
		Vr = (omega*C*R*Vs)/(omega*omega*C*C*R*R+1)/sin(atan(1/R/C/omega));
		printf("%.3lf\n", Vr);
	}
	return 0;
}