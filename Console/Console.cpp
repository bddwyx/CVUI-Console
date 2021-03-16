#include "Console.h"
#include "PID.h"

#define CVUI_IMPLEMENTATION
#include "cvui.h"

void ConsolePID(Mat &src, const double &radius, const double &steer) {
    static char bufRadius[20], bufSteer[20];
    static bool update = false;
    Mat dashBoard = Mat::zeros(cv::Size(400, 400),CV_8UC3);
    hconcat(src, dashBoard, dashBoard);

    cvui::init("Control Board");
    waitKey(10);

    cvui::window(dashBoard, 400, 0, 400, 100, "Option");
    if(!cvui::checkbox(dashBoard, 410, 30, "Halt", &update)){
        sprintf_s(bufRadius, "Radius:%f", radius);
        sprintf_s(bufSteer, "Steer:%f", steer);
        sprintf_s(bufSteer, "Steer:%f", steer);
    }
    cvui::text(dashBoard, 410, 70, bufRadius, 0.5, 0xffffff);
    cvui::text(dashBoard, 610, 70, bufSteer, 0.5, 0xffffff);

    cvui::window(dashBoard, 400, 100, 200, 300, "OuterLoop");
    cvui::trackbar(dashBoard, 410, 130, 180, &kp_d, 2., 4.);
    cvui::trackbar(dashBoard, 410, 160, 180, &ki_d, 0., 0.01);
    cvui::trackbar(dashBoard, 410, 190, 180, &kd_d, 0.7, 1.5);

    cvui::window(dashBoard, 600, 100, 200, 300, "InnerLoop");
    cvui::trackbar(dashBoard, 610, 130, 180, &kp_a, 0., 500.);
    cvui::trackbar(dashBoard, 610, 160, 180, &ki_a, 0., 0.01);
    cvui::trackbar(dashBoard, 610, 190, 180, &kd_a, 0., 1.5);

    cvui::update();
    cvui::imshow( "Control Board", dashBoard);
}
