#include<bits/stdc++.h>
using namespace std;
void findLCS(string X, string Y) {
    int s1,s2,i,j;
    s1 = X.length();
    s2 = Y.length();
    int p[s1+1][s2+1];
    for (i = 0; i <=s1;i++) {
       p[i][0]=0;
        }
    for (i= 0;i<=s2;i++){
        p[0][i]=0;
    }
    for (i=1;i<=s1;i++) {
        for (j = 1;j<=s2;j++) {
            if(X[i-1]==Y[j-1]) {
                p[i][j]=p[i-1][j-1]+1;
            } else {
                p[i][j] =max(p[i-1][j],p[i][j-1]);
            }
        }
    }
    string Z;
    i = s1, j = s2;
    while (i>0&&j>0){
        if (X[i-1]==Y[j-1]) {
            Z=X[i-1]+Z;
            i--;
            j--;
        } else if (p[i-1][j]>p[i][j-1]){
            i--;
        } else {
            j--;
        }
    }
    cout<<"\nLength: "<<p[s1][s2]<<"\nLCS string: "<<Z<<endl;
}

int main() {
    string X,Y;
    cout<<"Enter strings: "<<endl;
    cin>>X>>Y;
    findLCS(X,Y);
    return 0;
}
