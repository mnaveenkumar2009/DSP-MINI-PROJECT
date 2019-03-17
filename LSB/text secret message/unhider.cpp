#include <opencv2/opencv.hpp>
#include "../../template.h"

using namespace cv;

int main(){
    Mat meme = imread("data/hiddenmeme.png");

    int i,j,k;
    string s;
    f(i,meme.cols/2){
        f(j,meme.rows/2){
            k=0;
            {
                int a[4];
                a[0]=meme.at<Vec3b>(j*2,i*2).val[k]&3;
                a[1]=meme.at<Vec3b>(j*2+1,i*2).val[k]&3;
                a[2]=meme.at<Vec3b>(j*2,i*2+1).val[k]&3;
                a[3]=meme.at<Vec3b>(j*2+1,i*2+1).val[k]&3;
                // int ii;f(ii,4)cout<<a[ii]<<' ';cout<<'\n';
                s.pb((char)((a[3]<<6)|(a[2]<<4)|(a[1]<<2)|(a[0])));
                if(s[s.length()-1]==0){
                    s[s.length()-1]='\0';
                    break;
                }
            }
            if(s[s.length()-1]==0){
                break;
            }
        }
        if(s[s.length()-1]==0){
            break;
        }
    }
    // cout<<s.size()<<'\n';
    cout<<"HIDDEN MESSAGE IS \n"<<s<<'\n';
    return 0;
}