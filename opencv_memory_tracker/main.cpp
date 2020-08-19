#include <cv.h>
#include "MemTracker.h"


//测试程序
int main()
{
  //实例化
  MemTracker tracker;  

  //加载图片，注意它没有被release掉
  IplImage * pImg = cvLoadImage("./test.jpg", 1);

  return 0;
}


