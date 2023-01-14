#include<bits/stdc++.h>
using namespace std;
int main(){
string plaintext="Dept of ice!";
int key=3;
char tu;

int n=plaintext.size();

string ciphertext;
for(int i=0;i<n;i++){
      char ch =plaintext[i];
int val1;
//check capital or small letter then subtract a or A
     if(ch>='A' and ch<='Z'){//if capital letter
            val1=(ch-'A'+3)%26;


                tu=char(val1+'A');


         }
     else if (ch>='a' and ch<='z'){//if small letter
            val1=(ch-'a'+3)%26;


                tu=char(val1+'a');


        }
        else{ //otherwise keep as it is
                tu=plaintext[i];

        }



    ciphertext+=tu;
}

cout<<"\nPlaintext :"<<plaintext<<endl;
cout<<"CipherText :"<<ciphertext<<endl;

string decryptedtext;

for(int i=0;i<n;i++){
       char ch =ciphertext[i];
       int val1;
//check capital or small letter then subtract a or A
     if(ch>='A' and ch<='Z'){//if capital letter
        val1=(ch-'A'-3)%26;
        if(val1<0)
        val1+=26;

             tu=char(val1+'A');



     }
     else if(ch>='a' and ch<='z'){//if small letter
            val1=(ch-'a'-3)%26;
                if(val1<0)
                val1+=26;

                 tu=char(val1+'a');


     }
     else{ //otherwise as it is

            tu=ciphertext[i];
     }
    decryptedtext+=tu;

}
cout<<endl;
cout<<"Decrypted Ciphertext: "<<decryptedtext<<endl;


}


