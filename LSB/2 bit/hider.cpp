#include <opencv2/opencv.hpp>
#include "../../template.h"

using namespace cv;

int main(){
    Mat meme1 = imread("data/meme1.jpeg"),meme2=imread("data/meme2.jpg");
    
    if (meme1.empty()||meme2.empty()){
        cout << "Could not open or find the Meme" << '\n';
        return -1;
    }

    Size size(meme2.cols*2,meme2.rows*2);

    resize(meme1,meme1,size); //resize meme1
    
    int i,j,k;

    f(i,meme1.cols){
        f(j,meme1.rows){
            f(k,3){
                meme1.at<Vec3b>(j, i).val[k]-=meme1.at<Vec3b>(j, i).val[k]&3;
                if(j&1){
                    if(i&1)
                        meme1.at<Vec3b>(j, i).val[k]|=(meme2.at<Vec3b>(j/2, i/2).val[k]&0b11000000)>>6;
                    else
                        meme1.at<Vec3b>(j, i).val[k]|=(meme2.at<Vec3b>(j/2, i/2).val[k]&0b1100)>>2;
                }
                else{
                    if(i&1)
                        meme1.at<Vec3b>(j, i).val[k]|=(meme2.at<Vec3b>(j/2, i/2).val[k]&0b110000)>>4;
                    else
                        meme1.at<Vec3b>(j, i).val[k]|=meme2.at<Vec3b>(j/2, i/2).val[k]&0b11;
                }
            }
        }
    }

    if (!imwrite("data/hiddenmeme.png", meme1)){
        cout << "Failed to save the hidden meme" << '\n';
        return -1;
    }

    namedWindow("hidden meme 2 in meme 1");
    imshow("hidden meme 2 in meme 1", meme1);
    waitKey(0);
    destroyWindow("hidden meme 2 in meme 1");
    return 0;
}