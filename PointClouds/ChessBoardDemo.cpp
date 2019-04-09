#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include "AIV_qwx_ChessBoardGenerator.h"
//#include "AIV_qwx_SinglePatternGenerator.h"

using namespace std;
using namespace cv;

int main()
{
	AIV_qwx_ChessBoardGenerator cbg;
	cbg.setImageSize(1140, 912);
	cbg.setChessPoint(100, 300);
	cbg.setCornerSize(5, 4);
	cbg.setEdgeLength(50, 50);
	cbg.setFilename("chessboard");
	cbg.generate();
 
  return 0;
}