#include "AIV_qwx_GreyPatternGenerator.h"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	const int pattern_number = 8;
	const string Imagefilename = "ss//img";
	const string Tablefilename = "¸ñÀ×ÂëÍ¼Éú³É//GreyLineCodeTable.csv";
	//const int code_lines = 3;

	AIV_qwx_GreyPatternGenerator gpg;
	gpg.setImageFileName(Imagefilename);
	gpg.setPatternNumber(pattern_number);
	gpg.setImageSize(1140, 912);
	gpg.setPatternPoint(180, 72);
	gpg.setPatternSize(768, 768);
	gpg.setMarkPoint(180, 776);
	gpg.setMarkSize(202, 64);

	gpg.setTableFileName(Tablefilename);
	//gpg.generateTable();
	//vector<unsigned int> GreyLineCode;
	//gpg.loadTable(GreyLineCode, Tablefilename, 256);
	gpg.generateImage(true);

	return 0;
}