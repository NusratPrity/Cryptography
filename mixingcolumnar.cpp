#include<bits/stdc++.h>
using namespace std;


string plaintext, key ,pt ,ct ;
int age_ache[26] = {0};



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


string dist(){

    string p;

    for(int i = 0; i<key.size(); i++){
        int val = key[i] - 'a';
        if(age_ache[val] == 0){
            age_ache[val] = 1;
            p += key[i];
        }
    }
    return p;
}



string encodeMessage()
{
    string p = dist();
    int col = p.size();
    int row = 26/col;
    if(26 % col) row++;
    //cout << p << '\n';

    char mat[row][col];

    for(int i = 0; i<row; i++)
        for(int j = 0; j<col; j++)
            mat[i][j]='.';
    for(int j = 0; j<col; j++)
        mat[0][j] = p[j];

    char c = 'a';
    for(int i = 1; i<row; i++){
        for(int j = 0; j<col and c<='z'; c++){
            int val = c - 'a';
            if(age_ache[val] == 0){
                mat[i][j++] = c;
                age_ache[val] = 1;
            }
        }
    }
    string encoded;
    for(int j = 0; j < col; j++){
        for(int i = 0; i<row; i++){
            if(mat[i][j] != '.')
                encoded += mat[i][j];
        }
    }
    return encoded;
}

string encryptMessage(string encoded)
{
    string cipher ;
	for(int i = 0; i<plaintext.size(); i++){
        int val = plaintext[i] - 'a';
        cipher += encoded[val];
	}
	cipher=add_spc(pt,cipher);
	return cipher;
}



int main()
{
    plaintext = "far above cayuga swaters";
    pt=plaintext;

    key ="cornell";
    //cin >> plaintext >> sh;

     string plain;
    for(int i=0;i<26;i++)
        plain +=char(i+97);
    cout<<"Plain : "  <<plain<<endl;

    plaintext=del_sp(plaintext);
    key=del_sp(key);

    string encoded = encodeMessage();
    string ciphertext = encryptMessage(encoded);
    cout << "Cipher :"<<encoded << '\n';
    cout << plaintext << '\n';
    cout <<"CipherText :"<< ciphertext << '\n';

///Decryption Process

        ct=ciphertext;

        ciphertext=del_sp(ciphertext);

      string decipher ;
     int  k=0;
	for(int i = 0; i<ciphertext.size(); i++){
         for(k=0;k<26;k++){
        if(ciphertext[i]==encoded[k]){

        decipher += plain[k];
        }

        }
	}

	decipher=add_spc(ct,decipher);

     cout << "Decrypted Plaintext :"<<decipher << '\n';

    return 0;
}



///  Alhamdulillah...

