#ifndef DRIVER_CRUISE_CONSOLE_H
#define DRIVER_CRUISE_CONSOLE_H

#include <opencv2/opencv.hpp>
using namespace cv;

void ConsolePID(Mat &src, const double &radius, const double &steer);

#endif //DRIVER_CRUISE_CONSOLE_H
