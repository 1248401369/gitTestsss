#ifndef AIV_QWX_PHASEPATTERNGENERATOR

#include <opencv2/opencv.hpp>
#include <string>

#define functions
#define variables

//using namespace std;
//using namespace cv;

//相位码图案生成代码
//
class AIV_qwx_PhasePatternGenerator
{
variables private:

	int Image_number;//输出相位码图案张数
	int Image_rows, Image_cols;//输出相位码图案的行列数
	int Pattern_1strow, Pattern_1stcol;//相位码区域起始行列
	int Pattern_rows, Pattern_cols;//相位码区域行列数
	int period_lines;//一个周期相位码占像素行或列数
	std::string filename;//图像保存的文件名
	int Mark_1strow, Mark_1stcol;//标志区域的起始行列
	int Mark_rows, Mark_cols;//标志区域的行列数
	float OriginalPhaseShift;//初始相移

functions public:
	AIV_qwx_PhasePatternGenerator();
	AIV_qwx_PhasePatternGenerator(const int _ImageNumber, const int _ImageRows, const int _ImageCols, const int _Pattern_row, const int _Pattern_col,
		const int _PatternRows, const int _PatternCols, const int _PeriodLines, const std::string _FileName);
	~AIV_qwx_PhasePatternGenerator();

	void generate(bool _withmark = false);
	void setImageNumber(const int _ImageNumber);
	void setImageSize(const int _ImageRows, const int _ImageCols);
	void setPatternPoint(const int _Pattern_row, const int _Pattern_col);
	void setPatternSize(const int _PatternRows, const int _PatternCols);
	void setPeriodLines(const int _PeriodLines);
	void setFileName(const std::string _FileName);
	void setMarkPoint(const int _Mark_row, const int _Mark_col);
	void setMarkSize(const int _MarkRows, const int _MarkCols);
	void setOriginalPhaseShift(const float _PhaseShift);

functions private:
	void drawmark(cv::Mat &_img);
	
};


#endif // !AIV_QWX_PHASEPATTERNGENERATOR


