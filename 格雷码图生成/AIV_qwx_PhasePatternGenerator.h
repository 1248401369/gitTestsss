#ifndef AIV_QWX_PHASEPATTERNGENERATOR

#include <opencv2/opencv.hpp>
#include <string>

#define functions
#define variables

//using namespace std;
//using namespace cv;

//��λ��ͼ�����ɴ���
//
class AIV_qwx_PhasePatternGenerator
{
variables private:

	int Image_number;//�����λ��ͼ������
	int Image_rows, Image_cols;//�����λ��ͼ����������
	int Pattern_1strow, Pattern_1stcol;//��λ��������ʼ����
	int Pattern_rows, Pattern_cols;//��λ������������
	int period_lines;//һ��������λ��ռ�����л�����
	std::string filename;//ͼ�񱣴���ļ���
	int Mark_1strow, Mark_1stcol;//��־�������ʼ����
	int Mark_rows, Mark_cols;//��־�����������
	float OriginalPhaseShift;//��ʼ����

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


