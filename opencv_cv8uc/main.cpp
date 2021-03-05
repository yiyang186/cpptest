#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <ctype.h>

using namespace cv;
using namespace std;


int main( int argc, char** argv )
{
    Mat mat15(1024, 768, CV_8UC(15));
    cout << mat15.rows << ' ' << mat15.cols << ' ' << mat15.channels() << endl;

    vector<Mat> mats;
    for(int i = 0; i < 5; i++) {
      Mat mat(1024, 768, CV_8UC3, cv::Scalar(i, i, i));

      for(int j = 0; j < mat.channels(); j++) {
        cout << (int)mat.at<Vec3b>(0, 0)[j] << "|";
      }
      mats.push_back(mat);
    }
    cout << endl;

    merge(mats, mat15);
    cout << mat15.rows << ' ' << mat15.cols << ' ' << mat15.channels() << endl;

    uint8_t *p = mat15.data;
    for(int i = 0; i < 15; i++) {
      cout << (int)(*(p + i)) << ' ';
    }
    cout << endl;

    Mat resized;
    resize(mat15, resized, cv::Size(224, 224));
    cout << resized.rows << ' ' << resized.cols << ' ' << resized.channels() << endl;

    p = resized.data;
    for(int i = 0; i < 15; i++) {
      cout << (int)(*(p + i)) << ' ';
    }
    cout << endl;

    /*
    list<Mat> lmats;
    for(int i = 0; i < 5; i++) {
      Mat mat(1024, 768, CV_8UC3, cv::Scalar(i, i, i));

      for(int j = 0; j < mat.channels(); j++) {
        cout << (int)mat.at<Vec3b>(0, 0)[j] << "|";
      }
      lmats.push_back(mat);
    }
    cout << endl;

    merge(lmats, mat15);
    */

    return 0;
}
