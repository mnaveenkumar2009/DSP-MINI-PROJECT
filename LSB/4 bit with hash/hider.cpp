#include <opencv2/opencv.hpp>
#include "../../template.h"

using namespace cv;

int main(){
    ifstream hash("hash");
    vector <int> a(16);

    Mat meme1 = imread("data/meme1.jpeg"),meme2=imread("data/meme2.jpg");
    
    if (meme1.empty()||meme2.empty()){
        cout << "Could not open or find the Meme" << '\n';
        return -1;
    }

    Size size(meme1.cols,meme1.rows);

    resize(meme2,meme2,size); //resize meme2
    
    // return 0;
    int i,j,k;
    f(i,16){
        hash>>a[i];
    }
    f(i,meme1.cols){
        f(j,meme1.rows){
            f(k,3){
                meme1.at<Vec3b>(j, i).val[k]>>=4;
                meme1.at<Vec3b>(j, i).val[k]<<=4;
                meme2.at<Vec3b>(j, i).val[k]>>=4;
                assert(meme2.at<Vec3b>(j, i).val[k]<16);
                assert(meme1.at<Vec3b>(j, i).val[k]>=16||meme1.at<Vec3b>(j, i).val[k]==0);
                meme1.at<Vec3b>(j, i).val[k]|=a[meme2.at<Vec3b>(j, i).val[k]];
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