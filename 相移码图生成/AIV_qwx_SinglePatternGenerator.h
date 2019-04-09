#ifndef AIV_QWX_SINGLEPATTERNGENERATOR

#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

#define variables
#define functions

class AIV_qwx_SinglePatternGenerator
{
variables private:
	std::vector<cv::Mat> Images;

functions public:
	AIV_qwx_SinglePatternGenerator();
	~AIV_qwx_SinglePatternGenerator();

	void setImages(const std::vector<cv::Mat> &_images);
	bool generate();

functions private:
};


#endif // !AIV_QWX_SINGLEPATTERNGENERATOR
