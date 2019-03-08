#include <opencv2/opencv.hpp>
#include "template.h"

using namespace cv;

int main(){
    Mat meme1 = imread("data/meme2.jpg");

    Mat meme2=imread("data/meme1.jpeg");
    

    Size size(meme2.cols,meme2.rows);

    resize(meme1,meme1,size); //resize meme2
    
    // return 0;
    int i,j,k;
    f(i,meme1.cols){
        f(j,meme1.rows){
            f(k,3){
                meme1.at<Vec3b>(j, i).val[k]>>=4;
                meme1.at<Vec3b>(j, i).val[k]<<=4;
            }
        }
    }
    
    namedWindow("hidden meme 2 in meme 1");
    imshow("hidden meme 2 in meme 1", meme1);
    waitKey(0);
    destroyWindow("hidden meme 2 in meme 1");
    return 0;
}