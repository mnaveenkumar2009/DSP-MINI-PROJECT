#include <opencv2/opencv.hpp>
#include "../../template.h"
#define pi 3.142857 
using namespace cv;
ll roundd(ld xx){
    if(xx-floor(xx)>ceil(xx)-xx){
        if(ceil(xx)==16)
            return 15;
        return ceil(xx);
    }
    else
        return floor(xx);
    
}
int we=0;
int dct(ld matrix[8][8])
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
    ll freq[16]={0};
    f(i,8){
        f(j,8){
            if(i!=0||j!=0){
            if(roundd(dct[i][j])<15)
            freq[roundd(dct[i][j])]++;
            // if(roundd(dct[i][j])>15)cout<<i<<' '<<j<<' '<<roundd(dct[i][j])<<'\n';
            }
        }
    }
    ll maxi=0;
    f(i,16){
        maxi=max(maxi,freq[i]);
    }
    f(i,16){
        if(freq[i]==maxi){
            // if(we==0)cout<<i<<' '<<freq[i]<<'\n';
            we++;return i;
        }
    }
} 
int main(){
    ld tim = time(0);
    Mat image = imread("data/hiddenimage.png");
    Mat unhid= image;
    
    if (image.empty()){
        cout << "Oops, No hidden image found" << '\n';
        return -1;
    }
    // cout<<image.cols<<' '<<image.rows<<'\n';
    int xxx=image.cols/8,yyy=image.rows/8;
    Size size(xxx,yyy),siz2(xxx*8,yyy*8);

    resize(unhid,unhid,size); //resize image
    
    int i,j,k,u,v;
    // f(i,min(image.cols,10)){
    //     f(j,min(image.rows,10)){
    //         f(k,3)
    //         cout<<(ll)image.at<Vec3b>(j,i).val[k]<<'\n';    
    //     }
    // }
    // return 0;
    f(i,xxx){
        f(j,yyy){
            f(k,3){
                ld mat[8][8];
                // starts at i*8 , j*8
                f(u,8){
                    f(v,8){
                        mat[u][v]=image.at<Vec3b>(j*8+v,i*8+u).val[k];
                    }
                }
                unhid.at<Vec3b>(j,i).val[k]=dct(mat)<<4;
            }
        }
    }
    
    resize(unhid,unhid,siz2); //resize image

    if (!imwrite("data/unhiddenimage.png", unhid)){
        cout << "Failed to save the unhidden image" << '\n';
        return -1;
    }
    cout<<"Elapsed Time in seconds :\n"<<((time(0)-tim))<<'\n';
    // 16 secs
    namedWindow("unhidden image");
    imshow("unhidden image", unhid);
    waitKey(0);
    destroyWindow("unhidden image");
    return 0;
}