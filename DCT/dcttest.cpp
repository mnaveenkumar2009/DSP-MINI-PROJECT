#include <bits/stdc++.h> 
using namespace std; 
#define pi 3.142857 
const int m = 8, n = 8; 
int round(float x){
    if(ceil(x)-x>x-floor(x))
        return floor(x);
    else
        return ceil(x);
}
void idct(float matrix[8][8])
{
    int i, j, k, l;
    float idct[8][n]; 
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
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            printf("%f\t", idct[i][j]);
        printf("\n"); 
    } 
}

int dctTransform(int matrix[8][8]) 
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
    // for (i = 0; i < m; i++) { 
    //     for (j = 0; j < n; j++) { 
    //         printf("%f\t", dct[i][j]); 
    //     } 
    //     printf("\n"); 
    // } 
    // dct[7][7]=256;
    cout<<'\n'; 
    idct(dct);
} 
int main() 
{ 
    int matrix[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            matrix[i][j]=rand()%256;
            cout<<matrix[i][j]<<' ';
        }cout<<'\n';
    } 
    dctTransform(matrix); 
    return 0; 
} 