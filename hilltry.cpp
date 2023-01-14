

#include<iostream>
#include<math.h>

using namespace std;



float encrypt[100][100], decrypt[100][100], a[3][3], b[3][3], mes[100][100], c[3][3];

void encryption(); //encrypts the message
void decryption(); //decrypts the message
void getKeyMessage(); //gets key and message from user
void inverse(); //finds inverse of key matrix
void inverse1();
string plaintext,pt;
int row;
///Driver Code

int main() {
getKeyMessage();
encryption();
decryption();
}


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

void getKeyMessage() {
   string key = "gybnqkurp";
	int k = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			a[i][j] = (key[k] - 'a');
			c[i][j]=a[i][j];
			k++;
		}
	}

 plaintext="actyut iop yu";

pt=plaintext;

plaintext=del_sp(plaintext);
key=del_sp(key);



}
///Encryption
void encryption() {
int i, j, k;

if(plaintext.size() % 3 != 0)
        plaintext+='x';
    if(plaintext.size() % 3 != 0)
        plaintext+='x';

row=plaintext.size()/3;
	k=0;
	cout<<"Plaintext matrix :"<<endl;

	for (int i = 0; i < row; i++){
        for(int j=0;j<3;j++){
		mes[i][j] = (plaintext[k] - 'a') ;
        cout<<mes[i][j]<<" ";
        k++;
        }
        cout<<endl;
	};



for(i = 0; i < row; i++){
for(j = 0; j < 3; j++){
        encrypt[i][j]=0;
for(k = 0; k < 3; k++){
encrypt[i][j] = encrypt[i][j] + mes[i][k] * a[k][j];
}
//cout<<encrypt[i][j]<<" ";
}
cout<<endl;
}
string cipherText;
cout<<"\nEncrypted string is: ";
for(i = 0; i <row ; i++){
    for(int j=0;j<3;j++){
        cipherText+= (char)(fmod(encrypt[i][j], 26) + 97);
    }
}
cipherText=add_spc(pt,cipherText);

cout<<"CipherText : "<<cipherText<<endl;


}
///Decryption

void decryption() {
int i, j, k;
inverse1();
for(i = 0; i < row; i++){
for(j = 0; j < 3; j++){
    decrypt[i][j]=0;
for(k = 0; k < 3; k++){
decrypt[i][j] = decrypt[i][j] + encrypt[i][k] * b[k][j];

}
//cout<<decrypt[i][j]<<" ";
}
cout<<endl;
}
string decryptedtext;
cout<<"\nDecrypted string is: ";
for(i = 0; i < row; i++){
    for(int j=0;j<3;j++){
        decryptedtext+=(char)(fmod(decrypt[i][j], 26) + 97);
    }
}

decryptedtext=add_spc(pt,decryptedtext);

cout<<"DecryptedText : "<<decryptedtext<<endl;

}



void inverse1(){
    float d=0;

//finding determinant of the matrix
  for(int i = 0; i < 3; i++)
    d = d + (a[0][i] * (a[1][(i+1)%3] * a[2][(i+2)%3] - a[1][(i+2)%3] * a[2][(i+1)%3]));

 if(d>0)         //Condition to check if the derterminat is zero or not if zero than inverse dont exists
  {
      cout<<"\nInverse of the matrix is: \n";
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
          b[i][j]=((a[(j+1)%3][(i+1)%3] * a[(j+2)%3][(i+2)%3]) - (a[(j+1)%3][(i+2)%3] * a[(j+2)%3][(i+1)%3]))/ d; //finding adjoint and dividing it by determinant

     }
  }
  for(int i = 0; i < 3; i++) {
for(int j = 0; j < 3; j++)
cout<<b[i][j]<<" ";
cout<<"\n";
}

}

