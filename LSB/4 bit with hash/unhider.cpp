#include <opencv2/opencv.hpp>
#include "../../template.h"

using namespace cv;

int main(){
    Mat meme = imread("data/hiddenmeme.png");
    vector <int> a(16);
    ifstream invhash("invhash");
    if (meme.empty()){
        cout << "Go hide the meme first before unhiding it" << '\n';
        return -1;
    }

    int i,j,k;

    f(i,16){
        invhash>>a[i];
    }
    f(i,meme.cols){
        f(j,meme.rows){
            f(k,3){
                meme.at<Vec3b>(j, i).val[k]&=15;
                meme.at<Vec3b>(j, i).val[k]=a[meme.at<Vec3b>(j, i).val[k]];
                meme.at<Vec3b>(j, i).val[k]<<=4;
                // cout<<(ll)meme.at<Vec3b>(j, i).val[k]<<'\n';
            }
        }
    }

    if (!imwrite("data/unhiddenmeme.jpg", meme)){
        cout << "Failed to save the unhidden meme" << '\n';
        return -1;
    }

    namedWindow("hidden meme");
    imshow("hidden meme", meme);
    waitKey(0);
    destroyWindow("hidden meme");
    return 0;
}