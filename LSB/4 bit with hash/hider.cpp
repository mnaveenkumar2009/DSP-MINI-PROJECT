#include <opencv2/opencv.hpp>
#include "../../template.h"

using namespace cv;

int main(){
    ifstream hash("hash");
    vector <int> a(16);

    Mat image1 = imread("data/image1.jpeg"),image2=imread("data/image2.jpg");
    
    if (image1.empty()||image2.empty()){
        cout << "Could not open or find the image" << '\n';
        return -1;
    }

    Size size(image1.cols,image1.rows);

    resize(image2,image2,size); //resize image2
    
    // return 0;
    int i,j,k;
    f(i,16){
        hash>>a[i];
    }
    f(i,image1.cols){
        f(j,image1.rows){
            f(k,3){
                image1.at<Vec3b>(j, i).val[k]>>=4;
                image1.at<Vec3b>(j, i).val[k]<<=4;
                image2.at<Vec3b>(j, i).val[k]>>=4;
                assert(image2.at<Vec3b>(j, i).val[k]<16);
                assert(image1.at<Vec3b>(j, i).val[k]>=16||image1.at<Vec3b>(j, i).val[k]==0);
                image1.at<Vec3b>(j, i).val[k]|=a[image2.at<Vec3b>(j, i).val[k]];
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