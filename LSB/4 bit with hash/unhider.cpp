#include <opencv2/opencv.hpp>
#include "../../template.h"

using namespace cv;

int main(){
    Mat image = imread("data/hiddenimage.png");
    vector <int> a(16);
    ifstream invhash("invhash");
    if (image.empty()){
        cout << "Go hide the image first before unhiding it" << '\n';
        return -1;
    }

    int i,j,k;

    f(i,16){
        invhash>>a[i];
    }
    f(i,image.cols){
        f(j,image.rows){
            f(k,3){
                image.at<Vec3b>(j, i).val[k]&=15;
                image.at<Vec3b>(j, i).val[k]=a[image.at<Vec3b>(j, i).val[k]];
                image.at<Vec3b>(j, i).val[k]<<=4;
                // cout<<(ll)image.at<Vec3b>(j, i).val[k]<<'\n';
            }
        }
    }

    if (!imwrite("data/unhiddenimage.jpg", image)){
        cout << "Failed to save the unhidden image" << '\n';
        return -1;
    }

    namedWindow("hidden image");
    imshow("hidden image", image);
    waitKey(0);
    destroyWindow("hidden image");
    return 0;
}