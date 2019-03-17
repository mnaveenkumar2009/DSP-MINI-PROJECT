#include <opencv2/opencv.hpp>
#include "../../template.h"

using namespace cv;

int main(){
    Mat meme = imread("data/hiddenmeme.png"),unhid=meme;

    Size size(meme.cols/2,meme.rows/2);
    resize(unhid,unhid,size); //resize meme1
    if (meme.empty()){
        cout << "Go hide the meme first before unhiding it" << '\n';
        return -1;
    }

    int i,j,k;

    f(i,unhid.cols){
        f(j,unhid.rows){
            f(k,3){
                int a[4];
                a[0]=meme.at<Vec3b>(j*2,i*2).val[k]&3;
                a[1]=meme.at<Vec3b>(j*2+1,i*2).val[k]&3;
                a[2]=meme.at<Vec3b>(j*2,i*2+1).val[k]&3;
                a[3]=meme.at<Vec3b>(j*2+1,i*2+1).val[k]&3;
                unhid.at<Vec3b>(j, i).val[k]=(a[3]<<6)|(a[2]<<4)|(a[1]<<2)|(a[0]);
            }
        }
    }

    if (!imwrite("data/unhiddenmeme.jpg", unhid)){
        cout << "Failed to save the unhidden meme" << '\n';
        return -1;
    }

    namedWindow("hidden meme");
    imshow("hidden meme", unhid);
    waitKey(0);
    destroyWindow("hidden meme");
    return 0;
}