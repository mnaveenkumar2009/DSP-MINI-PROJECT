#include <bits/stdc++.h>
using namespace std;
int main(){
    int i;
    ofstream hash("hash"),invhash("invhash");
    vector <int> a(16),b(16);
    for(i=0;i<16;i++){
        a[i]=i;
    }
    random_shuffle(a.begin(),a.end());
    for(i=0;i<16;i++){
        b[a[i]]=i;
        hash<<a[i]<<'\n';
    }
    for(i=0;i<16;i++){
        invhash<<b[i]<<'\n';
    }
}