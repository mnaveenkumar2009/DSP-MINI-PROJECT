#include <opencv2/opencv.hpp>
#include "../../template.h"

using namespace cv;

int main(){
    Mat image1 = imread("data/image2.jpg");

    Mat image2=imread("data/image1.jpeg");
    

    Size size(image2.cols,image2.rows);

    resize(image1,image1,size); //resize image2
    
    // return 0;
    int i,j,k;
    f(i,image1.cols){
        f(j,image1.rows){
            f(k,3){
                image1.at<Vec3b>(j, i).val[k]>>=4;
                image1.at<Vec3b>(j, i).val[k]<<=4;
            }
        }
    }
    
    namedWindow("hidden image 2 in image 1");
    imshow("hidden image 2 in image 1", image1);
    waitKey(0);
    destroyWindow("hidden image 2 in image 1");
    return 0;
}