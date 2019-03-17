#include <opencv2/opencv.hpp>
#include "../../template.h"

using namespace cv;

#define KEY 1234  // secret Key used as seed for random

int main(){
    srand(KEY);
    Mat image = imread("data/hiddenimage.png"),unhid=image;

    Size size(image.cols/2,image.rows/2);
    resize(unhid,unhid,size); //resize image
    if (image.empty()){
        cout << "Go hide the image first before unhiding it" << '\n';
        return -1;
    }

    int i,j,k;
    vector <int> a(image.cols*image.rows);
    f(i,image.cols*image.rows){
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

    
     f(i,image.cols*image.rows){
        f(k,3){
            if(i%4==0)
                unhid.at<Vec3b>(i/(2*image.cols),(i%image.cols)/2).val[k]|=(image.at<Vec3b>(a[i]/image.cols,a[i]%image.cols).val[k]&3)<<6;
            if(i%4==1)
                unhid.at<Vec3b>(i/(2*image.cols),(i%image.cols)/2).val[k]|=(image.at<Vec3b>(a[i]/image.cols,a[i]%image.cols).val[k]&3)<<4;
            if(i%4==2)
                unhid.at<Vec3b>(i/(2*image.cols),(i%image.cols)/2).val[k]|=(image.at<Vec3b>(a[i]/image.cols,a[i]%image.cols).val[k]&3)<<2;
            if(i%4==3)
                unhid.at<Vec3b>(i/(2*image.cols),(i%image.cols)/2).val[k]|=(image.at<Vec3b>(a[i]/image.cols,a[i]%image.cols).val[k]&3);
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