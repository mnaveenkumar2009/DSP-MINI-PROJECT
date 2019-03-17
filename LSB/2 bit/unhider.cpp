#include <opencv2/opencv.hpp>
#include "../../template.h"

using namespace cv;

int main(){
    Mat image = imread("data/hiddenimage.png"),unhid=image;

    Size size(image.cols/2,image.rows/2);
    resize(unhid,unhid,size); //resize image1
    if (image.empty()){
        cout << "Go hide the image first before unhiding it" << '\n';
        return -1;
    }

    int i,j,k;

    f(i,unhid.cols){
        f(j,unhid.rows){
            f(k,3){
                int a[4];
                a[0]=image.at<Vec3b>(j*2,i*2).val[k]&3;
                a[1]=image.at<Vec3b>(j*2+1,i*2).val[k]&3;
                a[2]=image.at<Vec3b>(j*2,i*2+1).val[k]&3;
                a[3]=image.at<Vec3b>(j*2+1,i*2+1).val[k]&3;
                unhid.at<Vec3b>(j, i).val[k]=(a[3]<<6)|(a[2]<<4)|(a[1]<<2)|(a[0]);
            }
        }
    }

    if (!imwrite("data/unhiddenimage.jpg", unhid)){
        cout << "Failed to save the unhidden image" << '\n';
        return -1;
    }

    namedWindow("hidden image");
    imshow("hidden image", unhid);
    waitKey(0);
    destroyWindow("hidden image");
    return 0;
}