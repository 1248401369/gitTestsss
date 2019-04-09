#include <iostream>
#include "AIV_qwx_PhasePatternGenerator.h"
//#include "AIV_qwx_PhasePatternDecoder.h"

using namespace std;
using namespace cv;

int main()
{
	const int image_number = 4;
	const string filename = "./img//ss";
	const int period = 48;
	const float original_phase_shift = -CV_PI + 0.0000001;

	////////////ÖÆÍ¼////////////
	AIV_qwx_PhasePatternGenerator ppg;
	ppg.setFileName(filename);
	ppg.setImageNumber(image_number);
	ppg.setImageSize(1140, 912);
	ppg.setPatternPoint(180, 72);
	ppg.setPatternSize(768, 768);
	ppg.setPeriodLines(period);
	ppg.setMarkPoint(180, 776);
	ppg.setMarkSize(202, 64);
	ppg.setOriginalPhaseShift(original_phase_shift);
	ppg.generate(true);

	return 0;
}