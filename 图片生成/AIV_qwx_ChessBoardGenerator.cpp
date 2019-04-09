#include "AIV_qwx_ChessBoardGenerator.h"

AIV_qwx_ChessBoardGenerator::AIV_qwx_ChessBoardGenerator()
{

}

AIV_qwx_ChessBoardGenerator::AIV_qwx_ChessBoardGenerator(const int _image_rows, const int _image_cols, const int _chess_1strow, const int _chess_1stcol, const int _lenth_rows, const int _length_cols,
	const int _corner_rows, const int _corner_cols, const std::string _filename, const int _mark_1strow, const int _mark_1stcol, const int _mark_rows, const int _mark_cols)
{
	Image_rows = _image_rows;
	Image_cols = _image_cols;
	Chess_1strow = _chess_1strow;
	Chess_1stcol = _chess_1stcol;
	Edge_rows = _lenth_rows;
	Edge_cols = _length_cols;
	Corner_rows = _corner_rows;
	Corner_cols = _corner_cols;
	filename = _filename;
	Mark_1strow = _mark_1strow;
	Mark_1stcol = _mark_1stcol;
	Mark_rows = _mark_rows;
	Mark_cols = _mark_cols;
}

AIV_qwx_ChessBoardGenerator::~AIV_qwx_ChessBoardGenerator()
{

}

void AIV_qwx_ChessBoardGenerator::setImageSize(const int _image_rows, const int _image_cols)
{
	Image_rows = _image_rows;
	Image_cols = _image_cols;
}

void AIV_qwx_ChessBoardGenerator::setChessPoint(const int _chess_1strow, const int _chess_1stcol)
{
	Chess_1strow = _chess_1strow;
	Chess_1stcol = _chess_1stcol;
}

void AIV_qwx_ChessBoardGenerator::setEdgeLength(const int _lenth_rows, const int _length_cols)
{
	Edge_rows = _lenth_rows;
	Edge_cols = _length_cols;
}

void AIV_qwx_ChessBoardGenerator::setCornerSize(const int _corner_rows, const int _corner_cols)
{
	Corner_rows = _corner_rows;
	Corner_cols = _corner_cols;
}

void AIV_qwx_ChessBoardGenerator::setFilename(const std::string _filename)
{
	filename = _filename;
}

void AIV_qwx_ChessBoardGenerator::setMarkPoint(const int _mark_1strow, const int _mark_1stcol)
{
	Mark_1strow = _mark_1strow;
	Mark_1stcol = _mark_1stcol;
}

void AIV_qwx_ChessBoardGenerator::setMarkSize(const int _mark_rows, const int _mark_cols)
{
	Mark_rows = _mark_rows;
	Mark_cols = _mark_cols;
}

bool AIV_qwx_ChessBoardGenerator::generate(bool _with_mark)
{
	cv::Mat chessBoard_positive(Image_rows, Image_cols, CV_8UC3, cv::Scalar(255, 255, 255));
	cv::Mat chessBoard_negative(Image_rows, Image_cols, CV_8UC3, cv::Scalar(255, 255, 255));
	int ChessArea_rows = (Corner_rows + 1)*Edge_rows,
		ChessArea_cols = (Corner_cols + 1)*Edge_cols;
	cv::Mat chessROI_positive = chessBoard_positive(cv::Rect(Chess_1stcol, Chess_1strow, ChessArea_cols, ChessArea_rows));
	cv::Mat chessROI_negative = chessBoard_negative(cv::Rect(Chess_1stcol, Chess_1strow, ChessArea_cols, ChessArea_rows));
	//const int size = 50;
	for (int row = 0; row < ChessArea_rows; row++)
	{
		for (int col = 0; col < ChessArea_cols; col++)
		{
			int rownum = row / Edge_rows;
			int colnum = col / Edge_cols;
			if ((rownum + colnum) % 2 == 0)
			{
				chessROI_positive.at<cv::Vec3b>(row, col) = cv::Vec3b(0, 0, 0);
				chessROI_negative.at<cv::Vec3b>(row, col) = cv::Vec3b(255, 255, 255);
			}
			else
			{
				chessROI_positive.at<cv::Vec3b>(row, col) = cv::Vec3b(255, 255, 255);
				chessROI_negative.at<cv::Vec3b>(row, col) = cv::Vec3b(0, 0, 0);
			}
		}
	}
	
	std::string filename_positive = filename + "_positive.bmp",
		filename_negative = filename + "_negative.bmp";	

	imwrite(filename_positive, chessBoard_positive);
	imwrite(filename_negative, chessBoard_negative);

	return true;
}