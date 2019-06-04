#include<bits/stdc++.h>
#define s 4                 //Number of Component of vector
#define n 4                 //Number of input vector
#define m 2                 //Number of exempler vector
using namespace std;
float MatrixMultiplication(float x[n][s] ,float w[s][m],int row,int col){
float sum=0.0;
for(int i=0;i<s;i++){
    sum+=(x[row][i]*w[i][col]);
}
return sum;
}
int main(){

//Exempler vector
cout<<"Enter the values of Exempler vector"<<endl;
float e[m][s];
for(int i=0;i<m;i++){
    for(int j=0;j<s;j++){
        cin>>e[i][j];
    }
}

//Input vector
cout<<"Enter the values of Input vector"<<endl;
float x[n][s];
for(int i=0;i<n;i++){
    for(int j=0;j<s;j++){
        cin>>x[i][j];
    }
}

//converting Exempler to weight
float w[s][m];
for(int i=0;i<s;i++){
    for(int j=0;j<m;j++){
        w[i][j]=(e[j][i]/2);
        //cout<<w[i][j];
    }
    //cout<<endl;
}

//Initializing Bias
float b[m];
for(int i=0;i<m;i++){
    b[i]=n/2;
}

float y[n][m];
int c;
//Performing following Steps for each input vector
for(int i=0;i<n;i++){
        cout<<endl<<"For Input x = "<<i<<endl<<endl;
    for(int j=0;j<m;j++){
        y[i][j]=b[j]+MatrixMultiplication(x,w,i,j);
        cout<<"The value y"<<j<<"= "<<y[i][j]<<" is the number of components at which the input vector x"<<i<<" and e"<<j<<" agree ."<<endl;

    }
    cout<<"Y="<<*max_element(y[i],y[i]+m)<<" is the best match exempler for input x"<<i<<endl;

}

cout<<endl<<endl;


}
/*Input

Exempler
-1 -1 -1 1
1 -1 -1 -1

Input
-1 -1 1 -1
-1 -1 1 1
-1 -1 -1 1
1 1 -1 -1






*/
