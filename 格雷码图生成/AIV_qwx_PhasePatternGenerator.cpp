#include "AIV_qwx_PhasePatternGenerator.h"

AIV_qwx_PhasePatternGenerator::AIV_qwx_PhasePatternGenerator()
{

}

AIV_qwx_PhasePatternGenerator::AIV_qwx_PhasePatternGenerator(const int _ImageNumber, const int _ImageRows, const int _ImageCols, const int _Pattern_row, const int _Pattern_col,
	const int _PatternRows, const int _PatternCols, const int _PeriodLines, const std::string _FileName)
{
	Image_number = _ImageNumber;
	Image_rows = _ImageRows;
	Image_cols = _ImageCols;
	Pattern_1strow = _Pattern_row;
	Pattern_1stcol = _Pattern_col;
	Pattern_rows = _PatternRows;
	Pattern_cols = _PatternCols;
	period_lines = _PeriodLines;
	filename = _FileName;
}

AIV_qwx_PhasePatternGenerator::~AIV_qwx_PhasePatternGenerator()
{

}

void AIV_qwx_PhasePatternGenerator::setImageNumber(const int _ImageNumber)
{
	Image_number = _ImageNumber;
}

void AIV_qwx_PhasePatternGenerator::setImageSize(const int _ImageRows, const int _ImageCols)
{
	Image_rows = _ImageRows;
	Image_cols = _ImageCols;
}

void AIV_qwx_PhasePatternGenerator::setPatternPoint(const int _Pattern_row, const int _Pattern_col)
{
	Pattern_1strow = _Pattern_row;
	Pattern_1stcol = _Pattern_col;
}

void AIV_qwx_PhasePatternGenerator::setPatternSize(const int _PatternRows, const int _PatternCols)
{
	Pattern_rows = _PatternRows;
	Pattern_cols = _PatternCols;
}

void AIV_qwx_PhasePatternGenerator::setPeriodLines(const int _PeriodLines)
{
	period_lines = _PeriodLines;
}

void AIV_qwx_PhasePatternGenerator::setFileName(const std::string _FileName)
{
	filename = _FileName;
}

void AIV_qwx_PhasePatternGenerator::setMarkPoint(const int _Mark_row, const int _Mark_col)
{
	Mark_1strow = _Mark_row;
	Mark_1stcol = _Mark_col;
}

void AIV_qwx_PhasePatternGenerator::setMarkSize(const int _MarkRows, const int _MarkCols)
{
	Mark_rows = _MarkRows;
	Mark_cols = _MarkCols;
}

void AIV_qwx_PhasePatternGenerator::setOriginalPhaseShift(const float _PhaseShift)
{
	OriginalPhaseShift = _PhaseShift;
}

void AIV_qwx_PhasePatternGenerator::generate(bool _withmark)
{
	cv::Mat *images = new cv::Mat[Image_number]();
	cv::Mat *ROIimages = new cv::Mat[Image_number]();
	for (int i = 0; i < Image_number; i++)
	{
		images[i] = cv::Mat(Image_rows, Image_cols, CV_8UC3, cv::Scalar(0.0, 0.0, 0.0));
		ROIimages[i] = images[i](cv::Rect(Pattern_1stcol, Pattern_1strow, Pattern_cols, Pattern_rows));
	}

	//draw PhaseCode
	float unit_phase = 2 * CV_PI / period_lines;
	//uchar *pROI;
	for (int i = 0; i < Image_number; i++)
	{
		//pROI = ROIimages[i].data;
		float phaseShift = 2 * CV_PI * i / Image_number + OriginalPhaseShift;
		for (int row = 0; row < Pattern_rows; row++)
		{	
			float phase = row % period_lines * unit_phase + phaseShift;
			for (int col = 0; col < Pattern_cols; col++)
			{
				float value = roundf(cosf(phase)*127.5 + 127.5);
				ROIimages[i].at<cv::Vec3b>(row, col) = cv::Vec3b(value, value, value);
			}
		}
	}


	//draw mark
	if (_withmark)
	{
		for (int i = 0; i < Image_number; i++)
		{
			for (int row = Mark_1strow; row < Mark_1strow + Mark_rows; row++)
			{
				for (int col = Mark_1stcol; col < Mark_1stcol + Mark_cols; col++)
				{
					images[i].at<cv::Vec3b>(row, col) = cv::Vec3b(0, 0, 0);
				}
			}
		}
	}

	//show images
	for (int i = 0; i < Image_number; i++)
	{
		imshow("1", images[i]);
		cv::waitKey(0);
	}

	//save images
	std::stringstream ss;
	for (int i = 0; i < Image_number; i++)
	{
		ss.str("");
		ss << i;
		std::string path = filename + ss.str() + ".bmp";
		cv::imwrite(path, images[i]);
	}

	/////这里delete会出错，原因待查***//
	//delete images;
	//delete ROIimages;
}