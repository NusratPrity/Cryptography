#include<bits/stdc++.h>
using namespace std;

string del_sp(string pt){
    string plaintext;
    for(int i = 0; i<pt.size(); i++)
        if(pt[i] != ' ') plaintext += pt[i];
    return plaintext;
}

string add_spc(string pt, string ct){
    string ciphertext;
    for(int i = 0, j = 0; i<pt.size(); i++){
        if(pt[i] == ' ')
            ciphertext += ' ';
        else{
            ciphertext += ct[j];
            j++;
        }
    }
    return ciphertext;
}

int main(){
string plaintext="Dept of ice.";
string key="okey";
string extendedkey;
int n=plaintext.size();
extendedkey=key+plaintext;
extendedkey.resize(n);
string ciphertext;
string pt=plaintext;
plaintext=del_sp(plaintext);
extendedkey=del_sp(extendedkey);

for(int i=0;i<n;i++){
    int shift;
    char tu;
    cout<<extendedkey[i]<<" "<<endl;

        if(extendedkey[i]>='A' and extendedkey[i]<='Z')
            shift=extendedkey[i]-'A';
        else
            shift=extendedkey[i]-'a';
        cout<<"SHift :"<<shift<<endl;

char ch =plaintext[i];
int val1;
//check capital or small letter then subtract a or A
     if(ch>='A' and ch<='Z'){//if capital letter
            val1=(ch-'A'+shift)%26;


                tu=char(val1+'A');


         }
     else if (ch>='a' and ch<='z'){//if small letter
            val1=(ch-'a'+shift)%26;


                tu=char(val1+'a');


        }
        else{ //otherwise keep as it is
                tu=plaintext[i];

        }



    ciphertext+=tu;
}
ciphertext=add_spc(pt,ciphertext);
cout<<"Extended key : "<<extendedkey<<endl;
cout<<"Plaintext :"<<plaintext<<endl;
cout<<"CipherText : "<<ciphertext<<endl;



}

