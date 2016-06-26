import cv2

def change(img, a1, b1, c1):
	a = lambda x : x in range(a1[0], a1[1])
	b = lambda x : x in range(b1[0], b1[1])
	c = lambda x : x in range(c1[0], c1[1])

	for x in img:
		for y in x:
			if a(y[0]) and b(y[1]) and c(y[2]):
				y[0], y[1], y[2] = 255, 255, 255
	cv2.imwrite('e:\\desktop\\nex.jpg', img)

def dist(x, y):
	return sum(abs(x-y))

def change2(img, blue, yellow, black, red, brown):
	for x in img:
		for y in x:
			b1 = dist(y, blue)
			y1 = dist(y, yellow)
			b2 = dist(y, black)
			r1 = dist(y, red)
			b3 = dist(y, brown)
			if b1 == min([b1, y1, b2, r1, b3]):
				y[0], y[1], y[2] = 255, 255, 255
	cv2.imwrite('e:\\desktop\\nex.jpg', img)
	

if __name__ == '__main__':
	img = cv2.imread('e:\\desktop\\ex.png', cv2.IMREAD_COLOR)
	change2(img, [63, 143, 206], [238, 196, 184], [20, 20, 20], [234, 182, 182], [105,92,87])
	