#ifndef AIV_QWX_CHESSBOARDGENERATOR

#include <opencv2/opencv.hpp>
#include <string>
#include <sstream>

#define variables
#define functions

class AIV_qwx_ChessBoardGenerator
{
variables private:
	int Image_rows, Image_cols;			// ������̸�ͼ����������
	int Chess_1strow, Chess_1stcol;		// ���̸�������ʼ����
	int Edge_rows, Edge_cols;			// ���̸�߳�
	int Corner_rows, Corner_cols;		// ���̸�ǵ�������	
	std::string filename;				// ͼ�񱣴���ļ���
	int Mark_1strow, Mark_1stcol;		// ��־�������ʼ����
	int Mark_rows, Mark_cols;			// ��־�����������

functions public:
	AIV_qwx_ChessBoardGenerator();
	AIV_qwx_ChessBoardGenerator(const int _image_rows, const int _image_cols, const int _chess_1strow, const int _chess_1stcol, const int _lenth_rows, const int _length_cols,
		const int _corner_rows, const int _corner_cols, const std::string _filename, const int _mark_1strow, const int _mark_1stcol, const int _mark_rows, const int _mark_cols);
	~AIV_qwx_ChessBoardGenerator();

	void setImageSize(const int _image_rows, const int _image_cols);
	void setChessPoint(const int _chess_1strow, const int _chess_1stcol);
	void setEdgeLength(const int _lenth_rows, const int _length_cols);
	void setCornerSize(const int _corner_rows, const int _corner_cols);
	void setFilename(const std::string _filename);
	void setMarkPoint(const int _mark_1strow, const int _mark_1stcol);
	void setMarkSize(const int _mark_rows, const int _mark_cols);
	bool generate(bool _with_mark = false);

functions private:
};

#endif // !AIV_QWX_CHESSBOARDGENERATOR
