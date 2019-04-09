#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include "AIV_qwx_ChessBoardGenerator.h"
#include "AIV_qwx_SinglePatternGenerator.h"

using namespace std;
using namespace cv;

int main()
{
	const string filename = "GrayPhase/img";
	vector<Mat> images;
	for (int i = 0; i < 9; i++)
	{
		stringstream ss;
		ss << i;
		string path = filename + ss.str() + ".bmp";
		Mat temp = imread(path, 0);
		images.push_back(temp);
	}
	AIV_qwx_SinglePatternGenerator spg;
	spg.setImages(images);
	spg.generate();


	return 0;
}