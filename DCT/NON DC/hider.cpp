#include <opencv2/opencv.hpp>
#include "../../template.h"
#define pi 3.142857 
using namespace cv;
int we=0;

void idct(float matrix[8][8])
{
    int i, j, k, l;
    float idct[8][8];
    for (i = 0; i < 8; i++) { 
        for (j = 0; j < 8; j++) {
            idct[i][j] = 0; 
            for (k = 0; k < 8; k++) { 
                for (l = 0; l < 8; l++) { 
                    float coef=1;
                    if (k == 0) 
                        coef *= 1 / sqrt(2);
                    if (l == 0) 
                        coef *= 1 / sqrt(2);
                    idct[i][j]+=0.25* matrix[k][l] *  coef* cos((2 * i + 1) * k * pi / (16)) *  
                           cos((2 * j + 1) * l * pi / (16));
                }
            }
        }
    }
    f(i,8){
        f(j,8){
            matrix[i][j]=idct[i][j];
        }
    }
}

void dct(ld matrix[8][8],int secret)
{
    int i, j, k, l;
    float dct[8][8];  
    for (i = 0; i < 8; i++) { 
        for (j = 0; j < 8; j++) {
            float coef=1/(sqrt(8)*sqrt(8));
            if (i != 0)
                coef *= sqrt(2); 
            if (j != 0)
                coef *= sqrt(2);
            dct[i][j] = 0; 
            for (k = 0; k < 8; k++)
                for (l = 0; l < 8; l++)
                    dct[i][j]+= coef*matrix[k][l]*cos((2*k +1)*i*pi/(16))*cos((2*l+1)*j*pi/16);
        } 
    }
    
    f(i,8){
        f(j,8){
            if(i!=0||j!=0){
                dct[i][j]=(secret>>4);
                assert(dct[i][j]<16);
            }
        }
    }
    idct(dct);
    f(i,8){
        f(j,8){
            matrix[i][j]=dct[i][j];
        }
    }
    for (i = 0; i < 8; i++) { 
        for (j = 0; j < 8; j++) {
            float coef=1/(sqrt(8)*sqrt(8));
            if (i != 0)
                coef *= sqrt(2); 
            if (j != 0)
                coef *= sqrt(2);
            dct[i][j] = 0; 
            for (k = 0; k < 8; k++)
                for (l = 0; l < 8; l++)
                    dct[i][j]+= coef*matrix[k][l]*cos((2*k +1)*i*pi/(16))*cos((2*l+1)*j*pi/16);
        } 
    }
    we++;
} 
int main(){
    ld tim=time(0);
    Mat image1 = imread("data/image1.jpeg"),image2=imread("data/image2.jpg");
    
    if (image1.empty()||image2.empty()){
        cout << "Could not open or find the image" << '\n';
        return -1;
    }
    int xxx=((image1.cols/8) +1) * 8,yyy=((image1.rows/8) +1) * 8;
    Size size(xxx,yyy),siz2(xxx>>3,yyy>>3);

    resize(image1,image1,size); //resize image1
    resize(image2,image2,siz2); //resize image2
    
    int i,j,k,u,v;
    
    
    f(i,xxx>>3){
        f(j,yyy>>3){
            f(k,3){
                ld mat[8][8];
                // starts at i*8 , j*8
                f(u,8){
                    f(v,8){
                        mat[u][v]=image1.at<Vec3b>(j*8+v,i*8+u).val[k];
                    }
                }
                dct(mat,image2.at<Vec3b>(j,i).val[k]);
                f(u,8){
                    f(v,8){
                        image1.at<Vec3b>(j*8+v,i*8+u).val[k]=mat[u][v];
                    }
                }
            }
        }
    }
    

    if (!imwrite("data/hiddenimage.png", image1)){
        cout << "Failed to save the hidden image" << '\n';
        return -1;
    }
    cout<<"Elapsed Time in seconds :\n"<<((time(0)-tim))<<'\n';
    // 50 secs

    namedWindow("hidden image 2 in image 1");
    imshow("hidden image 2 in image 1", image1);
    waitKey(0);
    destroyWindow("hidden image 2 in image 1");
    return 0;
}