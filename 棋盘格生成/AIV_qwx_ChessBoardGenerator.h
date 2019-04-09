#ifndef AIV_QWX_CHESSBOARDGENERATOR

#include <opencv2/opencv.hpp>
#include <string>
#include <sstream>

#define variables
#define functions

class AIV_qwx_ChessBoardGenerator
{
variables private:
	int Image_rows, Image_cols;			// 输出棋盘格图案的行列数
	int Chess_1strow, Chess_1stcol;		// 棋盘格区域起始行列
	int Edge_rows, Edge_cols;			// 棋盘格边长
	int Corner_rows, Corner_cols;		// 棋盘格角点行列数	
	std::string filename;				// 图像保存的文件名
	int Mark_1strow, Mark_1stcol;		// 标志区域的起始行列
	int Mark_rows, Mark_cols;			// 标志区域的行列数

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
