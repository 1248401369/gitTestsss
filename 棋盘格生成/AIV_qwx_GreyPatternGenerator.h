#ifndef AIV_QWX_GREYPATTERNGENERATOR

#include <opencv2/opencv.hpp>
#include <vector>
#include <fstream>

#define variables
#define functions

class AIV_qwx_GreyPatternGenerator
{
variables private:
	int Pattern_number;//输出格雷码图案模式数，不包含正反
	int Image_rows, Image_cols;//输出格雷码图案的行列数
	int Pattern_1strow, Pattern_1stcol;//格雷码区域起始行列
	int Pattern_rows, Pattern_cols;//格雷码区域行列数
	int Code_lines;//一个格雷码占像素行或列数
	std::string Image_filename;//图像保存的文件名
	std::string Table_filename;//表单保存的文件名
	int Mark_1strow, Mark_1stcol;//标志区域的起始行列
	int Mark_rows, Mark_cols;//标志区域的行列数	

functions public:
	AIV_qwx_GreyPatternGenerator();
	~AIV_qwx_GreyPatternGenerator();

	void setPatternNumber(const int _PatternNumber);
	void setImageSize(const int _ImageRows, const int _ImageCols);
	void setPatternPoint(const int _Pattern_row, const int _Pattern_col);
	void setPatternSize(const int _PatternRows, const int _PatternCols);
	void setCodeLines(const int _CodeLines);
	void setImageFileName(const std::string _FileName);
	void setTableFileName(const std::string _FileName);
	void setMarkPoint(const int _Mark_row, const int _Mark_col);
	void setMarkSize(const int _MarkRows, const int _MarkCols);

	void generateImage(bool _withmark = false);
	
	void generateTable();
	static bool loadTable(std::vector<unsigned int> &_GreyLineCodeTable, const std::string _filename, const unsigned int _code_number);

functions private:
};

#endif // !AIV_QWX_GREYPATTERNGENERATOR
