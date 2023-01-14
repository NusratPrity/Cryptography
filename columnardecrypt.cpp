#include<bits/stdc++.h>
using namespace std;
int main(){

    string encryptedstr="iuthss amnaa rjn";
    string key="hack";
    int l=encryptedstr.size();
    int col=key.size();
    int row=l/col;
     if (encryptedstr.size() % col)
        row += 1;
    char mat[row][col];

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            mat[i][j]='_';
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }


    vector<pair<int,int>>mapkey;

    for(int i=0;i<key.size();i++){
        mapkey.push_back({key[i],i});
    }
    sort(mapkey.begin(),mapkey.end());

    for(auto i:mapkey){
        cout<<i.first<<" "<<i.second<<endl;
    }
int k=0;
cout<<"\n Matrix Table"<<endl;
    for(auto ii:mapkey){
        int j=ii.second;
        for(int i=0;i<row && k<l;i++){
            mat[i][j]=encryptedstr[k++];
            //cout<<str[k]<<" "<<endl;
        }
    }
    cout<<endl;

    string plaintext;
      k=0;
     for(int i=0;i<row;i++){
        for(int j=0;j<col && k<l ;j++){
           // mat[i][j]=str[k++];
            cout<<mat[i][j]<<" ";
            plaintext+=mat[i][j];
        }
        cout<<endl;
    }
    plaintext.resize(l);
    cout<<"\nPlaintext : "<<plaintext<<endl;
return 0;
}
