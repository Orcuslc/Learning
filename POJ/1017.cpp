#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int packet[7];

int main() {
	int sum, n;
	int space_p3[4] = {0, 5, 3, 1};
	while(1) {
		sum = 0;
		for(int i = 1; i < 7; i++) {
			cin >> packet[i];
			sum += packet[i];
		}
		if(sum == 0) break;
		// Count the packets size (6*6, 5*5, 4*4), and A 6*6 packet can store 4 3*3 packets.
		n = packet[6] + packet[5] + packet[4] + ceil(packet[3]/4.0);
		// Put the 2*2 packets into the free spaces of 4*4 and 3*3.
		int p2 = 5*packet[4] + space_p3[packet[3] % 4];
		if(packet[2] > p2) {
			n += ceil((packet[2] - p2)/9.0);
		}
		// Space left for 1*1 packets;
		int p1 = 36*n - 36*packet[6] - 25*packet[5] - 16*packet[4] - 9*packet[3] - 4*packet[2];
		if(packet[1] > p1) {
			n += ceil((packet[1] - p1)/36.0);
		}
		cout << n << endl;
	}
}