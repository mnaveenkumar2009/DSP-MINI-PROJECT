#include <opencv2/opencv.hpp>
#include "../../template.h"

using namespace cv;

#define KEY 1234  // secret Key used as seed for random

int main(){
    srand(KEY);
    Mat meme = imread("data/hiddenmeme.png"),unhid=meme;

    Size size(meme.cols/2,meme.rows/2);
    resize(unhid,unhid,size); //resize meme
    if (meme.empty()){
        cout << "Go hide the meme first before unhiding it" << '\n';
        return -1;
    }

    int i,j,k;
    vector <int> a(meme.cols*meme.rows);
    f(i,meme.cols*meme.rows){
        a[i]=i;
    }
    random_shuffle(a.begin(),a.end());
    f(i,unhid.cols){
        f(j,unhid.rows){
            f(k,3){
                unhid.at<Vec3b>(j, i).val[k]=0;
            }
        }
    }

    
     f(i,meme.cols*meme.rows){
        f(k,3){
            if(i%4==0)
                unhid.at<Vec3b>(i/(2*meme.cols),(i%meme.cols)/2).val[k]|=(meme.at<Vec3b>(a[i]/meme.cols,a[i]%meme.cols).val[k]&3)<<6;
            if(i%4==1)
                unhid.at<Vec3b>(i/(2*meme.cols),(i%meme.cols)/2).val[k]|=(meme.at<Vec3b>(a[i]/meme.cols,a[i]%meme.cols).val[k]&3)<<4;
            if(i%4==2)
                unhid.at<Vec3b>(i/(2*meme.cols),(i%meme.cols)/2).val[k]|=(meme.at<Vec3b>(a[i]/meme.cols,a[i]%meme.cols).val[k]&3)<<2;
            if(i%4==3)
                unhid.at<Vec3b>(i/(2*meme.cols),(i%meme.cols)/2).val[k]|=(meme.at<Vec3b>(a[i]/meme.cols,a[i]%meme.cols).val[k]&3);
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