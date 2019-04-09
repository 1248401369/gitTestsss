#ifndef AIV_QWX_GREYPATTERNGENERATOR

#include <opencv2/opencv.hpp>
#include <vector>
#include <fstream>

#define variables
#define functions

class AIV_qwx_GreyPatternGenerator
{
variables private:
	int Pattern_number;//���������ͼ��ģʽ��������������
	int Image_rows, Image_cols;//���������ͼ����������
	int Pattern_1strow, Pattern_1stcol;//������������ʼ����
	int Pattern_rows, Pattern_cols;//����������������
	int Code_lines;//һ��������ռ�����л�����
	std::string Image_filename;//ͼ�񱣴���ļ���
	std::string Table_filename;//��������ļ���
	int Mark_1strow, Mark_1stcol;//��־�������ʼ����
	int Mark_rows, Mark_cols;//��־�����������	

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
