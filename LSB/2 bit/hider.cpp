#include <opencv2/opencv.hpp>
#include "../../template.h"

using namespace cv;

int main(){
    Mat image1 = imread("data/image1.jpeg"),image2=imread("data/image2.jpg");
    
    if (image1.empty()||image2.empty()){
        cout << "Could not open or find the image" << '\n';
        return -1;
    }

    Size size(image2.cols*2,image2.rows*2);

    resize(image1,image1,size); //resize image1
    
    int i,j,k;

    f(i,image1.cols){
        f(j,image1.rows){
            f(k,3){
                image1.at<Vec3b>(j, i).val[k]-=image1.at<Vec3b>(j, i).val[k]&3;
                if(j&1){
                    if(i&1)
                        image1.at<Vec3b>(j, i).val[k]|=(image2.at<Vec3b>(j/2, i/2).val[k]&0b11000000)>>6;
                    else
                        image1.at<Vec3b>(j, i).val[k]|=(image2.at<Vec3b>(j/2, i/2).val[k]&0b1100)>>2;
                }
                else{
                    if(i&1)
                        image1.at<Vec3b>(j, i).val[k]|=(image2.at<Vec3b>(j/2, i/2).val[k]&0b110000)>>4;
                    else
                        image1.at<Vec3b>(j, i).val[k]|=image2.at<Vec3b>(j/2, i/2).val[k]&0b11;
                }
            }
        }
    }

    if (!imwrite("data/hiddenimage.png", image1)){
        cout << "Failed to save the hidden image" << '\n';
        return -1;
    }

    namedWindow("hidden image 2 in image 1");
    imshow("hidden image 2 in image 1", image1);
    waitKey(0);
    destroyWindow("hidden image 2 in image 1");
    return 0;
}