#include "AIV_qwx_GreyPatternGenerator.h"

AIV_qwx_GreyPatternGenerator::AIV_qwx_GreyPatternGenerator()
{

}

AIV_qwx_GreyPatternGenerator::~AIV_qwx_GreyPatternGenerator()
{

}

void AIV_qwx_GreyPatternGenerator::setPatternNumber(const int _PatternNumber)
{
	Pattern_number = _PatternNumber;
}

void AIV_qwx_GreyPatternGenerator::setImageSize(const int _ImageRows, const int _ImageCols)
{
	Image_rows = _ImageRows;
	Image_cols = _ImageCols;
}

void AIV_qwx_GreyPatternGenerator::setPatternPoint(const int _Pattern_row, const int _Pattern_col)
{
	Pattern_1strow = _Pattern_row;
	Pattern_1stcol = _Pattern_col;
}

void AIV_qwx_GreyPatternGenerator::setPatternSize(const int _PatternRows, const int _PatternCols)
{
	Pattern_rows = _PatternRows;
	Pattern_cols = _PatternCols;
}

void AIV_qwx_GreyPatternGenerator::setCodeLines(const int _PeriodLines)
{
	Code_lines = _PeriodLines;
}

void AIV_qwx_GreyPatternGenerator::setImageFileName(const std::string _FileName)
{
	Image_filename = _FileName;
}

void AIV_qwx_GreyPatternGenerator::setTableFileName(const std::string _FileName)
{
	Table_filename = _FileName;
}

void AIV_qwx_GreyPatternGenerator::setMarkPoint(const int _Mark_row, const int _Mark_col)
{
	Mark_1strow = _Mark_row;
	Mark_1stcol = _Mark_col;
}

void AIV_qwx_GreyPatternGenerator::setMarkSize(const int _MarkRows, const int _MarkCols)
{
	Mark_rows = _MarkRows;
	Mark_cols = _MarkCols;
}

void AIV_qwx_GreyPatternGenerator::generateImage(bool _withmark)
{
	const uchar ImageNumber = 2 * Pattern_number;
	const float CodeLines = Pattern_rows / powf(2.0, Pattern_number);

	std::vector<cv::Mat> images(ImageNumber);
	std::vector<cv::Mat> ROIimages(ImageNumber);
	std::cout << ImageNumber;
	for (int i = 0; i < ImageNumber; i++)
	{
		images[i] = cv::Mat(Image_rows, Image_cols, CV_8UC1, cv::Scalar(0.0));
		ROIimages[i] = images[i](cv::Rect(Pattern_1stcol, Pattern_1strow, Pattern_cols, Pattern_rows));
	}
	for (int index = 0; index < Pattern_number; index++)
	{
		const int positive_index = 2 * index,
			negative_index = 2 * index + 1;
		for (int y = 0; y < Pattern_rows; y++)
		{
			int value = (int(y * pow(2.0, index) / Pattern_rows + 0.5)) % 2;
			for (int x = 0; x < Pattern_cols; x++)
			{
				//generation equation
				ROIimages[positive_index].at<uchar>(y, x) = 255 * value;
				ROIimages[negative_index].at<uchar>(y, x) = 255 * (1 - value);
			}
		}		
	}
	//////draw mark//////
	if (_withmark)
	{
		for (int index = 0; index < ImageNumber; index++)
		{
			for (int y = Mark_1strow; y < Mark_1strow + Mark_rows; y++)
			{
				for (int x = Mark_1stcol; x < Mark_1stcol + Mark_cols; x++)
				{
					images[index].at<uchar>(y, x) = 0;
				}
			}
		}
	}
	//////save images/////
	cv::Mat saveimage(Image_rows, Image_cols, CV_8UC3, cv::Scalar(255.0, 255.0, 255.0));
	cv::imwrite(Image_filename+"_white.bmp", saveimage);
	//cv::imshow("sss", images[0]);
	//cv::waitKey(0);
	for (int index = 0; index < ImageNumber; index++)
	{
		std::stringstream ss;
		ss << index;
		std::string filename = Image_filename + ss.str() + ".bmp";
		cv::cvtColor(images[index], saveimage, CV_GRAY2BGR);
		cv::imwrite(filename, saveimage);
	}
	return;
}

void AIV_qwx_GreyPatternGenerator::generateTable()
{
	/////////////make table/////////////
	int code_number = pow(2.0, Pattern_number);
	std::vector<int> greylinecode(code_number);
	for (unsigned int line = 0; line < code_number; line++)
	{
		unsigned int line1 = line >> 1;
		unsigned int code = line^line1;
		greylinecode[line] = code;
	}
	///////////save table/////////////
	//std::string path = filename + ".csv";
	std::ofstream ofile(Table_filename);
	for (int line = 0; line < code_number; ++line)
	{
		ofile << greylinecode[line];
		ofile << std::endl;
	}
	ofile.close();

	return;
}

bool AIV_qwx_GreyPatternGenerator::loadTable(std::vector<unsigned int> &_GreyLineCodeTable, const std::string _filename, const unsigned int _code_number)
{
	_GreyLineCodeTable = std::vector<unsigned int>(_code_number, 0);
	std::ifstream ifile(_filename);
	//std::string linestr;
	for (int line = 0; line < _code_number; line++)
	{
		/*getline(ifile, linestr);
		std::stringstream ss(linestr);*/
		unsigned int temp = 0.0;
		ifile >> temp;
		_GreyLineCodeTable[line] = temp;
	}
	ifile.close();

	return true;
}