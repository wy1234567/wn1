#include <iostream>
#include <opencv2/core/core.hpp>  
#include <opencv2\highgui\highgui.hpp>
#include "highgui.h" 
#include <opencv2/opencv.hpp> 
#include "C:\Users\Administrator\Desktop\n3\n3\stereoprocessor.h"
#include "C:\Users\Administrator\Desktop\n3\n3\imageprocessor.h"
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <string>
#include "adcensuscv.h"


using namespace std;
using namespace cv;

int main()
{
	//para 
	uint dMin = 0;
	uint dMax = 100;

	Size censusWin;
	censusWin.height = 9;
	censusWin.width = 7;

	double defaultBorderCost;
	defaultBorderCost = 0.999;

	double lambdaAD;
	double lambdaCensus;
	lambdaAD = 10.0;
	lambdaCensus = 30.0;

	uint aggregatingIterations = 8;
	uint colorThreshold1 = 20;
	uint colorThreshold2 = 6;
	uint maxLength1 = 34;
	uint maxLength2 = 17;
	uint colorDifference = 15;
	double pi1 = 0.1;
	double pi2 = 0.3;
	uint dispTolerance = 0;
	uint votingThreshold = 20;//20
	double votingRatioThreshold = 0.4;//0.4
	uint maxSearchDepth = 20;
	uint blurKernelSize = 3;
	uint cannyThreshold1 = 20;
	uint cannyThreshold2 = 60;
	uint cannyKernelSize = 3;
    //end para  


	//loading image
	Mat images1 = imread("1.jpg");
	Mat images2 = imread("2.jpg");
	if (images1.empty() || images2.empty())
	{
		printf( "reading erro");
	}
	//imshow("yt1", images1);
	//imshow("yt2", images2);
	//waitKey(0);
	//Size dsize = Size(750,474);
	//resize(images1,images1,dsize);
	//resize(images2, images2, dsize);
	
	ImageProcessor iP(0.1);
	Mat eLeft, eRight;
	eLeft = iP.unsharpMasking(images1, "gauss", 3, 1.9, -1);
	eRight = iP.unsharpMasking(images2, "gauss", 3, 1.9, -1);

	//imshow("pro1",eLeft);
	//imshow("pro2", eRight);
	//waitKey(0);
	//end loading image

	Mat leftImage = eLeft;
	Mat rightImage = eRight;



	StereoProcessor sP(dMin, dMax, leftImage, rightImage, censusWin, defaultBorderCost, lambdaAD, lambdaCensus, 
		aggregatingIterations, colorThreshold1, colorThreshold2, maxLength1, maxLength2,
		colorDifference, pi1, pi2, dispTolerance, votingThreshold, votingRatioThreshold,
		maxSearchDepth, blurKernelSize, cannyThreshold1, cannyThreshold2, cannyKernelSize);
	
	sP.init();
	sP.compute();
	sP.~StereoProcessor();
	
}