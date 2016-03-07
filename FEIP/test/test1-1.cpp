#include "highgui.h"

int main(int argc, char** argv) {
	IplImage* img = cvLoadImage(argv[1]);
	cvNamedWindow("Exp1", CV_WINDOW_AUTOSIZE);
	cvShowImage("Exp1", img);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("Exp1");
}