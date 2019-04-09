#include "AIV_qwx_SinglePatternGenerator.h"

AIV_qwx_SinglePatternGenerator::AIV_qwx_SinglePatternGenerator()
{

}

AIV_qwx_SinglePatternGenerator::~AIV_qwx_SinglePatternGenerator()
{

}

void AIV_qwx_SinglePatternGenerator::setImages(const std::vector<cv::Mat> &_images)
{
	Images = _images;
}

bool AIV_qwx_SinglePatternGenerator::generate()
{
	const int Height = Images[0].rows,
		Width = Images[0].cols;
	const int Image_number = Images.size();
	cv::Mat imageSigle(Height, Width, CV_8UC3, cv::Scalar(255, 255, 255));

	//��img0.bmp~img7.bmp�浽imageSingle.bmp��R��
	for (int index = 0; index < std::fminf(8, Image_number); index++)
	{
		int value = pow(2.0, index);
		for (int y = 0; y < Height; y++)
		{
			for (int x = 0; x < Width; x++)
			{
				if (Images[index].at<uchar>(y, x) == 0)
				{
					imageSigle.at<cv::Vec3b>(y, x)[1] -= value;
				}
			}
		}
	}

	//��img8.bmp~img15.bmp�浽imageSingle.bmp��G��
	for (int index = 8; index < std::fminf(16, Image_number); index++)
	{
		int value = pow(2.0,index-8);
		for (int y = 0; y<Height; y++)
		{
			for (int x = 0; x<Width; x++)
			{
				if(Images[index].at<uchar>(y,x)==0)
				{
					imageSigle.at<cv::Vec3b>(y,x)[2] -= value;
				}
			}
		}
	}

	///*��img16.bmp~img23.bmp�浽imageSingle.bmp��B��*/
	for (int index = 16; index < std::fminf(24, Image_number); index++)
	{
		int value = pow(2.0, index - 16);
		for (int y = 0; y<Height; y++)
		{
			for (int x = 0; x<Width; x++)
			{
				if (Images[index].at<uchar>(y, x) == 0)
				{
					imageSigle.at<cv::Vec3b>(y, x)[2] -= value;
				}
			}
		}
	}

	//����Ҫע����ǣ���һ��ʼѡ����Ǳ���Ϊ.jpg��ʽ��Ȼ��.jpgת��Ϊ.bmp
	//�����ͻᶪʧ���ȣ�����Ҫֱ�Ӵ�Ϊ.bmp��ʽ
	imwrite("imageSingle.bmp", imageSigle);

	return true;
}