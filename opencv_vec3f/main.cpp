#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/mat.hpp>

using namespace std;
using namespace cv;
int main() {
  Mat a(10, 5, CV_8UC3);

  uint8_t *p = a.data;
  for(int i = 0; i < 50; i++) {
    *p++ = i * 3;
    *p++ = i * 3 + 1;
    *p++ = i * 3 + 2;
  }

  p = a.data;
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 5; j++) {
      for(int c = 0; c < 3; c++) {
        cout << (int)*p++ << " ";
      }
      cout << ",";
    }
    cout <<endl;
  }

  p = a.data;
  Mat_<Vec3f> b(12, 7);
  for(int i = 0; i < 10; i++) {
    float *p1 = b.ptr<float>(i + 1, 1);
    for(int j = 0; j < 5; j++) {
      for(int c = 0; c < 3; c++) {
        *p1++ = (float)*p++;
      }
    }
  }

  for(int i = 0; i < 12; i++) {
    float *p1 = b.ptr<float>(i,0);
    for(int j = 0; j < 7; j++) {
      for(int c = 0; c < 3; c++) {
        cout << *p1++ << " ";
      }
      cout << ",";
    }
    cout <<endl;
  }

  Mat img = imread("../000000000139.jpg");
  p = img.data;

  Mat_<Vec3f> res(img.rows, img.cols);
  for(int i = 0; i < img.rows; i++) {
    float *p1 = res.ptr<float>(i, 0);
    for(int j = 0; j < img.cols; j++) {
      for(int c = 0; c < 3; c++) {
        *p1++ = (float)*p++;
      }
    }
  }

  Mat d;
  res.convertTo(d, CV_8UC3);
  imwrite("output.jpg", d);
  // Mat a(100, 200, CV_32FC3, cv::Scalar(10, 10, 10));
  // cv::Mat_<cv::Vec3f> b
  return 0;
}
