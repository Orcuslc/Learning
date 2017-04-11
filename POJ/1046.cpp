#include <iostream>

using namespace std;

int main() {
	int set[16][3], dist, min_dist, index, pixel[3];
	for(int i = 0; i < 16; i++) {
		for(int j = 0; j < 3; j++) cin >> set[i][j];
	}
	while(1) {
		min_dist = 195076; index = -1;
		cin >> pixel[0] >> pixel[1] >> pixel[2];
		if(pixel[0] == -1) break;
		for(int i = 0; i < 16; i++) {
			dist = (pixel[0]-set[i][0])*(pixel[0]-set[i][0]) + (pixel[1]-set[i][1])*(pixel[1]-set[i][1])+ (pixel[2]-set[i][2])*(pixel[2]-set[i][2]);
			if(dist < min_dist) {
				index = i;
				min_dist = dist;
			}
		}
		cout << "(" << pixel[0] << "," << pixel[1] << "," << pixel[2] << ") maps to (" << set[index][0] << "," << set[index][1] << "," << set[index][2] << ")" << endl;
	}
	return 0;
}	