#include <opencv2/opencv.hpp>
#include "../../template.h"

using namespace cv;

int main(){
    Mat meme1 = imread("data/meme1.jpeg");
    string s;
    cout<<"ENTER THE MESSAGE\n";
    getline(cin,s);
    int i,j,k;

    f(i,meme1.cols){
        f(j,meme1.rows){
            k=0;
            {
                meme1.at<Vec3b>(j, i).val[k]-=meme1.at<Vec3b>(j, i).val[k]&3;
                if(((i/2)*meme1.rows+(j/2))>=s.size())continue;
                // cout<<((i/2)*meme1.rows+(j/2))<<'\n';
                if(j&1){
                    if(i&1)
                        meme1.at<Vec3b>(j, i).val[k]|=(s[((i/2)*meme1.rows+(j/2))]&0b11000000)>>6;
                    else
                        meme1.at<Vec3b>(j, i).val[k]|=(s[((i/2)*meme1.rows+(j/2))]&0b1100)>>2;
                }
                else{
                    if(i&1)
                        meme1.at<Vec3b>(j, i).val[k]|=(s[((i/2)*meme1.rows+(j/2))]&0b110000)>>4;
                    else
                        meme1.at<Vec3b>(j, i).val[k]|=s[((i/2)*meme1.rows+(j/2))]&0b11;
                }
            }
        }
    }

    if (!imwrite("data/hiddenmeme.png", meme1)){
        cout << "Failed to save the hidden meme" << '\n';
        return -1;
    }

    namedWindow("hidden message image");
    imshow("hidden message image", meme1);
    waitKey(0);
    destroyWindow("hidden message image");
    return 0;
}