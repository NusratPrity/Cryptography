#include<bits/stdc++.h>
using namespace std;
int main()
{

    string Str="mnaai urtjhnss a";
    int k=3;

    int l=Str.size();

    bool increment=true;

    char mat[k][l];

    for(int i=0;i<k;i++){
        for(int j=0;j<l;j++){
            mat[i][j]='=';
            //cout<<mat[i][j]<<" ";
        }
        //cout<<endl;
    }

    for(int i=0,j=0;j<l;j++){


        if(i==k-1)
            increment=false;
        if(i==0)
            increment=true;

        mat[i][j]='*';

        if(increment==true)
            i++;
        else
            i--;
    }
    int p=0;
    for(int i=0;i<k;i++){
        for(int j=0;j<l;j++){
            if(mat[i][j]=='*' && p<l){
                   // cout<<i<<" "<<j<<endl;
                mat[i][j]=Str[p++];
            }
        }
    }

    cout<<"PlainText: "<<endl;

      for(int i=0,j=0;j<l;j++){


        if(i==k-1)
            increment=false;
        if(i==0)
            increment=true;

        if(mat[i][j]!='=')
                cout<<mat[i][j];

        if(increment==true)
            i++;
        else
            i--;
    }
    cout<<endl;

    return 0;
}

