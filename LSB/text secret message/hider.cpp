#include <opencv2/opencv.hpp>
#include "../../template.h"

using namespace cv;

int main(){
    Mat image1 = imread("data/image1.jpeg");
    string s;
    cout<<"ENTER THE MESSAGE\n";
    getline(cin,s);
    int i,j,k;

    f(i,image1.cols){
        f(j,image1.rows){
            k=0;
            {
                image1.at<Vec3b>(j, i).val[k]-=image1.at<Vec3b>(j, i).val[k]&3;
                if(((i/2)*image1.rows+(j/2))>=s.size())continue;
                // cout<<((i/2)*image1.rows+(j/2))<<'\n';
                if(j&1){
                    if(i&1)
                        image1.at<Vec3b>(j, i).val[k]|=(s[((i/2)*image1.rows+(j/2))]&0b11000000)>>6;
                    else
                        image1.at<Vec3b>(j, i).val[k]|=(s[((i/2)*image1.rows+(j/2))]&0b1100)>>2;
                }
                else{
                    if(i&1)
                        image1.at<Vec3b>(j, i).val[k]|=(s[((i/2)*image1.rows+(j/2))]&0b110000)>>4;
                    else
                        image1.at<Vec3b>(j, i).val[k]|=s[((i/2)*image1.rows+(j/2))]&0b11;
                }
            }
        }
    }

    if (!imwrite("data/hiddenimage.png", image1)){
        cout << "Failed to save the hidden image" << '\n';
        return -1;
    }

    namedWindow("hidden message image");
    imshow("hidden message image", image1);
    waitKey(0);
    destroyWindow("hidden message image");
    return 0;
}