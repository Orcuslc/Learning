#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

// With http://leons.im/posts/poj-1009-edge-detection-report/ We can know that,
// Changing points in the output image are all located in the neighbourhood of changing points in the input image. 

using namespace std;
vector<int> sum;
vector<pair<int, int> > imgI;
map<int, int> imgO;
int height, width;

int get_pixel(int pos) {
	for(int i = 0; i < imgI.size(); i++) {
		if(pos < sum[i]) {
			return imgI[i].second;
		}
	}
}

void calc(int pos) {
	if(imgO.find(pos) != imgO.end()) {
		return ;
	}
	int row = pos/width, col = pos%width;
	if(pos < 0||pos >= sum.back()) {
		return ;
	}
	int pixel = get_pixel(pos);
	int maxdiv = 0;
	for(int i = row-1; i <= row+1; i++) {
		for(int j = col-1; j <= col+1; j++) {
			if(i<0 || i>=height|| j<0|| j>=width) {
				continue;
			}
			int neighbour = i*width+j;
			int neighbour_pixel = get_pixel(neighbour);
			maxdiv = max(maxdiv, abs(pixel - neighbour_pixel));
		}
	}
	imgO[pos] = maxdiv;
}

void comp() {
	for(int i = 0; i < imgI.size(); i++) {
		int pos = imgI[i].first;
		for(int k = -1; k <= 1; k++) {
			for(int j = -1; j <= 1; j++) {
				int n = pos + k*width + j;
				calc(n);
			}
		}
	}
	calc(sum.back() - width);
}

void print() {
	map<int, int>::iterator iter = imgO.begin();
	int cur_pos = iter->first, cur_pixel = iter->second;
	while(iter != imgO.end()) {
		if(iter->second != cur_pixel) {
			cout << cur_pixel << ' ' << (iter->first - cur_pos) << endl;
			cur_pos = iter->first;
			cur_pixel = iter->second;
		}
		iter++;
	}
	cout << cur_pixel << ' ' << (sum.back() - cur_pos) << endl;
	cout << "0 0" << endl;
}

int main() {
	int val, len;
	while(cin >> width && width) {
		cout << width << endl;
		sum.clear();
		imgI.clear();
		imgO.clear();
		int pos = 0;
		while(cin >> val >> len && len) {
			imgI.push_back(make_pair(pos, val));
			pos += len;
			sum.push_back(pos);
		}
		height = sum.back()/width;
		comp();
		print();
	}
	cout << 0 << endl;
	return(0);
}